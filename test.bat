@echo off
gcc testing.c -o prog -I inc ^
src/systemTime.c ^
src/systemInterface.c
prog
@echo on
