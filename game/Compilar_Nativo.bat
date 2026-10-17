@echo off
cd /d "%~dp0"

echo ========================================================
echo   Compilando CastleCat en Nativo (Windows - gcc)
echo ========================================================
echo/

where gcc >nul 2>nul
if errorlevel 1 (
    echo [ERROR] No se ha encontrado el compilador gcc en el PATH.
    pause
    exit /b 1
)

if not exist "temp" mkdir "temp"

echo [*] Compilando src\Main.c a temp\CastleCat.exe ...
gcc -O2 src\Main.c -o temp\CastleCat.exe

if errorlevel 1 (
    echo/
    echo [ERROR] La compilacion nativa ha fallado.
    pause
    exit /b 1
)

echo/
echo [OK] Compilacion Exitosa: temp\CastleCat.exe generado.
echo/
pause
