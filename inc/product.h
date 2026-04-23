#ifndef PRODUCT_H
#define PRODUCT_H

#include "setting.h"

typedef struct {
  int ProductID;

  char ProductName[MAX_STRING_LENGTH];
  char Category[MAX_STRING_LENGTH];

  unsigned long int quantity;
  unsigned long int priceImport;
  unsigned long int priceSelling;
  unsigned int lowStockThreshold;

  int isDeleted;
} Product;

#endif
