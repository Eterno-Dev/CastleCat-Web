
try:
    with open('index.html', 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()

    print("Searching for 'Nombre'...")
    idx = content.find('Nombre')
    if idx != -1:
        start = max(0, idx - 500)
        end = min(len(content), idx + 500)
        print("--- CONTEXT AROUND NOMBRE ---")
        print(content[start:end])
    else:
        print("'Nombre' NOT FOUND")
    
    # Check for encoded version
    print("\nSearching for 'Escorp'")
    idx2 = content.find('Escorp')
    if idx2 != -1:
        start = max(0, idx2 - 500)
        end = min(len(content), idx2 + 500)
        print("--- CONTEXT AROUND ESCORP ---")
        print(content[start:end])
    else:
        print("'Escorp' NOT FOUND")

except Exception as e:
    print(f"Error: {e}")
