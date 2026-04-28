#include "../inc/transactionArray.h"
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
                                    unsigned int productID,
                                    timeStamp timeStamp) {
  int success =
      TransactionArrayAllocate(transaction_array, transaction_array->count + 1);
  if (!success) {
    return;
  }
  transaction_array->ptr[transaction_array->count].productID = productID;
  transaction_array->ptr[transaction_array->count].time_stamp = timeStamp;
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
