def is_safe(report):
    levels = list(map(int, report.split()))
    diffs = [levels[i + 1] - levels[i] for i in range(len(levels) - 1)]
    
    if all(1 <= diff <= 3 for diff in diffs):  
        return True
    elif all(-3 <= diff <= -1 for diff in diffs): 
        return True
    return False

def is_safe_with_removal(levels):
    for i in range(len(levels)):
        modified_report = levels[:i]+levels[i+1:]
        if is_safe(" ".join(map(str, modified_report))):
            return True
        
    return False

def count_safe_reports(file_path):
    with open(file_path, 'r') as file:
        reports = file.readlines()
    safe_count = 0
    for report in reports:
        levels = list(map(int, report.strip().split()))
        if is_safe(report.strip()) or is_safe_with_removal(levels):
            safe_count += 1
    return safe_count

file_path = "input.txt" 
safe_reports = count_safe_reports(file_path)
print(f"Number of safe reports: {safe_reports}")
