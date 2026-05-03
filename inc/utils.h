#ifndef UTILS_H
#define UTILS_H

#include "setting.h"
#include <stdio.h>

uint uint_max(unsigned int a, unsigned int b);

int int_max(int a, int b);

uint uint_min(unsigned int a, unsigned int b);

int int_min(int a, int b);

// use it wisely :pray:
void swap_stack(void *a, void *b, size_t size);

uint swap_heap(void *a, void *b, size_t size);

// string search, naive
int str_cmp(char *search, char *str, unsigned int p,
            unsigned int comparing_length);

int string_search(char *search, char *str, uint l_s, uint l_str);

void highlighting(char *color, char *keyword, char *str, uint l_s, uint l_str,
                  uint start);
void string_highlighting(char *color, char *keyword, char *str, uint l_s,
                         uint l_str, uint start, char *return_str);
// alphabet sorting
// strcasecmp should do the trick

// quantity s
float QuantitySortingEvaluatingScores(uint quantity, uint threshold);

#endif
