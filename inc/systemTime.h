#ifndef SYSTEM_TIME_H
#define SYSTEM_TIME_H

#include <time.h>

typedef struct {
  time_t now;
  struct tm *time;
  int year;
  int month;
  int date;
  int hour;
  int minute;
  int second;
} systemTime;

void fetchTime(systemTime *system_time);

int systemTime_getCurrentYear(systemTime *system_time); 
int systemTime_getCurrentMonth(systemTime *system_time);
int systemTime_getCurrentDate(systemTime *system_time);

int systemTime_getCurrentHour(systemTime *system_time);
int systemTime_getCurrentMinute(systemTime *system_time);
int systemTime_getCurrentSecond(systemTime *system_time);

#endif
