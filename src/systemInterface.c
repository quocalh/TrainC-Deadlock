#include "../inc/systemInterface.h"
#include <stdio.h>

void clearBuffer() {
  // int c;
  while (getchar() != '\n')
    ;
}

void Interface(System *system) 
{
    int choice;
    do {
        printf("\n====================================");
        printf("\n       HE THONG QUAN LY       ");
        printf("\n====================================");
        printf("\n1. Them san pham moi");
        printf("\n2. Sua thong tin san pham");
        printf("\n3. Xoa san pham");
        printf("\n4. Hien thi danh sach san pham");
        printf("\n5. Sap xep va hien thi san pham");
        printf("\n6. Cap nhat so luong kho (Stock)");
        printf("\n7. Thiet lap nguong thong bao (Threshold)");
        printf("\n0. Thoat chuong trinh");
        printf("\n------------------------------------");
        printf("\nLua chon cua ban: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nLoi: Vui long nhap so!");
            clearBuffer();
            choice = -1; // Gan gia tri tam de tiep tuc vong lap
            continue;
        }
        clearBuffer();

        switch (choice) {
        case 1:
            InterfaceAddNewProduct(system);
            break;
        case 2:
            InterfaceModifyProduct(system);
            break;
        case 3:
            InterfaceDeleteProduct(system);
            break;
        case 4:
            InterfaceDisplayProduct(system);
            break;
        case 5:
            InterfaceDisplaySortedProduct(system);
            break;
        case 6:
            InterfaceUpdateStock(system);
            break;
        case 7:
            InterfaceSetProductThreshold(system);
            break;
        case 0:
            printf("\nDang thoat...\n");
            break;
        default:
            printf("\nLua chon khong hop le! Vui long thu lai.");
        }
    } while (choice != 0);
}

void InterfaceAddNewProduct(System *system) 
{
    printf("\n--- THEM SAN PHAM MOI ---");
    printf("\n[Thong bao] Da them san pham thanh cong!");
}

void InterfaceModifyProduct(System *system) 
{
    printf("\n--- SUA THONG TIN SAN PHAM ---");
    char id[20];
    printf("\nNhap ma san pham can sua: ");
    scanf("%s", id);
    clearBuffer();
}

void InterfaceDeleteProduct(System *system) 
{
    printf("\n--- XOA SAN PHAM ---");
    char id[20];
    printf("\nNhap ma san pham muon xoa: ");
    scanf("%s", id);
    clearBuffer();
}

void InterfaceDisplayProduct(System *system) 
{
    printf("\n--- DANH SACH SAN PHAM ---\n");
    printf("%-10s | %-20s | %-10s | %-10s\n", "Ma SP", "Ten SP", "Gia", "Ton kho");
}

void InterfaceUpdateStock(System *system) 
{
    printf("\n--- CAP NHAT KHO HANG ---");
}

void InterfaceDisplaySortedProduct(System *system) 
{
    printf("\n--- DANH SACH DA SAP XEP ---");
}

void InterfaceSetProductThreshold(System *system) 
{
    printf("\n--- THIET LAP NGUONG CANH BAO ---");
}
