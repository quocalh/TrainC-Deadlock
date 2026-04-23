#ifndef SYSTEM_ARRAY_H
#define SYSTEM_ARRAY_H

#include "product.h"

typedef struct {
  Product *ptr; // heap
  int capacity;
  int count;
} productArray;

#endif
