#ifndef SYSTEM_FILE_H
#define SYSTEM_FILE_H

#include "setting.h"
#include "systemArray.h"
#include <stdio.h>

typedef struct {
  FILE *file_ptr;
  unsigned int Range;
  unsigned int currentRange;
  char fileName[MAX_FILE_STRING_LENGTH];
} systemFile;
void systemFileInit(systemFile *system_file, unsigned int range);

void systemFileLoadProductArray(systemFile *system_file,
                                productArray *product_array);

void systemFileSaveProductArray(systemFile *system_file,
                                productArray *productArray, uint n);

void systemFileMarkDeleteProduct(systemFile *system_file, uint productID,
                                 Product *product);

void systemFileModifyProduct(systemFile *system_file, uint productID,
                             Product *product);
#endif
