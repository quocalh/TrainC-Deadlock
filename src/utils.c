#include "../inc/utils.h"
#include "../inc/systemColoring.h"

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned int uint_max(unsigned int a, unsigned int b) {
  return (a > b) ? a : b;
}
int int_max(int a, int b) { return (a > b) ? a : b; }

unsigned int uint_min(unsigned int a, unsigned int b) {
  return (a < b) ? a : b;
}
int int_min(int a, int b) { return (a < b) ? a : b; }

void swap_stack(void *a, void *b, size_t size) {
  void *tmp = alloca(size);

  memcpy(tmp, a, size);
  memcpy(a, b, size);
  memcpy(b, tmp, size);

  // im not sure whether should i free the stack though
  // the fooking document said no though
  // free(tmp);
}

uint swap_heap(void *a, void *b, size_t size) {
  void *tmp = malloc(size);
  if (!tmp) {
    printf("failed to allcoate heap space\n");
    return 0;
  }

  memcpy(tmp, a, size);
  memcpy(a, b, size);
  memcpy(b, tmp, size);

  free(tmp);
  return 1;
}

// return 0 if not found, 1 otherwise
int str_cmp(char *search, char *str, unsigned int p,
            unsigned int comparing_length) {
  for (unsigned int i = 0; i < comparing_length; i++) {
    if (str[p + i] != search[i]) {
      return 0;
    }
  }
  return 1;
}

// highlightinng words: e.g. "hello world world" => word world is highlighted if
// the keyword is world
void highlighting(char *color, char *keyword, char *str, uint l_s, uint l_str,
                  uint start) {
  if (l_str < l_s) {
    return;
  }
  if (l_s == 0) {
    printf("%s", str);
    return;
  }
  uint p = start;
  while (p < l_str) {
    if ((p <= l_str - l_s) && str_cmp(keyword, str, p, l_s)) {
      printf("%s", color);
      printf("%s", keyword);
      printf("%s", COLOR_NORMAL);
      p += l_s;
    } else {
      printf("%c", str[p]);
      p++;
    }
  }
}

// return the first apprearance index, return a -1 if search_string not found
int string_search(char *search, char *str, uint l_s, uint l_str) {
  uint p = 0;

  while (p <= l_str - l_s) {
    if (str_cmp(search, str, p, l_s)) {
      return p;
    }
    p++;
  }
  return -1;
}

float QuantitySortingEvaluatingScores(uint quantity, uint threshold) {
  if (threshold == 1) {
    printf("zamn\n");
    return 1;
  }
  return (quantity - threshold) / (float)threshold;
}
