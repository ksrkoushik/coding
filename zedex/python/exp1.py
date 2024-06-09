import re

class LogEntry:
    def __init__(self, log_string):
        # Regular expression to extract relevant parts
        pattern = r"#\d\d#\d\d\d\d\d\d\d\d-\d\d\d\d\d\d;\d\d\d#\d\d\d\d\d\d\d\d-\d\d\d\d\d\d;\d\d\d#\d\d\d\d#\d\d#GROUND#Y#-#\.F-WZFS#NSM\d#INFO#bsexport"
        match = re.match(pattern, log_string)
        if match:
            self.syntax_version = match.group(1)
            self.system_time = match.group(2)
            self.system_milliseconds = match.group(3)
            self.adiru_time = match.group(4)
            self.adiru_milliseconds = match.group(5)
            self.sequence_number = match.group(6)
            self.flight_phase = match.group(7)
            self.fws_validity = match.group(8)
            self.flight_number = match.group(9)
            self.aircraft_registration = f"{match.group(10)}.{match.group(11)}"
            self.module = match.group(12)
            self.criticality = match.group(13)
            self.application = match.group(14)
        else:
            print("Pattern didn't match.")
            print("Log string:", log_string)
            print("Pattern:", pattern)
            raise ValueError("Invalid log format")
 
    def __str__(self):
        return f"LogEntry: System Time={self.system_time}, Sequence Number={self.sequence_number}, Module={self.module}"

# Example usage

log_string = "#01#20230716-063938;056#20230716-063938;045#0727#01#GROUND#Y#-#.F-WZFS#NSM1#INFO#bsexport"
log_entry = LogEntry(log_string)
print(log_entry)

