@echo off
setlocal
cd /d "%~dp0"

echo ========================================================
echo   Compilando y Empaquetando CastleCat para Itch.io
echo ========================================================
echo/

:: 1. Detectar emcc
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

:: 2. Crear / limpiar carpeta de empaquetado build_itch
set "DEST_DIR=%~dp0build_itch"
if not exist "%DEST_DIR%" mkdir "%DEST_DIR%"

echo [*] 1/5 Compilando src\Main.c con Emscripten hacia build_itch\index.html ...
call "%EMCC_CMD%" game\src\Main.c -o "%DEST_DIR%\index.html" -s ASYNCIFY -s "EXPORTED_RUNTIME_METHODS=['ccall','cwrap']" --shell-file game\web\shell.html
if %errorlevel% neq 0 (
    echo/
    echo [ERROR] La compilacion con emcc ha fallado. Revisa tu codigo en C.
    pause
    exit /b 1
)

echo [*] 2/5 Aplicando parches de teclado y tiempo real a index.js ...
node game\web\parche_emscripten.js "%DEST_DIR%\index.js"

echo [*] 3/5 Generando terminal.html ...
copy /y "%DEST_DIR%\index.html" "%DEST_DIR%\terminal.html" >nul

echo [*] 4/5 Copiando assets de audio (music.mp3 y SFX/) ...
copy /y "game\assets\music.mp3" "%DEST_DIR%\music.mp3" >nul
if not exist "%DEST_DIR%\SFX" mkdir "%DEST_DIR%\SFX"
xcopy /e /i /y "game\assets\SFX" "%DEST_DIR%\SFX" >nul

echo [*] 5/5 Generando archivo ZIP comprimido para Itch.io ...
powershell -NoProfile -Command "Compress-Archive -Path '%DEST_DIR%\*' -DestinationPath '%~dp0CastleCat_itch.zip' -Force; Copy-Item '%~dp0CastleCat_itch.zip' 'C:\Users\paucr\Desktop\CastleCat_itch.zip' -Force" >nul

echo/
echo ========================================================
echo   PAQUETE LISTO PARA ITCH.IO CON EXITO
echo ========================================================
echo Carpeta descomprimida:
echo   %DEST_DIR%
echo/
echo Archivo ZIP listo para subir a Itch.io:
echo   %~dp0CastleCat_itch.zip
echo   C:\Users\paucr\Desktop\CastleCat_itch.zip
echo/
pause
