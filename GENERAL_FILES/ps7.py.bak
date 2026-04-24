# Copyright April 22 2026 AJ Audet
# ps7.py

import re
import sys
from datetime import datetime
import os

SERVICES = [
    'Logging', 'DatabaseInitialize', 'MessagingService', 'HealthMonitorService',
    'Persistence', 'ConfigurationService', 'LandingPadService', 'PortConfigurationService',
    'CacheService', 'ThemingService', 'StagingService', 'DeviceIOService',
    'BellService', 'GateService', 'ReaderDataService', 'BiometricService',
    'StateManager', 'OfflineSmartviewService', 'AVFeedbackService', 'DatabaseThreads',
    'SoftLoadService', 'WATCHDOG', 'ProtocolService', 'DiagnosticsService'
]

'''
    Parse timestamp and return datetime object
    @param timestamp string
    @return formatted datetime object
'''
def parse_timestamp(time_str):
    if not time_str:
        return None
    try:
        time_str = time_str.replace(',', '.')
        return datetime.strptime(time_str, "%Y-%m-%d %H:%M:%S.%f")
    except ValueError:
        try:
            return datetime.strptime(time_str.split('.')[0], "%Y-%m-%d %H:%M:%S")
        except ValueError:
            return None

'''
    Extract and parse timestamp from a line
    @param line to parse
'''
def extract_timestamp_from_line(line):
    match = re.search(r'(\d{4}-\d{2}-\d{2}\s+\d{2}:\d{2}:\d{2}(?:\.\d+)?)', line)
    if match:
        return parse_timestamp(match.group(1))
    return None

'''
    Extract boot and service events with proper context
    @param current line in the log file
    @return boot start / complete entries
'''
def extract_boot_and_service_entries(log_content):
    lines = log_content.split('\n')
    
    boot_starts = []
    boot_completes = []
    service_entries = []

    boot_start_pattern = re.compile(r'\(log\.c\.\d+\)\s+server started')
    boot_complete_pattern = re.compile(r'AbstractConnector.*Started SelectChannelConnector')
    service_start_pattern = re.compile(r'Starting Service\.?\s+(.+?)(?:\s+\d+\.\d+)?$')
    service_complete_pattern = re.compile(r'Service started successfully\.?\s+(.+?)\s*\((\d+)\s*ms\)')
    
    last_timestamp = None
    
    for line_num, line in enumerate(lines, 1):
        current_timestamp = extract_timestamp_from_line(line)
        if current_timestamp:
            last_timestamp = current_timestamp
        else:
            current_timestamp = last_timestamp

        if boot_start_pattern.search(line) and current_timestamp:
            boot_starts.append((line_num, current_timestamp))
        elif boot_complete_pattern.search(line) and current_timestamp:
            boot_completes.append((line_num, current_timestamp))

        match = service_start_pattern.search(line)
        if match and current_timestamp:
            service_name = match.group(1).strip()
            service_entries.append((line_num, current_timestamp, 'START', service_name))

        match = service_complete_pattern.search(line)
        if match and current_timestamp:
            service_name = match.group(1).strip()
            elapsed_ms = int(match.group(2))
            service_entries.append((line_num, current_timestamp, 'COMPLETE', service_name, elapsed_ms))

    return boot_starts, boot_completes, service_entries

'''
    Match boot events and associated services by matching them in sets
    @param boot start / completed entries
    @return 
'''
def match_boots_to_services(boot_starts, boot_completes, service_entries):
    boots = []
    used_starts = set()
    used_completes = set()

    for start_idx, (start_line, start_time) in enumerate(boot_starts):
        best_complete = None
        best_idx = None

        for complete_idx, (complete_line, complete_time) in enumerate(boot_completes):
            if complete_idx not in used_completes and complete_time >= start_time:
                if best_complete is None or complete_time < best_complete[1]:
                    best_complete = (complete_line, complete_time)
                    best_idx = complete_idx

        if best_complete:
            used_completes.add(best_idx)
            boot = {
                'start_line': start_line,
                'start_time': start_time,
                'end_line': best_complete[0],
                'end_time': best_complete[1],
                'status': 'SUCCESS',
                'duration': (best_complete[1] - start_time).total_seconds(),
                'services': {}
            }

            for entry in service_entries:
                if len(entry) == 5:
                    line_num, ts, event_type, service_name, elapsed_ms = entry
                    if start_line <= line_num <= best_complete[0] and ts >= start_time and ts <= best_complete[1]:
                        if service_name not in boot['services']:
                            for entry2 in service_entries:
                                if len(entry2) == 4 and entry2[3] == service_name and entry2[1] <= ts:
                                    if entry2[0] >= start_line:
                                        boot['services'][service_name] = {
                                            'start_line': entry2[0],
                                            'end_line': line_num,
                                            'elapsed_ms': elapsed_ms
                                        }
                                        break
            boots.append(boot)
            used_starts.add(start_idx)

    for start_idx, (start_line, start_time) in enumerate(boot_starts):
        if start_idx not in used_starts:
            boots.append({
                'start_line': start_line,
                'start_time': start_time,
                'end_line': None,
                'end_time': None,
                'status': 'FAILED',
                'duration': None,
                'services': {}
            })

    return boots

'''
    Generate device boot report from a given log file and its boots
    @param log_file to generate report from
    @param boots succeded / failed in log
    @return completed report
'''
def generate_report(log_file, boots):
    report_lines = []

    report_lines.append("Device Boot Report")
    report_lines.append("")
    report_lines.append(f"InTouch log file: {os.path.basename(log_file)}")

    with open(log_file, 'r', encoding='utf-8', errors='ignore') as f:
        total_lines = len(f.readlines())
    report_lines.append(f"Lines Scanned: {total_lines}")
    report_lines.append("")

    successful_boots = sum(1 for b in boots if b['status'] == 'SUCCESS')
    failed_boots = sum(1 for b in boots if b['status'] == 'FAILED')
    total_boots = successful_boots + failed_boots

    report_lines.append(f"Device boot count: initiated = {total_boots}, completed: {successful_boots}")
    report_lines.append("")
    report_lines.append("")

    for boot in boots:
        report_lines.append("=== Device boot ===")

        start_line = boot['start_line']
        start_time = boot['start_time']
        end_line = boot['end_line']
        end_time = boot['end_time']
        status = boot['status']
        duration = boot['duration']
        services = boot['services']

        basename = os.path.basename(log_file)

        if status == 'SUCCESS':
            report_lines.append(f"{start_line}({basename}): {start_time.strftime('%Y-%m-%d %H:%M:%S')} Boot Start")
            report_lines.append(f"{end_line}({basename}): {end_time.strftime('%Y-%m-%d %H:%M:%S')} Boot Completed")
            report_lines.append("")
            report_lines.append(f"\tBoot Time: {int(duration * 1000)}ms ")
            report_lines.append("")
        else:
            report_lines.append(f"{start_line}({basename}): {start_time.strftime('%Y-%m-%d %H:%M:%S')} Boot Start")
            report_lines.append("**** Incomplete boot **** ")
            report_lines.append("")

        report_lines.append("Services")
        failed_services = []

        for service_name in SERVICES:
            report_lines.append(f"\t{service_name}")

            if service_name in services:
                service_info = services[service_name]
                report_lines.append(f"\t\t Start: {service_info['start_line']}({basename})")
                report_lines.append(f"\t\t Completed: {service_info['end_line']}({basename})")
                report_lines.append(f"\t\t Elapsed Time: {service_info['elapsed_ms']} ms")
            else:
                report_lines.append(f"\t\t Start: Not started({basename})")
                report_lines.append(f"\t\t Completed: Not completed({basename})")
                report_lines.append(f"\t\t Elapsed Time: ")
                failed_services.append(service_name)

        if failed_services:
            report_lines.append("")
            report_lines.append(f"\t*** Services not successfully started: {', '.join(failed_services)}")

        report_lines.append("")
    return "\n".join(report_lines)
 
def main():
    if len(sys.argv) != 2:
        print("Usage: ps7.py <log_file>", file=sys.stderr)
        sys.exit(1)

    log_file = sys.argv[1]
    output_file = f"{log_file}.rpt"

    try:
        with open(log_file, 'r', encoding='utf-8', errors='ignore') as f:
            log_content = f.read()
    except FileNotFoundError:
        print(f"Error: Log file '{log_file}' not found", file=sys.stderr)
        sys.exit(1)
    except Exception as e:
        print(f"Error reading log file: {e}", file=sys.stderr)
        sys.exit(1)

    boot_starts, boot_completes, service_entries = extract_boot_and_service_entries(log_content)
    boots = match_boots_to_services(boot_starts, boot_completes, service_entries)
    report = generate_report(log_file, boots)

    try:
        output_dir = os.path.dirname(output_file)
        if output_dir and not os.path.exists(output_dir):
            os.makedirs(output_dir)
        with open(output_file, 'w', encoding='utf-8') as f:
            f.write(report)
        sys.exit(0)
    except (OSError, PermissionError):
        try:
            basename = os.path.basename(log_file)
            output_file = f"{basename}.rpt"
            with open(output_file, 'w', encoding='utf-8') as f:
                f.write(report)
            sys.exit(0)
        except Exception as e:
            print(f"Error writing report: {e}", file=sys.stderr)
            sys.exit(1)
 
if __name__ == '__main__':
    main()