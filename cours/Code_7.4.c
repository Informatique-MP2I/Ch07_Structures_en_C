#include <stdio.h>
typedef struct {
  unsigned int hours;   // number of hours (24 h)
  unsigned int minutes; // number of minutes (60 min)
  double seconds;       // number of seconds (60 s)
} time_s;
time_s add_three_hours(time_s t){
  t.hours = (t.hours + 3)%24;
  return t;
}
int main(int argc, char **argv) {
  time_s time = {3, 20, 0.023};
  time_s res;
  printf("time : %u h %u min %f s.\n",
	 time.hours, time.minutes, time.seconds);
  res=add_three_hours(time);
  printf("time : %u h %u min %f s.\n",
	 time.hours, time.minutes, time.seconds);
  printf("res  : %u h %u min %f s.\n",
	 res.hours, res.minutes, res.seconds);
  return 0;
}
