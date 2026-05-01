#include "../inc/systemFile.h"
#include "../inc/product.h"
#include <stdio.h>
#include "../inc/setting.h"

// read function
void systemFileLoadProductArray(systemFile *system_file,
                                productArray *product_array) {
  FILE *file_ptr = fopen(system_file->fileName, "r");
  if (file_ptr == NULL) {
    printf("cannot open the given file: %s\n", system_file->fileName);
    return;
  }

  printf("%-5s %-8s %-12s %-13s %-18s %-20s %-10s %-8s\n", "ID", "Qty",
         "Import", "Selling", "Product", "Category", "Threshold", "Deleted");

  Product product;

  while (fscanf(file_ptr, "%d \"%[^\"]\" \"%[^\"]\" %ld %ld %ld %d %d",
                &product.ProductID, product.ProductName, product.Category,
                &product.quantity, &product.priceImport, &product.priceSelling,
                &product.lowStockThreshold, &product.isDeleted) == 8) {

    productArrayAddProduct(product_array, product.ProductID,
                           product.ProductName, product.Category,
                           product.quantity, product.priceImport,
                           product.priceSelling, product.lowStockThreshold);

    printf("%-5d %-8ld %-12ld %-13ld %-18s %-20s %-10d %-8d\n",
           product.ProductID, product.quantity, product.priceImport,
           product.priceSelling, product.ProductName, product.Category,
           product.lowStockThreshold, product.isDeleted);
  }
}
// save function
void systemFileSaveProductArray(systemFile *system_file, productArray *productArray, uint n) 
{
    // Mở file bằng biến local file_ptr
    FILE *file_ptr = fopen(system_file->fileName, "w");
    
    if (file_ptr == NULL) 
    {
        printf("cannot open the given file: %s\n", system_file->fileName);
        return;
    }

    for (uint i = 0; i < n; i++) 
    {
        Product product = productArray->ptr[i]; 
        // SỬA TẠI ĐÂY: Dùng file_ptr thay vì system_file->file_ptr
        fprintf(file_ptr, "%d \"%s\" \"%s\" %u %lu %lu %u %d\n",
                product.ProductID,
                product.ProductName,
                product.Category,
                product.quantity,
                product.priceImport,
                product.priceSelling,
                product.lowStockThreshold,
                product.isDeleted);
    }

    system_file->currentRange = n;
    // Đóng biến local đã mở
    fclose(file_ptr);
}

