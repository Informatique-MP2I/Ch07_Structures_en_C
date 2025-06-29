#include <stdio.h>
struct time {
  unsigned int hours;   // number of hours (24 h)
  unsigned int minutes; // number of minutes (60 min)
  double seconds;       // number of seconds (60 s)
};
int main(int argc, char **argv) {
  // First struct time variable
  struct time time1;
  time1.hours = 15;
  time1.minutes = 54;
  time1.seconds = 4.6;
  printf("time1 : %u h %u min %f s.\n",
	 time1.hours, time1.minutes, time1.seconds);
  // Second struct time variable
  struct time time2 = {
    .hours = 8,
    .minutes = 13,
    .seconds = 56.2
  };
  printf("time2 : %u h %u min %f s.\n",
	 time2.hours, time2.minutes, time2.seconds);
  // Third struct time variable
  struct time time3 = {11,54,23.967};
  printf("time3 : %u h %u min %f s.\n",
	 time3.hours, time3.minutes, time3.seconds);
  // Modification
  time3.minutes = 15;
  printf("time3 : %u h %u min %f s.\n",
	 time3.hours, time3.minutes, time3.seconds);
  return 0;
}
