#include "../inc/systemFile.h"
#include "../inc/product.h"
#include "../inc/setting.h"
#include "../inc/transaction.h"
#include <stdio.h>
#include <string.h>

// read function
void systemFileLoadProductArray(systemFile *system_file,
                                productArray *product_array) {
  FILE *file_ptr = fopen(system_file->fileName, "r");
  if (file_ptr == NULL) {
    printf("cannot open the given file: %s\n", system_file->fileName);
    return;
  }

  Product product;

  while (fscanf(file_ptr, "%u \"%[^\"]\" \"%[^\"]\" %lu %lu %lu %u %u",
                &product.ProductID, product.ProductName, product.Category,
                &product.quantity, &product.priceImport, &product.priceSelling,
                &product.lowStockThreshold, &product.isDeleted) == 8) {

    productArrayAddProduct(product_array, product.ProductName, product.Category,
                           product.quantity, product.priceImport,
                           product.priceSelling, product.lowStockThreshold,
                           product.isDeleted);
  }

  fclose(file_ptr);
}
// save function
void systemFileSaveProductArray(systemFile *system_file,
                                productArray *productArray) {
  FILE *file_ptr = fopen(system_file->fileName, "w");

  if (file_ptr == NULL) {
    printf("cannot open the given file: %s\n", system_file->fileName);
    return;
  }

  for (uint i = 0; i < productArray->count; i++) {

    Product product = productArray->ptr[i];

    fprintf(file_ptr, "%d \"%s\" \"%s\" %lu %lu %lu %u %u\n", product.ProductID,
            product.ProductName, product.Category, product.quantity,
            product.priceImport, product.priceSelling,
            product.lowStockThreshold, product.isDeleted);
  }

  fclose(file_ptr);
}

// delete function
void systemFileMarkDeleteProduct(systemFile *system_file, Product *product) {
  uint isFound = 0;
  char buffer[MAX_FILE_WIDTH];

  FILE *file_ptr = fopen(system_file->fileName, "r");
  FILE *temp = fopen(system_file->fileNameTemp, "w");

  if (file_ptr == NULL || temp == NULL) {
    printf("cannot open the given file: %s\n", system_file->fileName);
    return;
  }
  while (fgets(buffer, MAX_FILE_WIDTH, file_ptr) != NULL) {

    uint id_in_file;
    if (sscanf(buffer, "%u", &id_in_file) == 1) {

      if (id_in_file == product->ProductID) {

        if (product->isDeleted == 1) {
          product->isDeleted = 0;
        } else if (product->isDeleted == 0) {
          product->isDeleted = 1;
        }

        fprintf(temp, "%u \"%s\" \"%s\" %lu %lu %lu %u %u\n",
                product->ProductID, product->ProductName, product->Category,
                product->quantity, product->priceImport, product->priceSelling,
                product->lowStockThreshold, product->isDeleted);
        isFound = 1;

      } else {
        fputs(buffer, temp);
      }
    }
  }

  if (!isFound) {
    printf("ID not found.\n");
    return;
  }

  fclose(file_ptr);
  fclose(temp);
  remove(system_file->fileName);
  rename(system_file->fileNameTemp, system_file->fileName);
}

uint systemFileAppendProduct(systemFile *system_file, Product *product) {
  char fileName[MAX_FILE_STRING_LENGTH];
  strcpy(fileName, system_file->fileName);

  FILE *file_ptr = fopen(system_file->fileName, "a");

  if (file_ptr == NULL) {
    printf("whut the hell\n");
    return 0;
  }

  fprintf(file_ptr, "%d \"%s\" \"%s\" %lu %lu %lu %u %u\n", product->ProductID,
          product->ProductName, product->Category, product->quantity,
          product->priceImport, product->priceSelling,
          product->lowStockThreshold, product->isDeleted);

  fclose(file_ptr);

  return 1;
}

void systemFileModifyProduct(systemFile *system_file,
                             Product *modified_product) {
  FILE *file_ptr = fopen(system_file->fileName, "r");
  FILE *temp_ptr = fopen(system_file->fileNameTemp, "w");

  if (file_ptr == NULL || temp_ptr == NULL) {
    printf("can't open the given file: %s, %s", system_file->fileName,
           system_file->fileNameTemp);
    return;
  }
  char buffer[MAX_FILE_WIDTH];

  uint isFound = 0;
  while (fgets(buffer, MAX_FILE_WIDTH, file_ptr) != NULL) {

    uint FileproductID;
    if (sscanf(buffer, "%u", &FileproductID) == 1) {

      if (FileproductID == modified_product->ProductID) {
        fprintf(temp_ptr, "%u \"%s\" \"%s\" %lu %lu %lu %u %u\n",
                modified_product->ProductID, modified_product->ProductName,
                modified_product->Category, modified_product->quantity,
                modified_product->priceImport, modified_product->priceSelling,
                modified_product->lowStockThreshold,
                modified_product->isDeleted);
        isFound = 1;
      } else {
        fputs(buffer, temp_ptr);
      }
    }
  }
  if (!isFound) {
    printf("ID not found");
    return;
  }

  fclose(file_ptr);
  fclose(temp_ptr);
  remove(system_file->fileName);
  rename(system_file->fileNameTemp, system_file->fileName);
  return;
}
// load trans:
void systemFileLoadTransactionArray(systemFile *system_file, transactionArray *transaction_array)
{
FILE *file_ptr = fopen(system_file->fileName, "r");
    if (file_ptr == NULL) 
    {
        printf("cannot open the given file: %s\n", system_file->fileName);
        return;
    }
    Transaction trans;
    while (fscanf(file_ptr, "%u %u %u/%u/%u %u:%u:%u %hu", 
              &trans.productID, 
              &trans.quantity,
              &trans.time_stamp.date,   
              &trans.time_stamp.month, 
              &trans.time_stamp.year,
              &trans.time_stamp.hour,
              &trans.time_stamp.minute,
              &trans.time_stamp.second,
              &trans.isForSelling) == 9) 
    {
        transactionArrayAdd(transaction_array, trans); 
    }

    fclose(file_ptr);
}
