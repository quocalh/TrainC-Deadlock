#ifndef SYSTEM_FILE_H
#define SYSTEM_FILE_H

#include "setting.h"
#include "systemArray.h"
#include "transaction.h"
#include "transactionArray.h"

typedef struct {
  char fileName[MAX_FILE_STRING_LENGTH];
  char fileNameTemp[MAX_FILE_STRING_LENGTH];
  char fileLogStockAndLogHistoryTransaction[MAX_FILE_STRING_LENGTH];
} systemFile;

void systemFileInit(systemFile *system_file, unsigned int range);

void systemFileLoadProductArray(systemFile *system_file,
                                productArray *product_array);

void systemFileSaveProductArray(systemFile *system_file,
                                productArray *productArray);

void systemFileMarkDeleteProduct(systemFile *system_file, Product *product);

uint systemFileAppendProduct(systemFile *system_file, Product *product);

void systemFileModifyProduct(systemFile *system_file, Product *product);

void systemFileAppendTransaction(systemFile *system_file,
                                 Transaction *transaction);

void systemFileLoadTransactionArray(systemFile *system_file,
                                    transactionArray *transaction_array);

void systemFileSaveTrasanctionArray(systemFile *system_file,
                                    transactionArray *transaction_array);
#endif
