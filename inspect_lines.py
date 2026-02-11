
try:
    with open('index.html', 'r', encoding='utf-8', errors='ignore') as f:
        lines = f.readlines()

    found_count = 0
    for i, line in enumerate(lines):
        if 'Nombre' in line:
            print(f"Line {i+1}: {line.strip()}")
            # Print surrounding lines to get context
            start = max(0, i - 5)
            end = min(len(lines), i + 20)
            for j in range(start, end):
                print(f"  {j+1}: {lines[j].strip()[:100]}") # Truncate long lines
            
            found_count += 1
            if found_count >= 2: # Just find a couple of instances
                break
    
    if found_count == 0:
        print("'Nombre' NOT FOUND in lines")

except Exception as e:
    print(f"Error: {e}")
