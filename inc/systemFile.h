#ifndef SYSTEM_FILE_H
#define SYSTEM_FILE_H

#include "systemArray.h"
#include <stdio.h>

typedef struct {
  FILE *file_ptr;
  // e.g: max item represented in the file: 10000
  // -> Range = 10_000, if the currentRange, perform an FIFO delete
  unsigned int Range;
  unsigned int currentRange;
} systemFile;
void systemFileInit(systemFile *system_file, unsigned int range);
void systemFileLoadProductArray(systemFile *system_file, productArray *product_array, char *fileName); 

#endif
