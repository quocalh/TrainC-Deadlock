@echo off
gcc testing.c -o prog -I inc ^
src/systemTime.c
prog
@echo on
