#ifndef SYSTEM_ARRAY_H
#define SYSTEM_ARRAY_H

#include "product.h"

#define INIT_AMOUNT 10
#define INCREMENT 10

typedef struct {
  Product *ptr; // heap [product0, product1, product2, prouct3]
  unsigned int capacity;
  unsigned int currentCapacity;
  unsigned int count;
} productArray;

void Allocate(productArray *product_array, unsigned int AllocatedSlot);

void AddProduct(productArray *product_array, unsigned int ProductID,
                char *ProductName, char *Category, unsigned int quantity,
                unsigned long int priceImport, unsigned long int priceSelling,
                unsigned int lowStockThreshold);

void Init(productArray *product_array, unsigned int maxCapacity);
void Free(productArray *product_array);

#endif
