#include "../inc/system.h"
#include "../inc/setting.h"
#include "../inc/systemColoring.h"
#include "../inc/systemFile.h"
#include "../inc/transactionArray.h"
#include "../inc/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SystemInit(System *system) {
  system->product_array = productArrayInit(PRODUCT_ARRAY_MAX_CAPACITY);
  system->transaction_array =
      TransactionArrayInit(TRANSACTION_ARRAY_MAX_CAPACITY);

  strcpy(system->system_file_product.fileName, "io/product.dat");
  strcpy(system->system_file_product.fileNameTemp, "io/.temp");

  strcpy(system->system_file_transaction.fileName, "io/transaction.dat");
  strcpy(system->system_file_transaction.fileNameTemp, "io/.temp");

  strcpy(system->system_file_report.fileName, "io/report.txt");
  strcpy(system->system_file_report.fileNameTemp, "io/.temp");
}

void SystemExit(System *system) {
  productArrayFree(&system->product_array);
  TransactionArrayFree(&system->transaction_array);
}

// 1
void SystemAddNewProduct(System *system) {
  unsigned int QuanityofProduct;
  printf("Enter the Quanity of New Product: ");
  scanf("%u", &QuanityofProduct);

  for (uint i = 0; i < QuanityofProduct; i++) {
    char productName[100];
    printf("Enter the new product name: ");
    scanf(" %[^\n]", productName);

    char Category[100];
    printf("Enter product category: ");
    scanf(" %[^\n]", Category);

    int quantity;
    printf("Enter the quantity of products: ");
    scanf("%d", &quantity);

    unsigned long int priceImport;
    printf("Enter entry price: ");
    scanf("%lu", &priceImport);

    unsigned long int priceSelling;
    printf("Enter the selling price: ");
    scanf("%lu", &priceSelling);

    unsigned int lowStockThreshold;
    printf("Enter the lowStockThreshold: ");
    scanf("%u", &lowStockThreshold);

    printf("Added successfully!\n");

    productArrayAddProduct(&system->product_array, productName, Category,
                           quantity, priceImport, priceSelling,
                           lowStockThreshold, 0);
    printf("count: %d\n", system->product_array.count);
    systemFileAppendProduct(
        &system->system_file_product,
        &system->product_array.ptr[system->product_array.count - 1]);
  }
}

// 2:
void SystemModifyProduct(System *system) {
  unsigned int ChosenID;
  printf("Nhap ID vao: ");
  scanf("%u", &ChosenID);

  // clear buffer sau khi nhập số
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;

  if (ChosenID >= system->product_array.count) {
    printf("ID khong tim thay\n");
    return;
  }

  Product *ModifyingProduct = &system->product_array.ptr[ChosenID];
  char input[100];

  // Change Name
  printf("Ten moi (Ten cu: %s): ", ModifyingProduct->ProductName);
  scanf(" %99[^\n]", input);
  if (!(input[0] == '*' && input[1] == '\0')) {
    strcpy(ModifyingProduct->ProductName, input);
  }

  // Change Category
  printf("Loai moi (Loai cu: %s): ", ModifyingProduct->Category);
  scanf(" %99[^\n]", input);
  if (!(input[0] == '*' && input[1] == '\0')) {
    strcpy(ModifyingProduct->Category, input);
  }

  // Change PriceImport
  printf("Gia nhap moi (Gia nhap cu: %ld): ", ModifyingProduct->priceImport);
  scanf(" %99s", input);
  if (!(input[0] == '*' && input[1] == '\0')) {
    ModifyingProduct->priceImport = atol(input);
  }

  // Change PriceSelling
  printf("Gia ban moi (Gia ban cu: %ld): ", ModifyingProduct->priceSelling);
  scanf(" %99s", input);
  if (!(input[0] == '*' && input[1] == '\0')) {
    ModifyingProduct->priceSelling = atol(input);
  }

  // Change LowStockThreshold
  printf("Nguong canh bao moi (Nguong cu: %d): ",
         ModifyingProduct->lowStockThreshold);
  scanf(" %99s", input);
  if (!(input[0] == '*' && input[1] == '\0')) {
    ModifyingProduct->lowStockThreshold = atoi(input);
  }

  // Print result
  printf("ID: %d | Ten: %s | Loai: %s | Gia nhap: %ld | Gia ban: %ld | Nguong "
         "canh bao: %d\n",
         ModifyingProduct->ProductID, ModifyingProduct->ProductName,
         ModifyingProduct->Category, ModifyingProduct->priceImport,
         ModifyingProduct->priceSelling, ModifyingProduct->lowStockThreshold);

  // File save the changes
  systemFileModifyProduct(&system->system_file_product,
                          &system->product_array.ptr[ChosenID]);
}

// 3:
void SystemDeleteProduct(System *system) {
  if (system == NULL)
    return;

  uint productID;
  printf("Dien vao ID san pham muon xoa: ");
  scanf("%u", &productID);

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
  printf("Da danh dau het hang san pham ID %d thanh cong.\n", productID);

  // systemFileMarkDeleteProduct(&system->system_file_product,
  //                             &system->product_array.ptr[productID]);
  systemFileModifyProduct(&system->system_file_product,
                          &system->product_array.ptr[productID]);
}

// 4:
void SystemUpdateStock(System *system) {
  uint productID;
  printf("Nhap vao ID cua san pham: ");
  scanf("%u", &productID);

  if (productID >= system->product_array.count) {
    printf("Khong tim thay san pham voi ID %u trong he thong.\n", productID);
    return;
  }

  if (system->product_array.ptr[productID].isDeleted == 1) {
    printf("San pham voi ID %d nay hien khong con ban he thong.\n", productID);
  }

  SystemTimeFetchTime(&system->system_time);
  timeStamp time_stamp;
  SystemTimeSaveTick(&system->system_time, &time_stamp);

  uint isForSelling;
  char respond;
  printf("San pham nay la ban (y) hay nhap (n)? (y/n): ");
  scanf(" %c", &respond);

  if (respond == 'y' || respond == 'Y') {
    isForSelling = 1;
  } else if (respond == 'n' || respond == 'N') {
    isForSelling = 0;
  } else {
    printf("Khong hieu\n");
    return;
  }

  uint quantity;
  printf("So luong: ");
  scanf("%u", &quantity);

  if (isForSelling == 1 &&
      system->product_array.ptr[productID].quantity < quantity) {
    printf("Hien khong co du san pham\n");
    return;
  }

  TransactionArrayAddTransaction(&system->transaction_array, productID,
                                 time_stamp, quantity, isForSelling);
  Transaction transaction = {productID, quantity, time_stamp, isForSelling};
  systemFileAppendTransaction(&system->system_file_transaction, &transaction);

  if (isForSelling == 1) {
    system->product_array.ptr[productID].quantity -= quantity;
  } else {
    system->product_array.ptr[productID].quantity += quantity;
  }
  // to change the quantity
  systemFileModifyProduct(&system->system_file_product,
                          &system->product_array.ptr[productID]);
}

// 5
void SystemDisplayProduct(System *system) {
  productArray *product_Array = &((*system).product_array);
  printf("\n-------------------------------------------------------------------"
         "------------------------------------------\n");
  printf("%-5s | %-30s | %-25s | %-12s | %-12s | %-8s\n", "ID", "Name",
         "Category", "PriceImport", "PriceSelling", "Threshold");
  printf("\n-------------------------------------------------------------------"
         "------------------------------------------\n");
  for (unsigned int i = 0; i < (*product_Array).count; i++) {
    printf(
        "%-5d | %-30s | %-25s | %-12ld | %-12ld | %-8d\n",
        (*product_Array).ptr[i].ProductID, (*product_Array).ptr[i].ProductName,
        (*product_Array).ptr[i].Category, (*product_Array).ptr[i].priceImport,
        (*product_Array).ptr[i].priceSelling,
        (*product_Array).ptr[i].lowStockThreshold);
  }
  printf("\n-------------------------------------------------------------------"
         "------------------------------------------\n");
}

// 6
void SystemSearchProductByID(System *system) {
  uint productID;
  printf("Nhap ID san pham can tim: ");
  scanf("%d", &productID);

  if (productID >= system->product_array.count - 1) {
    printf("Hien khong co san pham voi so ID tuong xung\n");
    return;
  }

  Product *product = &system->product_array.ptr[productID];
  printf("ID: %d | Name: %s | Category: %s | PriceImport: %ld | "
         "PriceSelling: %ld | LowStockThreHold: %d\n",
         product->ProductID, product->ProductName, product->Category,
         product->priceImport, product->priceSelling,
         product->lowStockThreshold);
}

void SystemSearchProductByName(System *system) {
  char search_string[MAX_STRING_LENGTH];

  printf("Nhap ten san pham can tim: ");
  scanf(" %[^\n]", search_string);

  printf("Ket qua tim kiem:\n");

  int found = 0;
  int len_search = strlen(search_string);

  for (uint i = 0; i < system->product_array.count; i++) {
    Product *product = &system->product_array.ptr[i];

    int index = string_search(search_string, product->ProductName, len_search,
                              strlen(product->ProductName));

    if (index != -1) {
      found = 1;

      printf("ID: %d | Name: %s | Category: %s | PriceImport: %ld | "
             "PriceSelling: %ld | LowStockThreHold: %d\n",
             product->ProductID, product->ProductName, product->Category,
             product->priceImport, product->priceSelling,
             product->lowStockThreshold);

      highlighting(COLOR_RED, search_string, product->ProductName, len_search,
                   strlen(product->ProductName), index);
      printf("\n");
    }
  }

  if (!found) {
    printf("Khong tim thay san pham nao!\n");
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

// 9
void SystemDisplayTransaction(System *system) {
  unsigned int ChosenID;
  printf("Nhap ID vao: ");
  scanf("%d", &ChosenID);
  if (ChosenID >= system->transaction_array.count) {
    printf("ID khong tim thay\n");
    return;
  }
  for (uint i = 0; i < system->transaction_array.count; i++) {

    if (system->transaction_array.ptr[i].productID == ChosenID) {
      Transaction *t = &system->transaction_array.ptr[i];
      printf("ID: %u | Quanity: %u | Type: %s | Time: %04u-%02u-%02u "
             "%02u:%02u:%02u\n",
             t->productID, t->quantity, t->isForSelling ? "Selling" : "Buying",
             t->time_stamp.year, t->time_stamp.month, t->time_stamp.date,
             t->time_stamp.hour, t->time_stamp.minute, t->time_stamp.second);
    }
  }
}

// 10:
void SystemCalculateProfit(System *system) {
  int sum_profit;
  sum_profit = 0;
  for (uint i = 0; i < system->transaction_array.count; i++) {
    Transaction *transaction = &system->transaction_array.ptr[i];
    Product *product = &system->product_array.ptr[transaction->productID];
    unsigned long int Sell = product->priceSelling;
    unsigned long int Import = product->priceImport;
    if (transaction->isForSelling == 1) {
      // Caculate profit when selling product
      sum_profit += (Sell - Import) * (transaction->quantity);
    } else {
      // Caculate profit when import product
      sum_profit -= Import * (transaction->quantity);
    }
  }
  printf("Profit = %d\n", sum_profit);
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

  systemFileModifyProduct(&system->system_file_product,
                          &system->product_array.ptr[targetID]);
}

// 12:
int SystemDisplayProductByCategories(System *system) {
  uint count = system->product_array.count;
  uint *sort_ptr = malloc(count * sizeof(unsigned int));
  if (sort_ptr == NULL) {
    printf("Failed to allocate slots\n");
    return 0;
  }
  // bijection access
  for (uint i = 0; i < count; i++) {
    sort_ptr[i] = i;
  }

  // perform selection sort
  for (uint i = 0; i < count; i++) {
    for (uint j = i + 1; j < count; j++) {
      char *str1 = system->product_array.ptr[sort_ptr[i]].Category;
      char *str2 = system->product_array.ptr[sort_ptr[j]].Category;
      if (strcasecmp(str1, str2) > 0) {
        swap_heap(sort_ptr + i, sort_ptr + j, sizeof(unsigned int));
      }
    }
  }
  for (uint i = 0; i < system->product_array.count; i++) {
    char *bijection_string = system->product_array.ptr[sort_ptr[i]].Category;
    printf("%s\n", bijection_string);
  }
  free(sort_ptr);
  return 1;
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
  free(ptr);
  return 1;
}

// 13.1
int SystemDisplayProductByStock(System *system) {
  int options;
  printf("Chon che do hien thi:\n");
  printf("0: hien thi san pham co ton kho thap den cao\n");
  printf("1: hien thi san pham co ton kho cao den thap\n");
  printf("Lua chon cua ban: ");
  scanf("%d", &options);
  while (getchar() != '\n')
    ;
  if (options != 1 && options != 0) {
    printf("Lua chon khong hop le. Vui long nhap 0 hoac 1.\n");
    while (getchar() != '\n')
      ;
    return 0;
  }
  uint count = system->product_array.count;
  uint *sort_ptr = malloc(count * sizeof(unsigned int));
  if (sort_ptr == NULL) {
    printf("Failed to allocate slots\n");
    return 0;
  }

  for (uint i = 0; i < count; i++) {
    sort_ptr[i] = i;
  }

  for (uint i = 0; i < count; i++) {
    for (uint j = i + 1; j < count; j++) {
      uint stock1 = system->product_array.ptr[sort_ptr[i]].quantity;
      uint stock2 = system->product_array.ptr[sort_ptr[j]].quantity;
      switch (options) {
      case 0:
        if (stock1 > stock2) {
          swap_heap(sort_ptr + i, sort_ptr + j, sizeof(unsigned int));
        }
        break;
      case 1:
        if (stock1 < stock2) {
          swap_heap(sort_ptr + i, sort_ptr + j, sizeof(unsigned int));
        }
        break;
      default:
        break;
      }
    }
  }
  printf("%-20s | %-10s\n", "Ten San Pham", "Ton Kho");
  for (uint i = 0; i < system->product_array.count; i++) {
    char *name = system->product_array.ptr[sort_ptr[i]].ProductName;
    uint qtt = system->product_array.ptr[sort_ptr[i]].quantity;
    printf("%-20s | %-10u\n", name, qtt);
  }
  free(sort_ptr);
  return 1;
}
