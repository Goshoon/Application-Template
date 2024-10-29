@echo off
setlocal enabledelayedexpansion
set "SOURCES="
set "OBJECTS="
set "INCLUDES="

:: Collect all source files and their respective object file paths
for /R ./Source %%f in (*.cpp) do (
    set "SOURCES=!SOURCES! %%f"
    set "OBJECTS=!OBJECTS! %%~nf.o"
)

:: Collect all include directories
for /R ./Headers /D %%d in (*) do (
    set "INCLUDES=!INCLUDES! %%d"
)

:: Compile each source file into an object file
for %%f in (%SOURCES%) do (
    g++ -std=c++17 -c %%f -I ./Headers/ -I %INCLUDES% -I ./Dependencies/SDL2/include -I ./Dependencies/ImGui -o %%~nf.o
)

:: Link all object files into the final executable
g++ %OBJECTS% -L ./Dependencies/SDL2/lib -o ./Bin/run.exe -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

endlocal
pause
exit
