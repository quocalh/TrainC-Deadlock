#ifndef SYSTEM_ARRAY_H
#define SYSTEM_ARRAY_H

#include "product.h"

#define INIT_AMOUNT 10
#define INCREMENT 10

typedef struct {
  Product *ptr; // heap
  int capacity;
  int count;
} productArray;

void Allocate(productArray *product_array, unsigned int AllocatedSlot);

void AddProduct(productArray *product_array);

void Init(productArray *product_array);
void Delete(productArray *product_array);

#endif
