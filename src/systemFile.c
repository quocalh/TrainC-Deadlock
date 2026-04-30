#include "../inc/product.h"
#include "../inc/systemFile.h"
#include <stdio.h>
void systemFileInit(systemFile *system_file, unsigned int range) 
{
    if (system_file != NULL) 
    {
        system_file->file_ptr = NULL; // Đảm bảo an toàn trước khi fopen
        system_file->Range = range;
        system_file->currentRange = 0;
    }
}
//read:
void systemFileLoadProductArray(systemFile *system_file, productArray *product_array, char *fileName) 
{
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) 
    {
        printf("Khong the mo file: %s\n", fileName);
        return;
    }
    
    // Gán con trỏ file vào struct (Giả sử bạn sửa lại struct dùng FILE *file_ptr)
    // Nếu bắt buộc dùng FILE file_ptr (không phải con trỏ) thì code sẽ phức tạp hơn và không khuyến khích.
    
    Product product;
    
    // In tiêu đề (Header)
    printf("%-5s %-8s %-12s %-13s %-18s %-20s %-10s %-8s\n", 
           "ID", "Qty", "Import", "Selling", "Product", "Category", "Threshold", "Deleted");

    // 2. Đọc dữ liệu từ file
    while (fscanf(fp, "%d \"%[^\"]\" \"%[^\"]\" %d %d %d %d %d",
                  &product.ProductID, product.ProductName, product.Category,
                  &product.quantity, &product.priceImport, &product.priceSelling,
                  &product.lowStockThreshold, &product.isDeleted) == 8) 
    {
        // Kiểm tra giới hạn Range trước khi nạp
        if (system_file->currentRange <system_file->Range) 
        {
            
            // In ra màn hình như hàm cũ
            printf("%-5d %-8d %-12d %-13d %-18s %-20s %-10d %-8d\n", 
                   product.ProductID, product.quantity, product.priceImport, product.priceSelling,
                   product.ProductName, product.Category, product.lowStockThreshold,
                   product.isDeleted);

            /* 
               3. Thêm logic nạp vào product_array ở đây 
               Ví dụ: addProductToArray(product_array, product);
            */
            
        system_file->currentRange++;
        } 
        else 
        {
            // Logic FIFO delete nếu vượt quá Range như comment của bạn
            printf("Canh bao: Vuot qua gioi han Range (%d). Thuc hien FIFO delete...\n",system_file->Range);
            // Thực hiện hàm xóa phần tử cũ nhất và chèn phần tử mới tại đây
        }
    }

    fclose(fp);
}