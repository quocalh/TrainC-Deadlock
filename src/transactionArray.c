#include "../inc/transactionArray.h"
#include "../inc/utils.h"
#include <stdio.h>
#include <stdlib.h>

transactionArray TransactionArrayInit(unsigned int maxCapacity) {
  transactionArray transaction_array;

  transaction_array.ptr = NULL;
  transaction_array.currentCapacity = 0;
  transaction_array.capacity = maxCapacity;

  return transaction_array;
}
void TransactionArrayAddTransaction(transactionArray *transaction_array,
                                    unsigned int productID,
                                    timeStamp timeStamp) {
  TransactionArrayAllocate(transaction_array, transaction_array->count + 1);

  transaction_array->ptr[transaction_array->count].productID = productID;
  transaction_array->ptr[transaction_array->count].time_stamp =
      timeStamp; // BUG BUG BUG BUG BUG
  // test this shit bro
  transaction_array->count++;
}

void TransactionArrayAllocate(transactionArray *transaction_array,
                              unsigned int AllocateSlot) {
  unsigned int new_capacity = 0;
  // out of free slot, need to allocate more
  if (AllocateSlot >= transaction_array->currentCapacity) {
    unsigned int new_capacity = uint_min(transaction_array->capacity,
                                         transaction_array->currentCapacity);
    new_capacity = uint_max(new_capacity, AllocateSlot);
    if (new_capacity >= transaction_array->capacity) {
      printf("what the hell\n");
      return;
    }
  }
  // else (general case), skip the function, since the allocate slot is lower
  // than what we have got
  else {
    return;
  }

  // start to realloc, with the size of the new_capacity
  Transaction *new_ptr = (Transaction *)realloc(
      transaction_array->ptr, sizeof(Transaction) * new_capacity);
  if (new_ptr == NULL) {
    printf("whut the hell 2\n");
    return;
  }
  transaction_array->ptr = new_ptr;
  transaction_array->capacity = new_capacity;
}
