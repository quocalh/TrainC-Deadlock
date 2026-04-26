#include "../inc/systemArray.h"
#include <stdlib.h>

#define INIT_AMOUNT 10
void Allocate(productArray *product_array, unsigned int AllocatedSlot) {
  Product *new_ptr = (Product *)malloc(sizeof(Product) * AllocatedSlot);

  if (product_array->count >= product_array->capacity) {
    return;
  }

  product_array->count = AllocatedSlot;
  if (new_ptr == NULL) {
    return;
  }

  product_array->ptr = new_ptr;
}
void AddProduct(productArray *product_array) {
  product_array->count++;
  return;
}
void Init(productArray *product_array) { Allocate(product_array, INIT_AMOUNT); }
void Delete(productArray *product_array) { free(product_array->ptr); }
