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
                       int type)
  {
    int found = 0;
    for (int i = 0; i < (*system).product_array.count; i++) 
    {
      if ((*system).product_array.ptr[i].ProductID == productID) 
      {
          found = 1;

          if (type == 1)
          {
                (*system).product_array.ptr[i].quantity += (unsigned long)quantityChange;
                printf("Da nhap %d vao ID %d.\n", quantityChange, productID);
          } 
          else if (type == 2)
          { 
              if ((*system).product_array.ptr[i].quantity >= (unsigned long)quantityChange) 
              {
                   (*system).product_array.ptr[i].quantity -= (unsigned long)quantityChange;
                  printf("Da xuat %d tu ID %d.\n", quantityChange, productID);
                  if ((*system).product_array.ptr[i].quantity <= (*system).product_array.ptr[i].lowStockThreshold) 
                  {
                      printf("!!! CANH BAO: San pham '%s' sap het hang (Con lai: %lu)\n", 
                              (*system).product_array.ptr[i].ProductName, 
                              (*system).product_array.ptr[i].quantity);
                  }
              } 
               else 
               {
                  printf("Khong du hang! Trong kho chi con %lu.\n", (*system).product_array.ptr[i].quantity);
               }
           }
           break; 
      }
  }

  if (found == 0) 
  {
      printf("Khong tim thay ID %d trong he thong.\n", productID);
  }
}                     

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
