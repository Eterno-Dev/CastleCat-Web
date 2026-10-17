@echo off
setlocal

echo ========================================================
echo   Compilando CastleCat en WebAssembly (Emscripten)
echo ========================================================
echo/

if exist "C:\Users\paucr\emsdk\upstream\emscripten\emcc.exe" (
    set "EMCC_CMD=C:\Users\paucr\emsdk\upstream\emscripten\emcc.exe"
    goto :found_emcc
)

where emcc >nul 2>nul
if %errorlevel% equ 0 (
    set "EMCC_CMD=emcc"
    goto :found_emcc
)

echo [ERROR] No se ha encontrado el compilador de Emscripten (emcc).
echo Asegurate de que emsdk este instalado en C:\Users\paucr\emsdk
pause
exit /b 1

:found_emcc
if not exist "game" mkdir "game"

echo [*] Compilando src\Main.c a game\index.html ...
call "%EMCC_CMD%" src\Main.c -o game\index.html -s ASYNCIFY -s "EXPORTED_RUNTIME_METHODS=['ccall','cwrap']" --shell-file web\shell.html
if %errorlevel% neq 0 (
    echo/
    echo [ERROR] La compilacion con emcc ha fallado. Revisa el codigo en C.
    pause
    exit /b 1
)

echo/
echo [OK] Compilacion Exitosa: game\index.html, game\index.js, game\index.wasm generados.
echo/
echo ========================================================
echo   Aplicando Parches de Sistema (game\index.js)
echo ========================================================
echo/

node web\parche_emscripten.js game\index.js

echo/
echo ========================================================
echo   PROCESO TERMINADO CON EXITO
echo ========================================================
echo Para jugar en tu navegador inicia un servidor local y abre:
echo   http://localhost:8080/game/
echo.
echo Servidor sugerido:
echo   python -m http.server 8080
echo   o
echo   npx serve
echo/
pause
