
import re

try:
    with open('index.html', 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    # Find all data-value="..."
    matches = re.findall(r'data-value="([^"]+)"', content)
    
    print("Found data-values:")
    for m in set(matches): # unique
        print(f" - {m}")

except Exception as e:
    print(f"Error: {e}")
