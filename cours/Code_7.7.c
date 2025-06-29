int main(int argc, char **argv) {
  time_s *time = (time_s *)malloc(sizeof(time_s));
  if(time == NULL) return 1; // fail to alloc memory
  time->hours = 3;
  time->minutes = 20;
  time->seconds = 0.023;
  printf("time : %u h %u min %f s.\n",
	 time->hours, time->minutes, time->seconds);
  add_three_hours(time);
  printf("time : %u h %u min %f s.\n",
	 time->hours, time->minutes, time->seconds);
  free(time);
  return 0;
}
