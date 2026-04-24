@echo off
gcc main.c -o prog -I inc ^
src/systemTime.c ^
src/systemInterface.c
prog
@echo on
