
import re

try:
    with open('index.html', 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    print("Scanning for IDs and Classes related to Enemigos/Jefes...")
    
    # Flexible quote matching
    # Find IDs
    ids = re.findall(r'id=["\']([^"\']+)["\']', content)
    interesting_ids = [i for i in ids if 'enem' in i.lower() or 'jef' in i.lower()]
    print(f"Interesting IDs found: {interesting_ids[:20]}")

    # Find data-values
    dvs = re.findall(r'data-value=["\']([^"\']+)["\']', content)
    print(f"Data-values found: {dvs[:20]}")
    
    # Check for 'Nombre' context again but print surrounding TAGS not just lines
    # This is hard with regex on raw html but let's try finding the container of "Escorpión"
    # We look for <div ... > ... Escorpión ... </div>
    # Too complex for simple regex.
    
except Exception as e:
    print(f"Error: {e}")
