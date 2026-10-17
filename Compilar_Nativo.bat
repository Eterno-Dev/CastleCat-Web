@echo off
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

echo [*] Compilando src\Main.c a CastleCat.exe ...
gcc -O2 src\Main.c -o CastleCat.exe

if errorlevel 1 (
    echo/
    echo [ERROR] La compilacion nativa ha fallado.
    pause
    exit /b 1
)

echo/
echo [OK] Compilacion Exitosa: CastleCat.exe generado.
echo/
pause
