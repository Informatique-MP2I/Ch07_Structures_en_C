#include <stdio.h>
typedef struct {
  unsigned int hours;   // number of hours (24 h)
  unsigned int minutes; // number of minutes (60 min)
  double seconds;       // number of seconds (60 s)
} time_s;
void add_three_hours(time_s *t){
  // (*t).hours = ((*t).hours + 3)%24;
  t->hours = (t->hours +3)%24;
  return;
}
int main(int argc, char **argv) {
  time_s time = {3, 20, 0.023};
  printf("time : %u h %u min %f s.\n",
	 time.hours, time.minutes, time.seconds);
  add_three_hours(&time);
  printf("time : %u h %u min %f s.\n",
	 time.hours, time.minutes, time.seconds);
  return 0;
}
