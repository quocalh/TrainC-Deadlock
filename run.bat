@echo off
gcc main.c -o prog -I inc ^
src/product.c ^
src/system.c ^
src/systemArray.c ^
src/systemColoring.c ^
src/systemFile.c ^
src/systemInterface.c ^
src/systemTime.c ^
src/transaction.c
prog
@echo on
