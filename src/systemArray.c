#include "../inc/systemArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_AMOUNT 10

// DEBUG UTILITIES - OPENGL ENUM APROACH
int PRODUCT_ARRAY_CAPACITY_OVERFLOW = 0;
int PRODUCT_ARRAY_ALLOCATE_FAILED = 0;

void ProductArrayDiagnose() {
  if (PRODUCT_ARRAY_ALLOCATE_FAILED) {
    printf("Failed to allocate more space for the heap array\n");
  }
  if (PRODUCT_ARRAY_CAPACITY_OVERFLOW) {
    printf("Allocate slots count is larger than the given capacity\n");
  }
}

void Allocate(productArray *product_array, unsigned int AllocatedSlot) {
  if (AllocatedSlot > product_array->capacity) {
    PRODUCT_ARRAY_CAPACITY_OVERFLOW = 1;
    return;
  }

  Product *new_ptr =
      realloc(product_array->ptr, sizeof(Product) * AllocatedSlot);

  if (new_ptr == NULL) {
    PRODUCT_ARRAY_ALLOCATE_FAILED = 1;
    return;
  }

  product_array->ptr = new_ptr;
  product_array->currentCapacity = AllocatedSlot;
}

void AddProduct(productArray *product_array, unsigned int ProductID,
                char *ProductName, char *Category, unsigned int quantity,
                unsigned long int priceImport, unsigned long int priceSelling,
                unsigned int lowStockThreshold) {

  if (product_array->count >= product_array->capacity) {
    PRODUCT_ARRAY_CAPACITY_OVERFLOW = 1;
    return;
  }

  if (product_array->count >= product_array->currentCapacity) {
    unsigned int newCapacity = product_array->currentCapacity * 2;

    if (newCapacity > product_array->capacity) {
      newCapacity = product_array->capacity;
    }

    Allocate(product_array, newCapacity);

    if (PRODUCT_ARRAY_ALLOCATE_FAILED) {
      return;
    }
  }

  Product *p = &product_array->ptr[product_array->count];

  p->ProductID = ProductID;
  strcpy(p->ProductName, ProductName);
  strcpy(p->Category, Category);
  p->quantity = quantity;
  p->priceImport = priceImport;
  p->priceSelling = priceSelling;
  p->lowStockThreshold = lowStockThreshold;

  product_array->count++;
}

void Init(productArray *product_array, unsigned int maxCapacity) {
  product_array->ptr = NULL;
  product_array->currentCapacity = 0;
  product_array->count = 0;
  product_array->capacity = maxCapacity;

  Allocate(product_array, INIT_AMOUNT);
}
void Free(productArray *product_array) { free(product_array->ptr); }
