#ifndef SYSTEM_FILE_H
#define SYSTEM_FILE_H

#include "systemArray.h"
#include <stdio.h>

typedef struct {
  FILE file_ptr;
} systemFile;

void systemFileLoadProductArray(productArray *product_array, char *fileName);

#endif
