#include "../inc/systemArray.h"
#include "../inc/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

productArray productArrayInit(int maxCapacity) {
  productArray product_array;
  product_array.ptr = (Product *)malloc(sizeof(Product) * 1);

  if (product_array.ptr == NULL) {
    printf("Failed to init a heap array\n");
    product_array.capacity = 0;
    product_array.currentCapacity = 0;
  } else {
    product_array.capacity = maxCapacity;
    product_array.currentCapacity = 1;
  }
  product_array.count = 0;
  return product_array;
}

int productArrayAllocate(productArray *product_array, unsigned int NeededSlot) {
  if (NeededSlot > product_array->capacity) {
    return 0;
  }
  if (NeededSlot <= product_array->currentCapacity) {
    return 1;
  }
  // NeededSlot > currentcapacity | expand
  unsigned int newExtenededBlock =
      uint_max(product_array->currentCapacity * 2, NeededSlot);
  newExtenededBlock = uint_min(product_array->capacity, newExtenededBlock);

  Product *ptr = (Product *)realloc(product_array->ptr,
                                    sizeof(Product) * newExtenededBlock);
  if (ptr == NULL) {
    printf("Failed to allocate the given NeededSlot (%d)", NeededSlot);
    return 0;
  }
  product_array->ptr = ptr;
  product_array->currentCapacity = newExtenededBlock;
  return 1;
}

int productArrayAddProduct(productArray *product_array, unsigned int ProductID,
                           char *ProductName, char *Category,
                           unsigned int quantity, unsigned long int priceImport,
                           unsigned long int priceSelling,
                           unsigned int lowStockThreshold,
                           unsigned int isDeleted) {
  int success = productArrayAllocate(product_array, product_array->count + 1);
  if (!success) {
    return 0;
  }

  Product *product_slot = &product_array->ptr[product_array->count];

  product_slot->ProductID = ProductID;
  strcpy(product_slot->ProductName, ProductName);
  strcpy(product_slot->Category, Category);
  product_slot->quantity = quantity;
  product_slot->priceImport = priceImport;
  product_slot->priceSelling = priceSelling;
  product_slot->lowStockThreshold = lowStockThreshold;
  product_slot->isDeleted = isDeleted;

  product_array->count++;

  return 1;
}

void productArrayFree(productArray *product_array) {
  printf("productArray: freed\n");
  free(product_array->ptr);
}

// field tested (in testing.c)
// #include "inc/systemArray.h"
// #include <stdio.h>
// int main() {
//   printf("Hello world\n");
//   productArray product_array = productArrayInit(100);
//
//   productArrayAddProduct(&product_array, 54, "Marker", "Book", 20, 30, 40,
//   10); Product *appended = &product_array.ptr[product_array.count - 1];
//   printf("ID: %d, Name: %s, Category: %s, Price: %ld\n", appended->ProductID,
//          appended->ProductName, appended->Category, appended->priceSelling);
//   printf("count: %d, current: %d, capacity: %d\n", product_array.count,
//          product_array.currentCapacity, product_array.capacity);
//
//   productArrayAddProduct(&product_array, 54, "Marker", "Book", 20, 30, 40,
//   10); appended = &product_array.ptr[product_array.count - 1]; printf("ID:
//   %d, Name: %s, Category: %s, Price: %ld\n", appended->ProductID,
//          appended->ProductName, appended->Category, appended->priceSelling);
//   printf("count: %d, current: %d, capacity: %d\n", product_array.count,
//          product_array.currentCapacity, product_array.capacity);
//
//   productArrayAddProduct(&product_array, 54, "Marker", "Book", 20, 30, 40,
//   10); appended = &product_array.ptr[product_array.count - 1]; printf("ID:
//   %d, Name: %s, Category: %s, Price: %ld\n", appended->ProductID,
//          appended->ProductName, appended->Category, appended->priceSelling);
//   printf("count: %d, current: %d, capacity: %d\n", product_array.count,
//          product_array.currentCapacity, product_array.capacity);
//
//   productArrayAddProduct(&product_array, 54, "Marker", "Book", 20, 30, 40,
//   10); appended = &product_array.ptr[product_array.count - 1]; printf("ID:
//   %d, Name: %s, Category: %s, Price: %ld\n", appended->ProductID,
//          appended->ProductName, appended->Category, appended->priceSelling);
//   printf("count: %d, current: %d, capacity: %d\n", product_array.count,
//          product_array.currentCapacity, product_array.capacity);
//
//   productArrayAddProduct(&product_array, 54, "Marker", "Book", 20, 30, 40,
//   10); appended = &product_array.ptr[product_array.count - 1]; printf("ID:
//   %d, Name: %s, Category: %s, Price: %ld\n", appended->ProductID,
//          appended->ProductName, appended->Category, appended->priceSelling);
//   printf("count: %d, current: %d, capacity: %d\n", product_array.count,
//          product_array.currentCapacity, product_array.capacity);
//
//   printf("\nTesting section -----------------\n");
//   for (unsigned int i = 0; i < product_array.count; i++) {
//     Product *product = &product_array.ptr[i];
//     printf("ID: %d, Name: %s, Category: %s, Price: %ld\n",
//     product->ProductID,
//            product->ProductName, product->Category, product->priceSelling);
//   }
//
//   printf("\n");
//   productArrayFree(&product_array);
// }
