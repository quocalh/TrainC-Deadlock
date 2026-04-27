#include "../inc/systemArray.h"
#include "../inc/utils.h"
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
  if (product_array->currentCapacity >= product_array->capacity) {
    PRODUCT_ARRAY_CAPACITY_OVERFLOW = 1;
    return;
  }
  Product *new_ptr = (Product *)malloc(sizeof(Product) * AllocatedSlot);
  if (new_ptr == NULL) {
    return;
  }
  product_array->currentCapacity = AllocatedSlot;
  product_array->ptr = new_ptr;
}

void AddProduct(productArray *product_array, unsigned int ProductID,
                char *ProductName, char *Category, unsigned int quantity,
                unsigned long int priceImport, unsigned long int priceSelling,
                unsigned int lowStockThreshold) {
  // if larger than the maximum capacity -> bombaclat
  if (product_array->currentCapacity >= product_array->capacity) {
    PRODUCT_ARRAY_CAPACITY_OVERFLOW = 1;
    return;
  }
  // if out of overhead slots, then allocate more
  if (product_array->count + 1 >= product_array->currentCapacity) {
    unsigned int appending_slot = int_max(
        product_array->count - product_array->currentCapacity + 1, INCREMENT);

    Allocate(product_array, product_array->currentCapacity + appending_slot);
    if (PRODUCT_ARRAY_ALLOCATE_FAILED == 1) {
      printf("whut the hell\n");
      return;
    }
    product_array->currentCapacity += appending_slot;
  }
  // add a new product
  Product *new_product = &product_array->ptr[product_array->count];
  new_product->ProductID = ProductID;
  strcpy(new_product->ProductName, ProductName);
  strcpy(new_product->Category, Category);
  new_product->quantity = quantity;
  new_product->priceImport = priceImport;
  new_product->priceSelling = priceSelling;
  new_product->lowStockThreshold = lowStockThreshold;

  product_array->count++;
  return;
}

void Init(productArray *product_array, unsigned int maxCapacity) {
  Allocate(product_array, INIT_AMOUNT);
  product_array->count = 0;
  product_array->capacity = maxCapacity;
}
void Free(productArray *product_array) { free(product_array->ptr); }
