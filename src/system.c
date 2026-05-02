#include "../inc/system.h"
#include "../inc/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2:
void SystemModifyProduct(System *system) {
  // choose the product
  unsigned int ChosenID;
  printf("Nhap ID vao: ");
  scanf("%d", &ChosenID);
  if (ChosenID >= system->product_array.count) {
    printf("ID khong tim thay\n");
    return;
  }
  Product *ModifyingProduct = &system->product_array.ptr[ChosenID];
  // Change Name:
  char input[100];
  printf("Ten moi (Ten cu: %s): ",
         system->product_array.ptr[ChosenID].ProductName);
  scanf("%s", input);
  if (!(input[0] == '*' && input[1] == '\0')) {
    strcpy(ModifyingProduct->ProductName, input);
  }
  // Change Category
  printf("Loai moi (Loai cu: %s): ",
         system->product_array.ptr[ChosenID].Category);
  scanf("%s", input);
  if (!(input[0] == '*' && input[1] == '\0')) {
    strcpy(ModifyingProduct->Category, input);
  }
  // Change PriceImport
  printf("Gia nhap moi (Gia nhap cu: %ld): ",
         system->product_array.ptr[ChosenID].priceImport);
  scanf("%s", input);
  if (!(input[0] == '*' && input[1] == '\0')) {
    ModifyingProduct->priceImport = atoi(input);
  }
  // Change PriceSelling
  printf("Gia ban moi (Gia ban cu: %ld): ",
         system->product_array.ptr[ChosenID].priceSelling);
  scanf("%s", input);
  if (!(input[0] == '*' && input[1] == '\0')) {
    ModifyingProduct->priceSelling = atoi(input);
  }
  // Change LowStockThreHold
  printf("Nguong canh bao moi (Nguong canh bao cu: %d): ",
         system->product_array.ptr[ChosenID].lowStockThreshold);
  scanf("%s", input);
  if (!(input[0] == '*' && input[1] == '\0')) {
    ModifyingProduct->lowStockThreshold = atoi(input);
  }
  // Print New Change
  printf("ID: %d | Ten: %s | Loai: %s | Gia nhap: %ld | Gia ban: %ld | Nguong "
         "canh bao: %d\n",
         system->product_array.ptr[ChosenID].ProductID,
         system->product_array.ptr[ChosenID].ProductName,
         system->product_array.ptr[ChosenID].Category,
         system->product_array.ptr[ChosenID].priceImport,
         system->product_array.ptr[ChosenID].priceSelling,
         system->product_array.ptr[ChosenID].lowStockThreshold);
}

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
// 5
// Show Display Products
void SystemDisplayProduct(System *system) {
  productArray *product_Array = &system->product_array;
  for (unsigned int i = 0; i < system->product_array.count; i++) {
    printf(
        "ID: %d | Name: %s | Category: %s | PriceImport: %ld | PriceSelling: "
        "%ld | LowStockThreHold: %d\n",
        product_Array->ptr[i].ProductID, product_Array->ptr[i].ProductName,
        product_Array->ptr[i].Category, product_Array->ptr[i].priceImport,
        product_Array->ptr[i].priceSelling,
        product_Array->ptr[i].lowStockThreshold);
  }
}
// 7:
void SystemLowStockWarning(System *system) {
  int options;
  printf("Chon che do hien thi:\n");
  printf("0: Chi hien thi canh bao (Red/Yellow)\n");
  printf("1: Hien thi tat ca (bao gom ca Green)\n");
  printf("Lua chon cua ban: ");
  scanf("%d", &options);
  while (getchar() != '\n')
    if (options != 1 && options != 0) {
      printf("Lua chon khong hop le. Vui long nhap 0 hoac 1.\n");
      while (getchar() != '\n')
        ;
      return;
    }
  unsigned int lowStockCount = 0;
  printf("%-5s | %-20s | %-5s | %-10s | %-10s\n", "ID", "Ten San Pham",
         "Ton Kho", "Dinh Muc", "Trang Thai");
  for (uint i = 0; i < system->product_array.count; i++) {
    Product *p = &(system->product_array.ptr[i]);
    if (p->isDeleted)
      continue;
    if (p->quantity < p->lowStockThreshold) {
      printf("%-5d | %-20s | %-5lu | %-10u | ", p->ProductID, p->ProductName,
             p->quantity, p->lowStockThreshold);
      printf("red\n");
      lowStockCount++;
    } else if (p->quantity == p->lowStockThreshold) {
      printf("%-5d | %-20s | %-5lu | %-10u | ", p->ProductID, p->ProductName,
             p->quantity, p->lowStockThreshold);
      printf("yellow\n");
      lowStockCount++;
    } else if (options == 1) {
      printf("%-5d | %-20s | %-5lu | %-10u | ", p->ProductID, p->ProductName,
             p->quantity, p->lowStockThreshold);
      printf("green\n");
    }
  }
  printf("Tong so san pham sap het hang: %u\n", lowStockCount);
  printf("\n");
}
// 11:
void SystemSetLowStockThreshold(System *system) {
  unsigned int targetID;
  printf("Nhap ID san pham ban muon thay doi nguong canh bao: ");
  if (scanf("%u", &targetID) != 1) {
    printf("ID khong hop le\n");
    while (getchar() != '\n')
      ;
    return;
  }
  productArray *pArray = &(system->product_array);
  int targetIndex = -1;
  for (uint i = 0; i < pArray->count; i++) {
    if (pArray->ptr[i].ProductID == targetID && pArray->ptr[i].isDeleted == 0) {
      targetIndex = i;
      break;
    }
  }
  if (targetIndex == -1) {
    printf("Khong tim thay san pham hoac san pham da bi xoa.\n");
    return;
  }
  printf("San pham tim thay: %s\n", pArray->ptr[targetIndex].ProductName);
  printf("Nguong canh bao hien tai: %u\n",
         pArray->ptr[targetIndex].lowStockThreshold);
  unsigned int newThreshold;
  printf("Nhap nguong canh bao moi: ");
  if (scanf("%u", &newThreshold) != 1) {
    printf("Gia tri nguong khong hop le\n");
    while (getchar() != '\n')
      ; // này để xóa ký tự còn lại trong buffer
    return;
  }
  pArray->ptr[targetIndex].lowStockThreshold = newThreshold;
  printf("Nguong canh bao cho san pham ten '%s' thanh %u \n",
         pArray->ptr[targetIndex].ProductName, newThreshold);
}
// 13
int SystemDisplaySortedProductByAlphabeticOrder(System *system) {
  // uint is_reversed = 0;
  uint count = system->product_array.count;
  unsigned int *ptr =
      malloc(sizeof(unsigned int) * system->product_array.count);

  if (ptr == NULL) {
    printf("Failed to allocate slots\n");
    return 0;
  }

  for (uint i = 0; i < count; i++) {
    ptr[i] = i;
  }

  for (uint i = 0; i < count; i++) {
    for (uint j = i + 1; j < count; j++) {
      char *str1 = system->product_array.ptr[ptr[i]].ProductName;
      char *str2 = system->product_array.ptr[ptr[j]].ProductName;

      if (strcasecmp(str1, str2) > 0) {
        swap_heap(&ptr[i], &ptr[j], sizeof(unsigned int));
      }
    }
  }
  for (uint i = 0; i < system->product_array.count; i++) {
    char *bijection_string = system->product_array.ptr[ptr[i]].ProductName;
    printf("%s\n", bijection_string);
  }
  return 1;
}
