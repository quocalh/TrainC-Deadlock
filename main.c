#include "inc/system.h"
#include "inc/systemFile.h"
// #include "inc/systemInterface.h"
#include <stdio.h>

int main() {
  printf("Hello world\n");
  System system;

  SystemInit(&system);

  int running = 1;
  int option = -1;

  systemFileLoadProductArray(&system.system_file_product,
                             &system.product_array);
  systemFileLoadTransactionArray(&system.system_file_transaction,
                                 &system.transaction_array);
  while (running) {
    scanf("%d", &option);
    switch (option) {
      // Interface(&system);

    case -1:
      running = 0;
      break;

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
      break;

    case 7:
      SystemLowStockWarning(&system);
      break;

    case 8:
      break;

    case 9:
      break;

    default:
      break;
    }
  }
  systemFileSaveProductArray(&system.system_file_product,
                             &system.product_array);
  systemFileSaveTrasanctionArray(&system.system_file_transaction,
                                 &system.transaction_array);

  SystemExit(&system);
}
