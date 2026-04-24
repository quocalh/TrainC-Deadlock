#ifndef SYSTEM_INTERFACE_H
#define SYSTEM_INTERFACE_H

#include "system.h"

typedef struct {

} systemInterface;

void Interface(System *system);

void InterfaceAddNewProduct(System *system);
void InterfaceModifyProduct(System *system);
void InterfaceDeleteProduct(System *system);

void InterfaceDisplayProduct(System *system);
void InterfaceUpdateStock(System *system);

void InterfaceSetProductThreshold(System *system);
void InterfaceDisplaySortedProduct(System *system);

// import export runs in the background, no interface yah
#include "../inc/systemInterface.h"
#include "../inc/system.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearBuffer() 
{
    int c;
   while (getchar() != '\n');
}

void Interface(System *system) 
{
    int choice;
    do {
        printf("\n====================================");
        printf("\n       HỆ THỐNG QUẢN LÝ      ");
        printf("\n====================================");
        printf("\n1. Thêm sản phẩm mới");
        printf("\n2. Sửa thông tin sản phẩm");
        printf("\n3. Xóa sản phẩm");
        printf("\n4. Hiển thị danh sách sản phẩm");
        printf("\n5. Sắp xếp và hiển thị sản phẩm");
        printf("\n6. Cập nhật số lượng kho (Stock)");
        printf("\n7. Thiết lập ngưỡng thông báo (Threshold)");
        printf("\n0. Thoát chương trình");
        printf("\n------------------------------------");
        printf("\nLựa chọn của bạn: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) 
        {
            case 1: InterfaceAddNewProduct(system); break;
            case 2: InterfaceModifyProduct(system); break;
            case 3: InterfaceDeleteProduct(system); break;
            case 4: InterfaceDisplayProduct(system); break;
            case 5: InterfaceDisplaySortedProduct(system); break;
            case 6: InterfaceUpdateStock(system); break;
            case 7: InterfaceSetProductThreshold(system); break;
            case 0: printf("\nĐang thoát...\n"); break;
            default: printf("\nLựa chọn không hợp lệ! Vui lòng thử lại.");
        }
    } 
    while (choice != 0);
}

void InterfaceAddNewProduct(System *system) 
{
    printf("\n--- THÊM SẢN PHẨM MỚI ---");
    printf("\n[Thông báo] Đã thêm sản phẩm thành công!");
}
void InterfaceModifyProduct(System *system) 
{
    printf("\n--- SỬA THÔNG TIN SẢN PHẨM ---");
    char id[20];
    printf("Nhập mã sản phẩm cần sửa: ");
    scanf("%s", id);
}

void InterfaceDeleteProduct(System *system) 
{
    printf("\n--- XÓA SẢN PHẨM ---");
    char id[20];
    printf("Nhập mã sản phẩm muốn xóa: ");
    scanf("%s", id);
}

void InterfaceDisplayProduct(System *system)
 {
    printf("\n--- DANH SÁCH SẢN PHẨM ---\n");
    printf("%-10s | %-20s | %-10s | %-10s\n", "Mã SP", "Tên SP", "Giá", "Tồn kho");
}

void InterfaceUpdateStock(System *system) 
{
    printf("\n--- CẬP NHẬT KHO HÀNG ---");
}

void InterfaceDisplaySortedProduct(System *system) 
{
    printf("\n--- DANH SÁCH ĐÃ SẮP XẾP ---");
    // logic: sortSystem(system); sau đó in ra
}

void InterfaceSetProductThreshold(System *system)
 {
    printf("\n--- THIẾT LẬP NGƯỠNG CẢNH BÁO ---");
}
#endif
