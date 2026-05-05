#include <stdio.h>
#include <stdlib.h>
#include "../inc/product.h"     
#include "../inc/transaction.h" 
#include"../inc/system.h"
#include"../inc/report.h"
#include"../inc/transactionArray.h"
#include"../inc/systemFile.h"

void SystemLogStock(System *system, systemFile *system_file) 
{
    FILE *file_ptr = fopen((*system_file).fileLogStockAndLogHistoryTransaction, "w");
    if (file_ptr == NULL) {
        printf("Khong the mo file: %s\n", (*system_file).fileLogStockAndLogHistoryTransaction);
        return;
    }
    
    fprintf(file_ptr, "==================== BAO CAO TON KHO ====================\n");
    fprintf(file_ptr, "%-5s | %-20s | %-10s | %-12s | %-12s | %-10s\n", 
            "ID", "Ten San Pham", "So Luong", "Gia Nhap", "Gia Ban", "Trang Thai");
    fprintf(file_ptr, "----------------------------------------------------------------------------------\n");

    for (unsigned int i = 0; i < (*system).product_array.count; i++) 
    {
        Product p = (*system).product_array.ptr[i];
        if (p.isDeleted == 0) 
        {
            fprintf(file_ptr, "%-5u | %-20s | %-10lu | %-12lu | %-12lu | %-10s\n", 
                    p.ProductID, 
                    p.ProductName, 
                    p.quantity,
                    p.priceImport,  
                    p.priceSelling, 
                    (p.quantity <= p.lowStockThreshold) ? "SAP HET" : "CON NHIEU");
        }
    }
    fprintf(file_ptr, "----------------------------------------------------------------------------------\n\n");

    fprintf(file_ptr, "==================== LICH SU GIAO DICH ====================\n");
    fprintf(file_ptr, "%-15s | %-10s | %-12s | %-10s\n", "Thoi Gian", "ID SP", "Loai GD", "So Luong");
    fprintf(file_ptr, "-----------------------------------------------------------\n");

    for (unsigned int i = 0; i < (*system).transaction_array.count; i++) 
    {
        Transaction trans = (*system).transaction_array.ptr[i]; //
        fprintf(file_ptr, "%02u/%02u/%04u      | %-10u | %-12s | %-10u\n", 
                trans.time_stamp.date, trans.time_stamp.month, trans.time_stamp.year, //
                trans.productID, 
                (trans.isForSelling == 1) ? "BAN RA" : "NHAP VAO", //
                trans.quantity);
    }
    fprintf(file_ptr, "-----------------------------------------------------------\n");
    fclose(file_ptr);
    printf("Da xuat bao cao tong hop vao file thanh cong!\n");
}