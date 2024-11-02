@echo off
setlocal enabledelayedexpansion
set "SOURCES="
set "OBJECTS="
set "INCLUDES="

:: Buscar todos los archivos .cpp en ./Source
for /R ./Source %%f in (*.cpp) do (
    set "SOURCES=!SOURCES! %%f"
    set "OBJECTS=!OBJECTS! %%~nf.o"
)

:: Buscar todas las carpetas de inclusion dentro de ./Headers
for /R ./Headers /D %%d in (*) do (
    set "INCLUDES=!INCLUDES! -I%%d"
)

:: Compilar todos los archivos a un archivo de objeto
for %%f in (%SOURCES%) do (
    g++ -std=c++17 -c %%f -I ./Headers/ %INCLUDES% -I ./Dependencies/SDL2/include -I ./Dependencies/ImGui -o %%~nf.o 2> ./Logs/error_log.txt

)

:: Conectar todos los archivos al ejecutable
g++ %OBJECTS% -L ./Dependencies/SDL2/lib -o ./Bin/run.exe -lmingw32 -lSDL2main -lSDL2 -lSDL2_image 2> ./Logs/error_log_linker.txt

if %errorlevel% == 1 (
    echo Compilation error!!!
    pause
    exit
)

pause

echo Compilation succeeded. Running the app...
start ./Bin/run.exe

endlocal
exit
