#ifndef SYSTEM_H
#define SYSTEM_H

#include "systemArray.h"

typedef struct {
  productArray product_array;
} System;

// Them san pham : ma | ten | loai | so luong | gia nhap | gia ban
void SystemAddNewProduct(int ProducID, char *productName, char *productCategory,
                         int quantity, unsigned long int priceImport,
                         unsigned long int priceSelling);
void ystemCheckStockLevels(System *system);
void systemDeleteProduct(System *system, int productID);
void systemUpdateInventoryStock(System *system, int productID, int quantityChange, int type);
void systemViewInventory(System *system); 
#endif
