#include <stdio.h>

int getch(void); 

#ifdef __EMSCRIPTEN__
    #include <emscripten.h>
    #include <emscripten/html5.h>
    #include <ctype.h>

    // Global variable to store the last key pressed
    volatile int last_key = 0;

    // Callback function for keydown events
    EM_BOOL key_callback(int eventType, const EmscriptenKeyboardEvent *e, void *userData) {
        // Map keys to their ASCII codes or custom codes
        if (strcmp(e->key, "Enter") == 0) {
            last_key = 13; // Enter
        } else if (strcmp(e->key, "Backspace") == 0) {
            last_key = 8; // Backspace
        } else if (strcmp(e->key, "ArrowUp") == 0) {
            last_key = 'w';
        } else if (strcmp(e->key, "ArrowDown") == 0) {
            last_key = 's';
        } else if (strcmp(e->key, "ArrowLeft") == 0) {
            last_key = 'a';
        } else if (strcmp(e->key, "ArrowRight") == 0) {
            last_key = 'd';
        } else if (strlen(e->key) == 1) {
            last_key = e->key[0];
        }
        return EM_TRUE;
    }

    void init_input() {
        emscripten_set_keydown_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, 0, 1, key_callback);
    }

    int getch(void) {
        last_key = 0;
        while (last_key == 0) {
            emscripten_sleep(10);
        }
        int key = last_key;
        last_key = 0; // Reset for next call
        return key;
    }

    // Function to wait specifically for Enter
    void waitForEnter() {
       int key = 0;
       do {
           key = getch();
       } while (key != 13);
       // Clear any buffered input
       last_key = 0;
    }

    // Function to read a string one character at a time (replaces scanf)
    void inputString(char* buffer, int maxLen, int echo) {
        int i = 0;
        int key;
        while (i < maxLen - 1) {
            key = getch();
            if (key == 13) { // Enter
                break;
            } else if (key == 8 || key == 127) { // Backspace
                if (i > 0) {
                    i--;
                    if (echo) {
                        EM_ASM({
                            var c = document.getElementById('console');
                            if (html.length > 0) {
                                c.innerHTML = html.substring(0, html.length - 1);
                            }
                        });
                    }
                }
            } else if (isprint(key)) {
                buffer[i] = (char)key;
                i++;
                if (echo) {
                     // Append char directly without newline
                    EM_ASM({
                        var c = document.getElementById('console');
                        c.insertAdjacentHTML('beforeend', String.fromCharCode($0));
                        c.scrollTop = c.scrollHeight;
                    }, key);
                }
            }
        }
        buffer[i] = '\0';
        if (echo) {
            printf("\n"); // Normal newline at end
        }
    }

#elif defined(_WIN32)
    #include <conio.h>
    #include <windows.h>
    void init_input() {}
    void waitForEnter() {
         while (getch() != 13);
    }
    void inputString(char* buffer, int maxLen, int echo) {
         if (echo) {
             fgets(buffer, maxLen, stdin);
             buffer[strcspn(buffer, "\n")] = 0;
         } else {
             // Implementation for non-echo if needed, or just use fgets for now
             fgets(buffer, maxLen, stdin);
             buffer[strcspn(buffer, "\n")] = 0;
         }
    }
#else
    int getch(void) {
        return getchar();
    }
    void init_input() {}
    void waitForEnter() {
        while(getchar() != '\n');
    }
    void inputString(char* buffer, int maxLen, int echo) {
         fgets(buffer, maxLen, stdin);
         buffer[strcspn(buffer, "\n")] = 0;
    }
#endif

#ifdef __EMSCRIPTEN__
void typeWriterEffect(const char *dialog, int delay_ms) {
    char buffer[4096] = {0};
    int b_idx = 0;
    int i = 0;
    
    // Preparar el nodo en JS
    EM_ASM( window.typeWriterNode = document.createElement('span'); document.getElementById('console').appendChild(window.typeWriterNode); );
    
    while (dialog[i] != '\0') {
        int char_len = 1;
        
        // ANSI escape code \033[...m
        if (dialog[i] == '\033') {
            while (dialog[i + char_len - 1] != 'm' && dialog[i + char_len] != '\0') {
               char_len++;
            }
        } 
        // UTF-8 char
        else if ((dialog[i] & 0x80) != 0) {
            unsigned char c = dialog[i];
            if ((c & 0xE0) == 0xC0) char_len = 2;
            else if ((c & 0xF0) == 0xE0) char_len = 3;
            else if ((c & 0xF8) == 0xF0) char_len = 4;
        }

        // Add chunk to buffer
        for(int j = 0; j < char_len && dialog[i+j] != '\0'; j++) {
            if (b_idx < 4095) {
                buffer[b_idx++] = dialog[i+j];
            }
        }
        buffer[b_idx] = '\0';
        
        // Update DOM Node
        EM_ASM({
            var text = UTF8ToString($0);
            if (window.typeWriterNode) {
                window.typeWriterNode.innerHTML = window.parseAnsi ? window.parseAnsi(text) : text;
                var c = document.getElementById('console');
                c.scrollTop = c.scrollHeight;
            }
        }, buffer);
        
        // Only sleep if it wasn't an invisible ANSI code
        if (dialog[i] != '\033') {
            emscripten_sleep(delay_ms);
        }
        
        i += char_len;
    }
    
    // Al acabar se anula para la próxima línea
    EM_ASM( window.typeWriterNode = null; );
}
#endif

/* Dibujo Texto Progresivo Rápido*/
void printR(const char *dialog)
{
    #ifdef __EMSCRIPTEN__
    typeWriterEffect(dialog, 8);
    #elif defined(_WIN32)
    int i;
    for (i = 0; dialog[i] != '\0'; i++)
    {
        printf("%c", dialog[i]);
        fflush(stdout);
        Sleep(8);
    }
    #else
    int i;
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 8000000;
    
    for (i = 0; dialog[i] != '\0'; i++)
    {
        printf("%c", dialog[i]);
        fflush(stdout);
        nanosleep(&ts, NULL);
    }
    #endif
}

/* Dibujo Texto Progresivo Lento*/
void printP(const char *dialog)
{
    #ifdef __EMSCRIPTEN__
    typeWriterEffect(dialog, 25);
    #elif defined(_WIN32)
    int i;
    for (i = 0; dialog[i] != '\0'; i++)
    {
        printf("%c", dialog[i]);
        fflush(stdout);
        Sleep(25);
    }
    #else
    int i;
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 25000000;
    
    for (i = 0; dialog[i] != '\0'; i++)
    {
        printf("%c", dialog[i]);
        fflush(stdout);
        nanosleep(&ts, NULL);
    }
    #endif
}

/* Limpiar Pantalla Windows y Linux */
void limpiarPantalla()
{
    // Limpiar la Pantalla
    #ifdef __EMSCRIPTEN__
    fflush(stdout);
    EM_ASM(Module.clearConsole());
    #elif defined(_WIN32)
    system("cls"); // Windows
    #else
    system("clear"); // Unix/Linux
    #endif
}

/* Enter Para Continuar */
void enterContinuar()
{
    printP("\nPulsa \033[40mENTER\033[0;1;37m para continuar.\n");
    fflush(stdout);

    // Esperar un solo Enter
    waitForEnter();

    limpiarPantalla();
}

/* Evento Encontrado */
void evento()
{
    printf("\n\033[1m\033[37m¡EVENTO ENCONTRADO!\033[0m\n");
    printf("\nPulsa \033[40mENTER\033[0;1;37m para resolver el evento.\n");
    fflush(stdout);
    waitForEnter();

    limpiarPantalla();
}

/* Enter Para Pasar Planta */
void pasarDePlanta()
{
    char enter;
    
    printP("\n\033[1mPresiona \033[40mENTER\033[0;1;37m Para Entrar a la Sala... \033[0m\n");
    fflush(stdout);
    waitForEnter();
    
    limpiarPantalla();
}


