
try:
    with open('index.html', 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()

    print("Searching for 'Escorpión'...")
    idx = content.find('Escorpión')
    if idx != -1:
        start = max(0, idx - 500)
        end = min(len(content), idx + 500)
        print("--- CONTEXT AROUND ESCORPIÓN ---")
        print(content[start:end])
    else:
        print("'Escorpión' NOT FOUND")

    print("\nSearching for 'data-value=\"Enemigos\"'...")
    # Escape quotes for python string literal
    idx2 = content.find('data-value="Enemigos"')
    if idx2 != -1:
        start = max(0, idx2 - 500)
        end = min(len(content), idx2 + 500)
        print("--- CONTEXT AROUND DATA-VALUE ---")
        print(content[start:end])
    else:
        print("'data-value=\"Enemigos\"' NOT FOUND")

except Exception as e:
    print(f"Error: {e}")
