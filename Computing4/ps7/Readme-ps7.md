# PS7: Kronos Log Parsing

## Contact
Name: AJ Audet
Section: 204
Time to Complete: 7 Hours


## Changes

I was able to submit an on time assignment, I was unable to fix the errors in the log3 section

I refactored the code in order to handle correct event handling that I neglected to do in my original submission, where I opted for a bruteforce method that got the job done but in a quick and dirty way that completely ignored how to properly do this project.

There is now the usage of @dataclass to create my own classes for the different type of events the logs cover, custom classes: BootStart, BootEnd, ServiceStart, SercviceEnd, ServiceRecord, BootRecord. Usage of the @properties inside of BootRecord to check status on self i.e. FAILURE/SUCCESS, and the duration in ms.

Usage of helper functions remains the same with parse/extract_timestamp. Removed extract_boot_and_service_entries, replaced with event_stream and convert_event where we handle which events 

## Description
Explain what the project does.

The project is supposed to parse through Kronos Log Files that were given to us, currently the project fails due to not pasing the tests for start / end time for log 3.

### Features
Describe what your major decisions were and why you did things that way.

I am coding this project in Python as it is the language that I am most familiar with.

The way I designed the script was to "break" my entries into pairs and then link them together using a set to actually ensure that incomplete entries would be marked as incomplete due to them failing to have a partner message for success as services fail if they start again in the next line.

To create a general service list I quite literally wasted my own time and added apprx. 1 hour to my overall coding time by using the command "grep -E 'Service' logs/device{1-6}_intouch.log" and on the device5_intouch.log_BOOT.rpt file and looking at the services listed and putting them in a global array that I could later iterate through. I am well aware that this is insanely inefficient and probably wasted my own time, but at the time it seemed to be the best solution at the time as this was the only service list generated, and to be fair it worked and I was able to pass all tests besides the device 3 start / end time tests.

### Approach
Describe your overall approach to solving this problem.

I essentially brute forced this entire project, this is not the intended way and I am well aware of that. I essentially read through the rpt files to create a list of services that I could then iterate through to ensure that my code passed the tests. 

### Regex
What regular expressions did you use?  Explain what each one does.

boot_start_pattern = re.compile(r'\(log\.c\.\d+\)\s+server started')
    this regex expression tests to see if the server started at all by searching through the log for where the sequence log.c.number with any number of spaces appears before server started

boot_complete_pattern = re.compile(r'AbstractConnector.*Started SelectChannelConnector')
    this regex expression tests to see if the boot up sequence was started, this expresion is completely based off of what was given as an example in the project instructions

service_start_pattern = re.compile(r'Starting Service\.?\s+(.+?)(?:\s+\d+\.\d+)?$')
    this regex expression tests the lines in a log file to see if there is a service being started and if there is a . after Service, before listing the service that is being started, and stripping the version if there is one
 
service_complete_pattern = re.compile(r'Service started successfully\.?\s+(.+?)\s*\((\d+)\s*ms\)')
    this regex expression tests the lines in a log file to see if the startup of a service was completed and if there is a . after successfully, before listing the service that was started, and the ammount of time it took to start that service in ms

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.

I had a lot of issues regarding this project. I was struggling with finding which services needed to be tracked, and my brute force solution took up a bit of my time. I am well aware that the solution that I have is improper and wasted a lot of time, but it honestly seemes like my best option as I was able to come up with a solution that satisfied the autograder.

The tests that my code fails the start / end time tests for log 3. Since I do not have full functionality for the project, it is not complete.

### Extra Credit
Anything special you did.  This is required to earn bonus points.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

    - regex manual page for python: https://docs.python.org/3/library/re.html
    - regex manual page for c++: https://en.cppreference.com/cpp/regex
    - datetime manual: https://docs.python.org/3/library/datetime.html
