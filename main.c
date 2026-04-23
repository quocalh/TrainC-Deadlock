#include "inc/systemTime.h"

#include <stdio.h>
int main() {
  printf("hello world\n");
  printf("hello world another one\n");
  systemTime system_time;

  system_time.now = time(NULL);
  system_time.time = localtime(&system_time.now);
  printf("%d gonna be my year!", system_time.time->tm_year + 1900);
}
