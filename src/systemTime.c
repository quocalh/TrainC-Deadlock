#include "../inc/systemTime.h"

void fetchTime(systemTime *system_time) {
  system_time->now = time(NULL);
  system_time->time = localtime(&system_time->now);

  system_time->year = (system_time->time->tm_year) + 1900;
  system_time->month = (system_time->time->tm_mon) + 1;
  system_time->month = (system_time->time->tm_mday);
  system_time->month = (system_time->time->tm_hour);
  system_time->month = (system_time->time->tm_min);
  system_time->month = (system_time->time->tm_sec);
}
int systemTime_getCurrentYear(systemTime *system_time) {
  return system_time->year + 1900;
}
int systemTime_getCurrentMonth(systemTime *system_time) {
  return system_time->month + 1;
}
int systemTime_getCurrentDate(systemTime *system_time) {
  return system_time->date;
}
int systemTime_getCurrentHour(systemTime *system_time) {
  return system_time->hour;
}
int systemTime_getCurrentMinute(systemTime *system_time) {
  return system_time->minute;
}
int systemTime_getCurrentSecond(systemTime *system_time) {
  return system_time->second;
}
