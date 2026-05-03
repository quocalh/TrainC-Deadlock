#include "../inc/utils.h"
#include "../inc/systemColoring.h"

#include <ctype.h>
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
    if (tolower(str[p + i]) != tolower(search[i])) {
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
      for (uint i = 0; i < strlen(keyword); i++) {
        printf("%c", str[p + i]);
      }
      printf("%s", COLOR_NORMAL);
      p += l_s;
    } else {
      printf("%c", str[p]);
      p++;
    }
  }
}

void string_highlighting(char *color, char *keyword, char *str, uint l_s,
                         uint l_str, uint start, char *return_str) {
  if (l_str < l_s || l_s == 0) {
    strcpy(return_str, str);
    return;
  }

  uint p = start;
  uint i = 0;

  for (; i < p; i++) {
    return_str[i] = str[i];
  }

  while (p < l_str) {
    if ((p <= l_str - l_s) && str_cmp(keyword, str, p, l_s)) {
      // the color code
      for (int j = 0; color[j] != '\0'; j++) {
        return_str[i++] = color[j];
      }
      // real content
      for (uint j = 0; j < l_s; j++) {
        return_str[i++] = str[p + j];
      }

      // the reset code
      for (int j = 0; COLOR_NORMAL[j] != '\0'; j++) {
        return_str[i++] = COLOR_NORMAL[j];
      }

      p += l_s;
    } else {
      return_str[i++] = str[p++];
    }
  }

  return_str[i] = '\0';
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

void *AlphabeticSort(unsigned int l, char str_array[][l], unsigned int count) {
  // dynamic array heap address return
  char **ptr = malloc(sizeof(void *) * count);

  if (ptr == NULL) {
    printf("Failed to allocate slots\n");
    return NULL;
  }
  // if successfully allocated a sufficient heap array, fill it with bijection
  // address
  for (uint i = 0; i < count; i++) {
    ptr[i] = str_array[i];
  }

  // sorting we will see
  for (uint i = 0; i < count; i++) {
    for (uint j = i + 1; j < count; j++) {
      char *str1 = str_array[i];
      char *str2 = str_array[j];
      if (strcasecmp(str1, str2) > 0) {
        swap_stack(str1, str2, l);
      }
    }
  }
  printf("---sorted-----\n");
  for (uint i = 0; i < count; i++) {
    char *bijection_string = ptr[i];
    printf("%s\n", bijection_string);
  }

  return ptr;
}
// Use
// char what_the_hell[][50] = {
//       "apple",      "Banana",     "APPLE",      "banana",     "Apricot",
//       "apricot",    "Cherry",     "cherry",     "blueberry",  "BlueBerry",
//       "grape",      "Grape",      "grapefruit", "Grapefruit", "kiwi",
//       "KiWi",       "lemon",      "Lemon",      "lime",       "Lime",
//       "mango",      "Mango",      "melon",      "Melon",      "nectarine",
//       "Nectarine",  "orange",     "Orange",     "peach",      "Peach",
//       "pear",       "Pear",       "pineapple",  "PineApple",  "plum",
//       "Plum",       "raspberry",  "Raspberry",  "strawberry", "Strawberry",
//       "watermelon", "WaterMelon", "fig",        "Fig",        "date",
//       "Date",       "papaya",     "Papaya",     "guava",      "Guava"};
//
//   unsigned int *output_array = AlphabeticSort(50, what_the_hell, 50);
//
//   free(output_array);
