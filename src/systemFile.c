#include "../inc/systemFile.h"
#include "../inc/product.h"
#include "../inc/setting.h"
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

// read function
void systemFileLoadProductArray(systemFile *system_file,
                                productArray *product_array) {
  FILE *file_ptr = fopen(system_file->fileName, "r");
  if (file_ptr == NULL) {
    printf("cannot open the given file: %s\n", system_file->fileName);
    return;
  }

  // printf("%-5s %-8s %-12s %-13s %-18s %-20s %-10s %-8s\n", "ID", "Qty",
  //        "Import", "Selling", "Product", "Category", "Threshold", "Deleted");

  Product product;

  while (fscanf(file_ptr, "%u \"%[^\"]\" \"%[^\"]\" %lu %lu %lu %u %u",
                &product.ProductID, product.ProductName, product.Category,
                &product.quantity, &product.priceImport, &product.priceSelling,
                &product.lowStockThreshold, &product.isDeleted) == 8) {

    productArrayAddProduct(product_array, product.ProductName, product.Category,
                           product.quantity, product.priceImport,
                           product.priceSelling, product.lowStockThreshold,
                           product.isDeleted);

    // printf("%-5d %-8ld %-12ld %-13ld %-18s %-20s %-10d %-8d\n",
    //        product.ProductID, product.quantity, product.priceImport,
    //        product.priceSelling, product.ProductName, product.Category,
    //        product.lowStockThreshold, product.isDeleted);
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
void systemFileMarkDeleteProduct(systemFile *system_file, uint productID, Product *product)
{
    char buffer[MAX_LINE];
    char replace[MAX_LINE];
    char temp_filename[MAX_FILE_STRING_LENGTH];
    strcpy(temp_filename, "file_temp.txt");
    int replace_line = 1;
    FILE *file_ptr = fopen(system_file->fileName, "r");
    FILE *temp = fopen(temp_filename,"w");
    if (file_ptr == NULL || temp == NULL) 
    {
        printf("cannot open the given file: %s\n", system_file->fileName);
        return;
    }
    bool keep_reading = true;
    fprintf(temp,"%u \"%s\" \"%s\" %lu %lu %lu %u %u\n", product->ProductID, product->ProductName, product->Category, product->quantity, product->priceImport, product->priceSelling,product->lowStockThreshold, product->isDeleted);
   do 
    {
        if (fgets(buffer, MAX_LINE, file_ptr) == NULL) 
        {
            keep_reading = false;
        }
        else 
        {
            uint id_in_file;
            sscanf(buffer, "%u", &id_in_file);
            if (id_in_file != productID) 
            {
                fputs(buffer, temp);
            }
        }
    } 
    while (keep_reading);
    
    fclose(file_ptr);
    fclose(temp);
    remove(system_file->fileName);
    rename(temp_filename, system_file->fileName);
    
}