#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "systemTime.h"

typedef struct {
  unsigned int productID;
  timeStamp time_stamp;
} Transaction;

#endif
