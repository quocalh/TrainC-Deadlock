#ifndef SYSTEM_TIME_H
#define SYSTEM_TIME_H

#include <time.h>
typedef struct {
  time_t now;
  struct tm *time;
} systemTime;

typedef struct {
  time_t now;
  struct tm *time;
  int year;
  int month;
  int date;
  int hour;
  int minute;
  int second;
} timeStamp;

void fetchTime(systemTime *system_time);
void saveTick(systemTime *system_time, timeStamp *time_stamp);

// int systemTime_getCurrentYear(systemTime *system_time, timeStamp *time_stamp);
// int systemTime_getCurrentMonth(systemTime *system_time, timeStamp *time_stamp);
// int systemTime_getCurrentDate(systemTime *system_time, timeStamp *time_stamp);

// int systemTime_getCurrentHour(systemTime *system_time, timeStamp *time_stamp);
// int systemTime_getCurrentMinute(systemTime *system_time, timeStamp *time_stamp);
// int systemTime_getCurrentSecond(systemTime *system_time, timeStamp *time_stamp);

#endif
