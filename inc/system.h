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
// Thong bao: dat | thong bao
void SystemSetLowStockThreshold(System *system,int systemSet, char *systemAnnouncement);
// Phan loai: Loc san pham
void SystemDisplayProduct(System *system);
//Sap xep: 
void SystemViewSortProduct(System *system);
//Xuat:
void SystemExportStock(System *system);
void SystemExportTransaction(System *system);
#endif
