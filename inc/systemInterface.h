#ifndef SYSTEM_INTERFACE_H
#define SYSTEM_INTERFACE_H

#include "system.h"

typedef struct {

} systemInterface;

void Interface(System *system);
void clearclearBuffer();

void InterfaceAddNewProduct(System *system);
void InterfaceModifyProduct(System *system);
void InterfaceDeleteProduct(System *system);

void InterfaceDisplayProduct(System *system);
void InterfaceUpdateStock(System *system);

void InterfaceSetProductThreshold(System *system);
void InterfaceDisplaySortedProduct(System *system);

#endif
