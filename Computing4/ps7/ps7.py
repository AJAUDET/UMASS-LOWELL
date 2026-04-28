# Copyright April 22 2026 AJ Audet
# ps7.py

import re
import sys
import os
from datetime import datetime
from dataclasses import dataclass, field
from typing import Optional, List, Dict, Iterator

'''
    Regex Storage
    Keep track of the events we want to parse through, saved as global variables to keep my sanity
'''
TIMESTAMP = re.compile(
    r'(\d{4}-\d{2}-\d{2}\s+\d{2}:\d{2}:\d{2}(?:[.,]\d+)?)'
)
BOOT_START = re.compile(r'\(log\.c\.\d+\)\s+server started')
BOOT_END = re.compile(r'AbstractConnector.*Started SelectChannelConnector')
SERVICE_START = re.compile(r'Starting Service\.?\s+(.+?)(?:\s+\d+\.\d+)?$')
SERVICE_END = re.compile(r'Service started successfully\.?\s+(.+?)\s*\((\d+)\s*ms\)')

'''
    Event Monitoring

    We use dataclasses to track the types of events we wish to check for in our program
    Each event we have to check has a line where we will use our REGEX variables to check if the conditions for the events are met
'''
@dataclass
class Event:
    line: int
    timestamp: Optional[datetime]

@dataclass
class BootStart(Event):
    pass

@dataclass
class BootEnd(Event):
    pass

@dataclass
class ServiceStart(Event):
    name: str

@dataclass
class ServiceEnd(Event):
    name: str
    duration_ms: int

'''
    Type Storage
    We use dataclasses to sort through the events we have found from the logs, and then record them
'''
@dataclass
class ServiceRecord:
    name: str
    start_line: Optional[int] = None
    end_line: Optional[int] = None
    elapsed_ms: Optional[int] = None

@dataclass
class BootRecord:
    start_line: int
    start_time: datetime
    end_line: Optional[int] = None
    end_time: Optional[datetime] = None
    services: Dict[str, ServiceRecord] = field(default_factory=dict)

    @property
    def status(self):
        return "SUCCESS" if self.end_time else "FAILED"

    @property
    def duration_ms(self):
        if self.end_time:
            return int((self.end_time - self.start_time).total_seconds() * 1000)
        return None

'''
    Parsing Functions
    parse_timestamp: parse through raw input and find the timestamp, check the format and return a datetime object if the format is correct, otherwise None
    extract_timestamp: extract a timestamp from a line, return a datetime object if the format is correct, otherwise None
    event_stream: generate an event stream from the log file, yielding events as they are found, return an iterator of events
'''

def parse_timestamp(raw: str) -> Optional[datetime]:
    if not raw:
        return None
    raw = raw.replace(',', '.')
    for fmt in ("%Y-%m-%d %H:%M:%S.%f", "%Y-%m-%d %H:%M:%S"):
        try:
            return datetime.strptime(raw, fmt);
        except ValueError:
            pass
    return None

def extract_timestamp(line: str) -> Optional[datetime]:
    timestamp = TIMESTAMP.search(line)
    return parse_timestamp(timestamp.group(1)) if timestamp else None

def fmt_time(dt: datetime) -> str:
    return dt.strftime("%Y-%m-%d %H:%M:%S")

def event_stream(lines: List[str]) -> Iterator[Event]:
    last_time = None

    for line_num, line in enumerate(lines, start=1):
        curr_time = extract_timestamp(line)
        if curr_time is None:
            curr_time = last_time
        else:
            last_time = curr_time

        if BOOT_START.search(line):
            if curr_time is None:
                continue
            yield BootStart(line_num, curr_time)
        elif BOOT_END.search(line):
            yield BootEnd(line_num, curr_time)
        
        m = SERVICE_START.search(line)
        if m:
            ts = curr_time
            if ts is None:
                continue
            yield ServiceStart(line_num, ts, m.group(1).strip())
        m = SERVICE_END.search(line)
        if m:
            ts = curr_time
            if ts is None:
                continue
            yield ServiceEnd(line_num, ts, m.group(1).strip(), int(m.group(2)))

'''
    Event Handling
    convert_event: convert events into a usable list we can read through for the report
'''
def convert_event(events: Iterator[Event]) -> List[BootRecord]:
    boots = []
    current_boot = None

    for event in events:
        if isinstance(event, BootStart):
            if event.timestamp is None:
                continue
            if current_boot is not None:
                boots.append(current_boot)

            current_boot = BootRecord(
                start_line=event.line,
                start_time=event.timestamp
            )
        elif isinstance(event, BootEnd):
            if current_boot is None:
                continue
            if event.timestamp is None:
                continue
            current_boot.end_line = event.line
            current_boot.end_time = event.timestamp
            boots.append(current_boot)
            current_boot = None
        elif current_boot:
            if isinstance(event, ServiceStart):
                svc = current_boot.services.setdefault(
                    event.name,
                    ServiceRecord(name=event.name)
                )
                svc.start_line = event.line
            elif isinstance(event, ServiceEnd):
                svc = current_boot.services.setdefault(
                    event.name,
                    ServiceRecord(name=event.name)
                )
                svc.end_line = event.line
                svc.elapsed_ms = event.duration_ms

    if current_boot and current_boot.end_time is None:
        boots.append(current_boot)
    return boots

'''
    Report Generation
    generate_report: generate a report from the list of BootRecords, printing out the details of each boot and its services
'''
def generate_report(log_file: str, boots: List[BootRecord]) -> str:
    basename = os.path.basename(log_file)
    with open(log_file, "r", encoding="utf-8", errors="ignore") as f:
        total_lines = sum(1 for _ in f)

    success = sum(1 for b in boots if b.status == "SUCCESS")
    out = [
        "Device Boot Report",
        "",
        f"InTouch log file: {basename}",
        f"Lines Scanned: {total_lines}",
        "",
        f"Device boot count: initiated = {len(boots)}, completed: {success}",
        "",
    ]

    for boot in boots:
        out.append("=== Device boot ===")
        out.append(
            f"{boot.start_line}({basename}): "
            f"{fmt_time(boot.start_time)} Boot Start"
        )

        if boot.status == "SUCCESS":
            out.append(
                f"{boot.end_line}({basename}): "
                f"{fmt_time(boot.end_time)} Boot Completed"
            )
            out.append(f"\tBoot Time: {boot.duration_ms}ms")
        else:
            out.append("**** Incomplete boot ****")

        out.append("")
        out.append("Services")
        for name in sorted(boot.services):
            s = boot.services[name]
            out.append(f"\t{name}")
            out.append(f"\t\tStart: {s.start_line}")
            out.append(f"\t\tCompleted: {s.end_line}")
            out.append(f"\t\tElapsed Time: {s.elapsed_ms} ms")
        out.append("")
    return "\n".join(out)

'''
    IO Handling
    read_file: read a file and return its lines as a list of strings
    write_file: write a string to a file, with error handling to write to a fallback
'''
def read_file(path: str) -> List[str]:
    with open(path, "r", encoding="utf-8", errors="ignore") as f:
        return f.readlines()

def write_file(path: str, content: str):
    try:
        directory = os.path.dirname(path)
        if directory:
            os.makedirs(directory, exist_ok=True)
        with open(path, "w", encoding="utf-8") as f:
            f.write(content)
    except Exception:
        try:
            with open(path, "w", encoding="utf-8") as f:
                f.write(content)
        except Exception as e:
            print(f"Fatal write error: {e}", file=sys.stderr)
            sys.exit(1)

def main():
    if len(sys.argv) != 2:
        print("Usage: ps7.py <log_file>", file=sys.stderr)
        sys.exit(1)

    log_file = sys.argv[1]
    lines = read_file(log_file)
    events = event_stream(lines)
    boots =  convert_event(events)
    report = generate_report(log_file, boots)
    write_file(f"{log_file}.rpt", report)
    sys.exit(0)

if __name__ == "__main__":
    main()