#include "inc/report.h"
#include "inc/system.h"
#include "inc/systemFile.h"
#include "inc/systemInterface.h"
#include <stdio.h>

int main() {
  printf("Hello world\n");
  System system;

  SystemInit(&system);

  uint running = 1;
  uint option = -1;

  systemFileLoadProductArray(&system.system_file_product,
                             &system.product_array);
  systemFileLoadTransactionArray(&system.system_file_transaction,
                                 &system.transaction_array);
  while (running) {
    Interface();
    scanf("%d", &option);
    switch (option) {

    case 0:
      running = 0;
      break;

    case 1:
      SystemAddNewProduct(&system);
      break;

    case 2:
      SystemModifyProduct(&system);
      break;

    case 3:
      SystemDeleteProduct(&system);
      break;

    case 4:
      SystemUpdateStock(&system);
      break;

    case 5:
      SystemDisplayProduct(&system);
      break;

    case 6:
      SystemSearchProductByID(&system);
      break;

    case 7:
      SystemSearchProductByName(&system);
      break;

    case 8:
      SystemLowStockWarning(&system);
      break;

    case 9:
      SystemDisplayTransaction(&system);
      break;

    case 10:
      SystemCalculateProfit(&system);
      break;

    case 11:
      SystemSetLowStockThreshold(&system);
      break;

    case 12:
      SystemDisplayProductByCategories(&system);
      break;

    case 13:
      SystemDisplaySortedProductByAlphabeticOrder(&system);
      break;

    case 14:
      SystemDisplayProductByStock(&system);
      break;

    case 15:
      SystemLogStockAndTransaction(&system);

    default:
      printf("Invalid choice");
      break;
    }
  }
  systemFileSaveProductArray(&system.system_file_product,
                             &system.product_array);
  systemFileSaveTrasanctionArray(&system.system_file_transaction,
                                 &system.transaction_array);

  SystemExit(&system);
}
