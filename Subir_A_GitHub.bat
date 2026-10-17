@echo off
setlocal enabledelayedexpansion
title Subir CastleCat a GitHub

echo ========================================================
echo          SUBIR CASTLECAT A GITHUB (GitHub Pages)
echo ========================================================
echo/

cd /d "%~dp0"

echo [*] Repositorio remoto:
git remote -v
echo/

echo [*] Comprobando cambios en el proyecto:
git status -s
echo/

echo [*] Preparando archivos para commit...
git add .

set /p "COMMIT_MSG=Introduce el mensaje del commit (Enter para usar mensaje automatico): "
if "!COMMIT_MSG!"=="" (
    set "COMMIT_MSG=Actualizacion CastleCat: Web y Juego (%DATE% %TIME%)"
)

echo/
echo [*] Creando commit: "!COMMIT_MSG!"
git commit -m "!COMMIT_MSG!"

echo/
echo ========================================================
echo   Enviando cambios a GitHub (origin/main)...
echo   (Si no has iniciado sesion, se abrira GitHub en el navegador)
echo ========================================================
echo/

git push origin main
if %errorlevel% equ 0 (
    echo/
    echo ========================================================
    echo   [OK] !SUBIDO CON EXITO A GITHUB!
    echo ========================================================
    echo Tu web y juego estaran activos en breve en GitHub Pages:
    echo   Web principal: https://eterno-dev.github.io/CastleCat-Web/
    echo   Juego Web:     https://eterno-dev.github.io/CastleCat-Web/game/temp/
) else (
    echo/
    echo ========================================================
    echo   [AVISO] El envio ha devuelto un codigo de estado distinto de cero.
    echo ========================================================
    echo Si es la primera vez que haces push desde esta maquina,
    echo inicia sesion en GitHub cuando te lo pida la ventana emergente.
)

echo/
pause
