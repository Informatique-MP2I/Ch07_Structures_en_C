#include <stdio.h>
typedef struct {
  unsigned int hours;
  unsigned int minutes;
  double seconds;
} time_s;
int main(int argc, char **argv) {
  time_s time ={1, 0, 0.1};
  time_s a[2] ={{1,2,3.456},time};
  time_s *b[2]={&time,&a[0]};
  printf("before:\n");
  for(int i=0;i<2;i++) {
    printf("a[%d]=%uh%um%2.3f ",
	   i, a[i].hours, a[i].minutes, a[i].seconds);
    printf("b[%d]=%uh%um%2.3f\n",
	   i, b[i]->hours, b[i]->minutes, b[i]->seconds);
  }
  
  time.hours=3;
  printf("after:\n");
  for(int i=0;i<2;i++) {
    printf("a[%d]=%uh%um%2.3f ",
	   i, a[i].hours, a[i].minutes, a[i].seconds);
    printf("b[%d]=%uh%um%2.3f\n",
	   i, b[i]->hours, b[i]->minutes, b[i]->seconds);
  }
  return 0;
}
