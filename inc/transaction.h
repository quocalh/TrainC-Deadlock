#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "systemTime.h"

typedef struct {
  unsigned int productID;
  unsigned int quantity;
  timeStamp time_stamp;
  unsigned short int isForSelling;
} Transaction;

#endif
