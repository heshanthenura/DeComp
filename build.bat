@echo off

set SRC_DIR=src
set INCLUDE_DIR=include
set BUILD_DIR=build

if not exist %BUILD_DIR% (
    mkdir %BUILD_DIR%
)

g++ -I%INCLUDE_DIR% -c %SRC_DIR%\main.cpp -o %BUILD_DIR%\main.o
g++ -I%INCLUDE_DIR% -c %SRC_DIR%\process_utils.cpp -o %BUILD_DIR%\process_utils.o

g++ %BUILD_DIR%\main.o %BUILD_DIR%\process_utils.o -o %BUILD_DIR%\DeComp

echo Running the program...
%BUILD_DIR%\DeComp