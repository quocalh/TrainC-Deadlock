#ifndef SYSTEM_TIME_H
#define SYSTEM_TIME_H

#include <time.h>
typedef struct {
  time_t now;
  struct tm time;
} systemTime;

typedef struct {
  unsigned int year;
  unsigned int month;
  unsigned int date;
  unsigned int hour;
  unsigned int minute;
  unsigned int second;
} timeStamp;

// void fetchTime(systemTime *system_time);
// void saveTick(systemTime *system_time, timeStamp *time_stamp);

void SystemTimeFetchTime(systemTime *system_time);
void SystemTimeSaveTick(systemTime *system_time, timeStamp *time_stamp);

#endif
