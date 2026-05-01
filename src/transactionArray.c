#include "../inc/transactionArray.h"
#include "../inc/setting.h"
#include "../inc/utils.h"
#include <stdio.h>
#include <stdlib.h>

transactionArray TransactionArrayInit(unsigned int maxCapacity) {
  transactionArray transaction_array;
  if (maxCapacity < 1) {
    printf("Dude, leave us some space to breath :pray:");
  }
  transaction_array.ptr = (Transaction *)malloc(sizeof(Transaction) * 1);
  if (transaction_array.ptr == NULL) {
    printf("Initial Allocation failed\n");
    transaction_array.currentCapacity = 0;
    transaction_array.capacity = 0;
  } else {

    transaction_array.currentCapacity = 1;
    transaction_array.capacity = maxCapacity;
  }

  transaction_array.count = 0;

  return transaction_array;
}

void TransactionArrayAddTransaction(transactionArray *transaction_array,
                                    unsigned int productID, timeStamp timeStamp,
                                    uint quantity,
                                    unsigned short int isForSelling) {
  int success =
      TransactionArrayAllocate(transaction_array, transaction_array->count + 1);
  if (!success) {
    return;
  }
  transaction_array->ptr[transaction_array->count].productID = productID;
  transaction_array->ptr[transaction_array->count].time_stamp = timeStamp;
  transaction_array->ptr[transaction_array->count].quantity = quantity;
  transaction_array->ptr[transaction_array->count].isForSelling = isForSelling;

  transaction_array->count++;
}

int TransactionArrayAllocate(transactionArray *transaction_array,
                             unsigned int AllocateSlot) {
  // already good to go
  if (transaction_array->currentCapacity >= AllocateSlot) {
    return 1;
  }
  // impossible to allocate
  if (AllocateSlot > transaction_array->capacity) {
    printf("Proposed allocating slots exceeds the maximum slot \n");
    return 0;
  }

  // clamping the allocating slots
  unsigned int new_capacity = transaction_array->currentCapacity * 2;
  new_capacity = uint_max(new_capacity, AllocateSlot);
  new_capacity = uint_min(new_capacity, transaction_array->capacity);

  // passed all the edge cases, now allocating
  Transaction *new_ptr = (Transaction *)realloc(
      transaction_array->ptr, sizeof(Transaction) * new_capacity);

  if (new_ptr == NULL) {
    printf("Failed to allocate the given new_capacity\n");
    return 0;
  }
  transaction_array->ptr = new_ptr;
  transaction_array->currentCapacity = new_capacity;
  return 1;
}
void TranscationArrayFree(transactionArray *transaction_array) {
  free(transaction_array->ptr);
  printf("TransactionArray: freed\n");
}

// ------------------------------------------------------------------------
// testing.c
// // #include "inc/transaction.h"
// #include "inc/systemTime.h"
// #include "inc/transactionArray.h"
// #include <stdio.h>
//
// int main() {
//   transactionArray transaction_array = TransactionArrayInit(10);
//   printf("transaction_array -> ptr: %p \n", transaction_array.ptr);
//   printf("trasaction_array -> count: %d \n", transaction_array.count);
//   printf("trasaction_array -> currentCapacity: %d \n",
//          transaction_array.currentCapacity);
//   printf("trasaction_array -> capacity: %d \n", transaction_array.capacity);
//
//   systemTime time_system;
//   fetchTime(&time_system);
//   timeStamp time_stamp;
//   saveTick(&time_system, &time_stamp);
//
//   TransactionArrayAddTransaction(&transaction_array, 54, time_stamp);
//   printf("\n");
//   printf("transaction_array -> ptr: %p \n", transaction_array.ptr);
//   printf("trasaction_array -> count: %d \n", transaction_array.count);
//   printf("trasaction_array -> currentCapacity: %d \n",
//          transaction_array.currentCapacity);
//   printf("trasaction_array -> capacity: %d \n", transaction_array.capacity);
//
//   TransactionArrayAddTransaction(&transaction_array, 54, time_stamp);
//   printf("\n");
//   printf("transaction_array -> ptr: %p \n", transaction_array.ptr);
//   printf("trasaction_array -> count: %d \n", transaction_array.count);
//   printf("trasaction_array -> currentCapacity: %d \n",
//          transaction_array.currentCapacity);
//   printf("trasaction_array -> capacity: %d \n", transaction_array.capacity);
//
//   TransactionArrayAddTransaction(&transaction_array, 54, time_stamp);
//   printf("\n");
//   printf("transaction_array -> ptr: %p \n", transaction_array.ptr);
//   printf("trasaction_array -> count: %d \n", transaction_array.count);
//   printf("trasaction_array -> currentCapacity: %d \n",
//          transaction_array.currentCapacity);
//   printf("trasaction_array -> capacity: %d \n", transaction_array.capacity);
//
//   TransactionArrayAddTransaction(&transaction_array, 54, time_stamp);
//   printf("\n");
//   printf("transaction_array -> ptr: %p \n", transaction_array.ptr);
//   printf("trasaction_array -> count: %d \n", transaction_array.count);
//   printf("trasaction_array -> currentCapacity: %d \n",
//          transaction_array.currentCapacity);
//   printf("trasaction_array -> capacity: %d \n", transaction_array.capacity);
//
//   TransactionArrayAddTransaction(&transaction_array, 54, time_stamp);
//   printf("\n");
//   printf("transaction_array -> ptr: %p \n", transaction_array.ptr);
//   printf("trasaction_array -> count: %d \n", transaction_array.count);
//   printf("trasaction_array -> currentCapacity: %d \n",
//          transaction_array.currentCapacity);
//   printf("trasaction_array -> capacity: %d \n", transaction_array.capacity);
//
//   printf("\nTesting section: \n");
//   for (unsigned int i = 0; i < transaction_array.count; i++) {
//     Transaction *trans = transaction_array.ptr;
//     printf("ID: %d, year: %d,second: %d\n", trans->productID,
//            trans->time_stamp.year, trans->time_stamp.second);
//   }
//   TranscationArrayFree(&transaction_array);
// }
//
// output:
// ---------------------------------------------------------------------
// transaction_array -> ptr: 0000023E93D97BA0
// trasaction_array -> count: 0
// trasaction_array -> currentCapacity: 1
// trasaction_array -> capacity: 10
//
// transaction_array -> ptr: 0000023E93D97BA0
// trasaction_array -> count: 1
// trasaction_array -> currentCapacity: 1
// trasaction_array -> capacity: 10
//
// transaction_array -> ptr: 0000023E93D91670
// trasaction_array -> count: 2
// trasaction_array -> currentCapacity: 2
// trasaction_array -> capacity: 10
//
// transaction_array -> ptr: 0000023E93D9CA40
// trasaction_array -> count: 3
// trasaction_array -> currentCapacity: 4
// trasaction_array -> capacity: 10
//
// transaction_array -> ptr: 0000023E93D9CA40
// trasaction_array -> count: 4
// trasaction_array -> currentCapacity: 4
// trasaction_array -> capacity: 10
//
// transaction_array -> ptr: 0000023E93D9CA40
// trasaction_array -> count: 5
// trasaction_array -> currentCapacity: 8
// trasaction_array -> capacity: 10
//
// Testing section:
// ID: 54, year: 2026,second: 11
// ID: 54, year: 2026,second: 11
// ID: 54, year: 2026,second: 11
// ID: 54, year: 2026,second: 11
// ID: 54, year: 2026,second: 11
// TransactionArray: freed
