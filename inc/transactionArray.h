#ifndef TRANSACTION_ARRAY_H
#define TRANSACTION_ARRAY_H
#include "../inc/setting.h"
#include "systemTime.h"
#include "transaction.h"

typedef struct {
  Transaction *ptr;

  unsigned int count;
  unsigned int capacity;
  unsigned int currentCapacity;
} transactionArray;

transactionArray TransactionArrayInit(unsigned int maxCapacity);

void TransactionArrayAddTransaction(transactionArray *transaction_array,
                                    unsigned int productID, timeStamp timeStamp,
                                    uint quantity);

int TransactionArrayAllocate(transactionArray *transaction_array,
                             unsigned int AllocateSlot);

void TranscationArrayFree(transactionArray *transaction_array);

#endif
