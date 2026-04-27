#include "../inc/utils.h"

unsigned int uint_max(unsigned int a, unsigned int b) {
  return (a > b) ? a : b;
}
int int_max(int a, int b) { return (a > b) ? a : b; }

unsigned int uint_min(unsigned int a, unsigned int b) {
  return (a < b) ? a : b;
}
int int_min(int a, int b) { return (a < b) ? a : b; }
