#include "../inc/system.h"
#include <stdio.h>

// 3:
void SystemDeleteProduct(System *system, unsigned int productID) {
  if (system == NULL)
    return;
  productArray *pArray = &(system->product_array);
  int targetIndex = -1;
  for (unsigned int i = 0; i < pArray->count; i++) {
    if (pArray->ptr[i].ProductID == productID &&
        pArray->ptr[i].isDeleted == 0) {
      targetIndex = i;
      break;
    }
  }
  if (targetIndex == -1) {
    printf("Khong tim thay san pham ID: %d\n", productID);
    return;
  }
  if (pArray->ptr[targetIndex].quantity != 0) {
    printf("Loi: San pham '%s' van con ton kho (%lu). Khong duoc phep xoa!\n",
           pArray->ptr[targetIndex].ProductName,
           pArray->ptr[targetIndex].quantity);
    return;
  }
  char confirm;
  printf("Xac nhan xoa '%s' (ID: %d)? (y/n): ",
         pArray->ptr[targetIndex].ProductName, productID);
  scanf(" %c", &confirm);
  if (confirm != 'y' && confirm != 'Y') {
    printf("Huy thao tac xoa.\n");
    return;
  }
  printf("CANH BAO: Du lieu se bi danh dau xoa vinh vien. Chac chan? (y/n): ");
  scanf(" %c", &confirm);
  if (confirm != 'y' && confirm != 'Y') {
    printf("Huy thao tac xoa o buoc cuoi.\n");
    return;
  }
  pArray->ptr[targetIndex].isDeleted = 1;
  printf("Da xoa san pham ID %d thanh cong.\n", productID);
}

// 4:
void SystemUpdateStock(System *system, unsigned int productID,
                       unsigned int quantityChange, int type) {
  int found = 0;
  for (unsigned int i = 0; i < (*system).product_array.count; i++) {
    if (system->product_array.ptr[i].ProductID == productID) {
      found = 1;
      if (type == 1) {
        (*system).product_array.ptr[i].quantity +=
            (unsigned long)quantityChange;
        printf("Da nhap %d vao ID %d.\n", quantityChange, productID);
      } else if (type == 2) {
        if ((*system).product_array.ptr[i].quantity >=
            (unsigned long)quantityChange) {
          (*system).product_array.ptr[i].quantity -=
              (unsigned long)quantityChange;
          printf("Da xuat %d tu ID %d.\n", quantityChange, productID);
          if ((*system).product_array.ptr[i].quantity <=
              (*system).product_array.ptr[i].lowStockThreshold) {
            printf("!!! CANH BAO: San pham '%s' sap het hang (Con lai: %lu)\n",
                   (*system).product_array.ptr[i].ProductName,
                   (*system).product_array.ptr[i].quantity);
          }
        } else {
          printf("Khong du hang! Trong kho chi con %lu.\n",
                 (*system).product_array.ptr[i].quantity);
        }
      }
      break;
    }
  }
  if (found == 0) {
    printf("Khong tim thay ID %d trong he thong.\n", productID);
  }
}
