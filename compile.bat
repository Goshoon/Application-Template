@echo off

:: enabledelayedexpansion permite utilizar !SOURCES! que es la manera de acceder una variable dentro de un ciclo
setlocal enabledelayedexpansion
set "SOURCES="
set "INCLUDES="

:: Buscar todos los archivos .cpp dentro de ./Source y carpetas dentro de ./Source/
for /R ./Source %%f in (*.cpp) do (
    set "SOURCES=!SOURCES! %%f"
)

:: Buscar todas las carpetas de inclusion dentro de ./Headers/
for /R ./Headers /D %%d in (*) do (
    set "INCLUDES=!INCLUDES! %%d"
)

:: Compilar
g++ -std=c++17 %SOURCES% -I ./Headers/ -I %INCLUDES% -I ./Dependencies/SDL2/include -I ./Dependencies/ImGui -L ./Dependencies/SDL2/lib -o ./Bin/run.exe -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

endlocal
pause
exit