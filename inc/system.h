#ifndef SYSTEM_H
#define SYSTEM_H

#include "systemArray.h"

typedef struct {
  productArray product_array;
} System;

// 1:
void SystemAddNewProduct(System *system, int productID, char *productName,
                         char *productCategory, int quantity,
                         unsigned long int priceImport,
                         unsigned long int priceSelling);

// 2:
void SystemModifyProduct(System *system);

// 3:
void SystemDeleteProduct(System *system, int productID);

// 4:
void SystemUpdateStock(System *system, int productID, int quantityChange,
                       int type);                  
// 5:
void SystemDisplayProduct(System *system);

// 6:
void SystemSearchProductByID(System *system, int ProductID, char *productName,
                             unsigned long int priceSelling);
void SystemSearchProductByName(System *system, int ProductID, char *productName,
                               unsigned long int priceSelling);

// 7:
void SystemLowStockWarning(System *system, int ProductID, char *productName,
                           char *productCategory, int quantity);
// 8:
void SystemReadFile(System *system, int ProductID, char *productName,
                    char *productCategory, int quantity,
                    unsigned long int priceImport,
                    unsigned long int priceSelling);
void SystemWriteFile(System *system, int ProductID, char *productName,
                     char *productCategory, int quantity,
                     unsigned long int priceImport,
                     unsigned long int priceSelling);

// 9:
void SystemImportandExportHistory(System *system, int ProductID,
                                  char *productName, char *productCategory,
                                  int quantity, unsigned long int priceImport);
// 10:
void SystemCalculateProfit(System *system);

// 11:
void SystemSetLowStockThreshold(System *system, int systemSet,
                                char *systemAnnouncement);
// 12:
void SystemDisplayProductByCategories(System *system);

// 13:
void SystemDisplaySortProduct(System *system);

// 14:
void SystemLogStock(System *system);
void SystemLogHistoryTransaction(System *system);
#endif
