#include <stdio.h>
#include <string.h>

#ifdef __EMSCRIPTEN__
    #include <emscripten.h>
    #include <emscripten/html5.h>
    #include <ctype.h>
#endif

int getch(void); 

// Global variables for menu/pause and game state
volatile int g_solicitarMenu = 0;
volatile int g_hayPartida = 0;

// Estadísticas de la partida actual para puntuación
volatile int g_enemigosDerrotados = 0;
volatile int g_tesorosAbiertos = 0;

void reproducirSonido(const char* tipo) {
#ifdef __EMSCRIPTEN__
    EM_ASM({
        if (typeof window.playSound === 'function') {
            window.playSound(UTF8ToString($0));
        }
    }, tipo);
#endif
}

void temblorPantalla(void) {
#ifdef __EMSCRIPTEN__
    EM_ASM({
        if (typeof window.screenShake === 'function') {
            window.screenShake(false);
        }
    });
#endif
}

void temblorPantallaMuerte(void) {
#ifdef __EMSCRIPTEN__
    EM_ASM({
        if (typeof window.screenShake === 'function') {
            window.screenShake(true);
        }
    });
#endif
}

void setModoNarrativa(int activo) {
#ifdef __EMSCRIPTEN__
    EM_ASM({
        if (typeof window !== 'undefined') {
            window.canSkipNarrative = ($0 === 1);
            if ($0 === 1) {
                window.skipNarrative = false;
                if (typeof setTabMode === 'function') setTabMode('skip');
            } else {
                window.skipNarrative = false;
                if (typeof setTabMode === 'function') setTabMode(window.inGameplay ? 'menu' : 'hidden');
            }
        }
    }, activo);
#endif
}

void setModoJuego(int activo) {
#ifdef __EMSCRIPTEN__
    EM_ASM({
        if (typeof window !== 'undefined') {
            window.inGameplay = ($0 === 1);
            if (typeof setTabMode === 'function' && !window.canSkipNarrative) {
                setTabMode($0 === 1 ? 'menu' : 'hidden');
            }
        }
    }, activo);
#endif
}

#ifdef __EMSCRIPTEN__
    // Global variable to store the last key pressed
    volatile int last_key = 0;

EMSCRIPTEN_KEEPALIVE
void triggerMenuTab(void) {
    g_solicitarMenu = 1;
    last_key = 9;
}

    // Callback function for keydown events
    EM_BOOL key_callback(int eventType, const EmscriptenKeyboardEvent *e, void *userData) {
        // Map keys to their ASCII codes or custom codes
        if (strcmp(e->key, "Enter") == 0) {
            last_key = 13; // Enter
        } else if (strcmp(e->key, "Backspace") == 0) {
            last_key = 8; // Backspace
        } else if (strcmp(e->key, "Tab") == 0) {
            last_key = 9; // Tab
            EM_ASM({
                if (typeof window !== 'undefined' && window.canSkipNarrative) {
                    window.skipNarrative = true;
                }
            });
        } else if (strcmp(e->key, "Escape") == 0) {
            last_key = 27; // Escape
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
            #ifdef __EMSCRIPTEN__
            int sliderChanged = EM_ASM_INT({
                if (typeof window !== 'undefined' && window.inOptionsMenu && window.volumeSliderChanged) {
                    window.volumeSliderChanged = false;
                    return 1;
                }
                return 0;
            });
            if (sliderChanged) {
                return 999;
            }
            #endif
            emscripten_sleep(10);
        }
        int key = last_key;
        last_key = 0; // Reset for next call
        return key;
    }

    // Function to wait specifically for Enter
    void waitForEnter() {
       int key = 0;
       #ifdef __EMSCRIPTEN__
       int skip = EM_ASM_INT({
           return (typeof window !== 'undefined' && window.skipNarrative) ? 1 : 0;
       });
       if (skip) {
           reproducirSonido("confirm");
           last_key = 0;
           return;
       }
       #endif
       do {
           key = getch();
           #ifdef __EMSCRIPTEN__
           int skipNow = EM_ASM_INT({
               return (typeof window !== 'undefined' && window.skipNarrative) ? 1 : 0;
           });
           if (skipNow || key == 9) { // TAB o click en botón saltar
               break;
           }
           #endif
       } while (key != 13 && key != 10);
       reproducirSonido("confirm");
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
    int skipInit = EM_ASM_INT({
        return (typeof window !== 'undefined' && window.skipNarrative) ? 1 : 0;
    });
    if (skipInit) {
        printf("%s", dialog);
        fflush(stdout);
        return;
    }

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
        
        int skip = EM_ASM_INT({
            return (typeof window !== 'undefined' && window.skipNarrative) ? 1 : 0;
        });

        if (skip) {
            i += char_len;
            while (dialog[i] != '\0' && b_idx < 4094) {
                buffer[b_idx++] = dialog[i++];
            }
            buffer[b_idx] = '\0';
            EM_ASM({
                var text = UTF8ToString($0);
                if (window.typeWriterNode) {
                    window.typeWriterNode.innerHTML = window.parseAnsi ? window.parseAnsi(text) : text;
                    var c = document.getElementById('console');
                    c.scrollTop = c.scrollHeight;
                }
            }, buffer);
            break;
        }

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
    printP("\n\033[1mPresiona \033[40mENTER\033[0;1;37m Para Entrar a la Sala... \033[0m\n");
    fflush(stdout);
    waitForEnter();
    
    limpiarPantalla();
}

/* ========================================================
   SISTEMA DE PUNTUACIÓN Y SALÓN DE LA FAMA (RÉCORDS)
   ======================================================== */

#define MAX_RECORDS 5

typedef struct {
    char nombre[24];
    int clase;
    int planta;
    int puntuacion;
} TRecord;

static TRecord g_records[MAX_RECORDS];
static int g_numRecords = 0;
static int g_recordsCargados = 0;

int calcularPuntuacion(int planta, int hpRestante) {
    int puntos = (planta * 1000) + (g_enemigosDerrotados * 250) + (g_tesorosAbiertos * 150) + (hpRestante * 50);
    if (puntos < 0) puntos = 0;
    return puntos;
}

void cargarRecords(void) {
    if (g_recordsCargados) return;
    g_numRecords = 0;
#ifdef __EMSCRIPTEN__
    EM_ASM({
        try {
            var raw = localStorage.getItem('castlecat_records');
            if (raw) {
                var arr = JSON.parse(raw);
                if (Array.isArray(arr)) {
                    // Limpiar datos de prueba anteriores si existen
                    var esDummy = arr.some(function(r) {
                        return (r.nombre === 'Michi' && r.puntuacion === 6200) ||
                               (r.nombre === 'Garfield' && r.puntuacion === 1100);
                    });
                    if (esDummy) {
                        localStorage.removeItem('castlecat_records');
                        arr = [];
                    }
                    var count = Math.min(arr.length, 5);
                    setValue($1, count, 'i32');
                    for (var i = 0; i < count; i++) {
                        stringToUTF8(arr[i].nombre || "", $0 + i * 36, 24);
                        setValue($0 + i * 36 + 24, arr[i].clase || 0, 'i32');
                        setValue($0 + i * 36 + 28, arr[i].planta || 1, 'i32');
                        setValue($0 + i * 36 + 32, arr[i].puntuacion || 0, 'i32');
                    }
                }
            } else {
                setValue($1, 0, 'i32');
            }
        } catch(e) {
            setValue($1, 0, 'i32');
        }
    }, g_records, &g_numRecords);
#else
    FILE *f = fopen("records.dat", "rb");
    if (f) {
        if (fread(&g_numRecords, sizeof(int), 1, f) == 1) {
            if (g_numRecords > MAX_RECORDS) g_numRecords = MAX_RECORDS;
            if (g_numRecords > 0) {
                fread(g_records, sizeof(TRecord), g_numRecords, f);
            }
        } else {
            g_numRecords = 0;
        }
        fclose(f);
    }
#endif
    g_recordsCargados = 1;
}

void guardarRecords(void) {
#ifdef __EMSCRIPTEN__
    EM_ASM({
        try {
            var arr = [];
            var count = $1;
            for (var i = 0; i < count; i++) {
                var ptr = $0 + i * 36;
                var nom = UTF8ToString(ptr);
                var cla = getValue(ptr + 24, 'i32');
                var pla = getValue(ptr + 28, 'i32');
                var pts = getValue(ptr + 32, 'i32');
                arr.push({ nombre: nom, clase: cla, planta: pla, puntuacion: pts });
            }
            localStorage.setItem('castlecat_records', JSON.stringify(arr));
        } catch(e) {}
    }, g_records, g_numRecords);
#else
    FILE *f = fopen("records.dat", "wb");
    if (f) {
        fwrite(&g_numRecords, sizeof(int), 1, f);
        if (g_numRecords > 0) {
            fwrite(g_records, sizeof(TRecord), g_numRecords, f);
        }
        fclose(f);
    }
#endif
}

int comprobarYGuardarRecord(const char* nombre, int clase, int planta, int puntuacion) {
    cargarRecords();
    if (puntuacion <= 0) return 0;

    int pos = -1;
    if (g_numRecords < MAX_RECORDS) {
        pos = g_numRecords;
        for (int i = 0; i < g_numRecords; i++) {
            if (puntuacion > g_records[i].puntuacion) {
                pos = i;
                break;
            }
        }
        for (int j = g_numRecords; j > pos; j--) {
            g_records[j] = g_records[j - 1];
        }
        g_numRecords++;
    } else {
        for (int i = 0; i < MAX_RECORDS; i++) {
            if (puntuacion > g_records[i].puntuacion) {
                pos = i;
                break;
            }
        }
        if (pos != -1) {
            for (int j = MAX_RECORDS - 1; j > pos; j--) {
                g_records[j] = g_records[j - 1];
            }
        }
    }

    if (pos != -1) {
        strncpy(g_records[pos].nombre, nombre, 23);
        g_records[pos].nombre[23] = '\0';
        g_records[pos].clase = clase;
        g_records[pos].planta = planta;
        g_records[pos].puntuacion = puntuacion;
        guardarRecords();
        return pos + 1; // Posición obtenida (1..5)
    }
    return 0; // No entra en el Top 5
}

void mostrarRecords(void) {
    cargarRecords();
    limpiarPantalla();
    printf("\033[1;33m╔═══════════════════════════════════════════════════╗\n");
    printf("║             SALON DE LA FAMA - RECORDS            ║\n");
    printf("╚═══════════════════════════════════════════════════╝\033[0m\n\n");

    if (g_numRecords <= 0) {
        printf("─────────────────────────────────────────────────────\n");
        printf("          \033[1;37mNO HAY PUNTUACIONES REGISTRADAS\033[0m\n");
        printf("       ¡Juega una partida para dejar tu marca!\n");
        printf("─────────────────────────────────────────────────────\n");
    } else {
        printf("\033[1mPOS   NOMBRE              CLASE        PLANTA     PUNTOS\033[0m\n");
        printf("─────────────────────────────────────────────────────\n");
        const char* clasesStr[] = {"Guerrero", "Mago", "Asesino"};
        for (int i = 0; i < g_numRecords; i++) {
            const char* cNom = (g_records[i].clase >= 0 && g_records[i].clase < 3) ? clasesStr[g_records[i].clase] : "Gato";
            if (i == 0) {
                printf("\033[1;33m#1\033[0m    %-19s %-12s P.%-4d \033[1;32m%7d\033[0m\n", g_records[i].nombre, cNom, g_records[i].planta, g_records[i].puntuacion);
            } else if (i == 1) {
                printf("\033[1;37m#2\033[0m    %-19s %-12s P.%-4d \033[1;32m%7d\033[0m\n", g_records[i].nombre, cNom, g_records[i].planta, g_records[i].puntuacion);
            } else if (i == 2) {
                printf("\033[1;31m#3\033[0m    %-19s %-12s P.%-4d \033[1;32m%7d\033[0m\n", g_records[i].nombre, cNom, g_records[i].planta, g_records[i].puntuacion);
            } else {
                printf("\033[0;2m#%d\033[0m    %-19s %-12s P.%-4d \033[1;32m%7d\033[0m\n", i + 1, g_records[i].nombre, cNom, g_records[i].planta, g_records[i].puntuacion);
            }
        }
        printf("─────────────────────────────────────────────────────\n");
    }
    enterContinuar();
}


