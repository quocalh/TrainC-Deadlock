#ifndef SYSTEM_H
#define SYSTEM_H

#include "systemArray.h"

typedef struct {
  productArray product_array;
} System;

// Them san pham : ma | ten | loai | so luong | gia nhap | gia ban
void SystemAddNewProduct(System *system, int productID, char *productName,
                         char *productCategory, int quantity,
                         unsigned long int priceImport,
                         unsigned long int priceSelling);

void SystemCheckStockLevels(System *system);
void SystemDeleteProduct(System *system, int productID);
void SystemUpdateInventoryStock(System *system, int productID,
                                int quantityChange, int type);
void SystemViewInventory(System *system);

// Thong bao: dat | thong bao

void SystemSetLowStockThreshold(System *system, int systemSet,
                                char *systemAnnouncement);
// Phan loai: Loc san pham
void SystemDisplayProduct(System *system);
// Sap xep:
void SystemViewSortProduct(System *system);
// Xuat:
void SystemExportStock(System *system);
void SystemExportTransaction(System *system);
#endif
//tim kiem san pham:ma SKU / ten san pham (ko phan biet HOA thuong)         
void SystemSearchProduct(int ProducID, char *productName, unsigned long int priceSelling);
//canh bao hang sap het
void SystemWarningItemisrunninglow (int ProducID, char *productName, char *productCategory, 
  int quantity);
//luu file va doc file
void SystemReadAndSaveFile (int ProducID, char *productName, char *productCategory,
                         int quantity, unsigned long int priceImport,
                         unsigned long int priceSelling) ;                         
//lich su nhap va xuat cua mot san pham
void SystemImportandExportHistory ( int ProducID, char *productName, char *productCategory,
                         int quantity, unsigned long int priceImport);
#endif
