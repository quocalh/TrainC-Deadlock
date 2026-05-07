#ifndef SYSTEM_H
#define SYSTEM_H

#include "systemArray.h"
#include "systemFile.h"
#include "systemTime.h"
#include "transactionArray.h"

typedef struct {
  productArray product_array;
  transactionArray transaction_array;

  systemTime system_time;

  systemFile system_file_product;
  systemFile system_file_transaction;
  systemFile system_file_report;
} System;

void SystemInit(System *system);
void SystemExit(System *system);

// 1:
void SystemAddNewProduct(System *system);

// 2:(done)
void SystemModifyProduct(System *system);

// 3:(done)
void SystemDeleteProduct(System *system);

// 4:(done)
void SystemUpdateStock(System *system);

// 5:(done)
void SystemDisplayProduct(System *system);

// 6:
void SystemSearchProductByID(System *system);
void SystemSearchProductByName(System *system);

// 7:
void SystemLowStockWarning(System *system);

// 8:
void SystemReadFile(System *system, int ProductID, char *productName,
                    char *productCategory, int quantity,
                    unsigned long int priceImport,
                    unsigned long int priceSelling);
void SystemWriteFile(System *system, int ProductID, char *productName,
                     char *productCategory, int quantity,
                     unsigned long int priceImport,
                     unsigned long int priceSelling);

// 9: (done)
void SystemDisplayTransaction(System *system);

// 10: (done)
void SystemCalculateProfit(System *system);

// 11:
void SystemSetLowStockThreshold(System *system);

// 12:
int SystemDisplayProductByCategories(System *system);

// 13:
int SystemDisplaySortedProductByAlphabeticOrder(System *system);
int SystemDisplayProductByStock(System *system);
#endif
