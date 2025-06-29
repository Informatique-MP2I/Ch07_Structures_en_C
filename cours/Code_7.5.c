#include <stdio.h>
#include <stdlib.h>
typedef struct {
  unsigned int hours;   // number of hours (24 h)
  unsigned int minutes; // number of minutes (60 min)
  double seconds;       // number of seconds (60 s)
} time_s;
typedef struct {
  unsigned int day;
  unsigned int mount;
  int year;
  time_s time;
} day_time_s;
int main(int argc, char **argv) {
  day_time_s day_time = {12,12,2023, {3, 20, 0.023}};
  printf("day_time : %u/%u/%d - %u h %u min %f s.\n",
	 day_time.day, day_time.mount, day_time.year,
	 day_time.time.hours,
	 day_time.time.minutes,
	 day_time.time.seconds);
  return 0;
}
