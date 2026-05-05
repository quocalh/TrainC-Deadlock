#include "../inc/systemTime.h"

// void fetchTime(systemTime *system_time) {
//   system_time->now = time(NULL);
//   system_time->time = localtime(&system_time->now);
// }
//
// void saveTick(systemTime *system_time, timeStamp *time_stamp) {
//   time_stamp->year = (system_time->time->tm_year) + 1900;
//   time_stamp->month = (system_time->time->tm_mon) + 1;
//   time_stamp->date = (system_time->time->tm_mday);
//   time_stamp->hour = (system_time->time->tm_hour);
//   time_stamp->minute = (system_time->time->tm_min);
//   time_stamp->second = (system_time->time->tm_sec);
// }

void SystemTimeFetchTime(systemTime *system_time) {
  system_time->now = time(NULL);
  system_time->time = *localtime(&system_time->now);
}

void SystemTimeSaveTick(systemTime *system_time, timeStamp *time_stamp) {
  time_stamp->year = (system_time->time.tm_year) + 1900;
  time_stamp->month = (system_time->time.tm_mon) + 1;
  time_stamp->date = (system_time->time.tm_mday);
  time_stamp->hour = (system_time->time.tm_hour);
  time_stamp->minute = (system_time->time.tm_min);
  time_stamp->second = (system_time->time.tm_sec);
}
