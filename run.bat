@echo off
gcc main.c -o prog -I inc ^
src/product.c ^
src/productArray.c ^
src/system.c ^
src/systemArray.c ^
src/systemColoring.c ^
src/systemFile.c ^
src/systemInterface.c ^
src/systemTime.c ^
src/transaction.c ^
src/transactionArray.c ^
src/utils.c ^
src/report.c
if %ERRORLEVEL% neq 0 (
    echo Compilation failed!
    exit /b %ERRORLEVEL%
)
prog
@echo on
