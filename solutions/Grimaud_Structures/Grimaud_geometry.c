#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
  double x;
  double y;
} point_s;

typedef struct {
  point_s center;
  double radius;
} circle_s;

double distance(point_s p1, point_s p2){
  return sqrt((p2.x - p1.x)*(p2.x - p1.x)+(p2.y - p1.y)*(p2.y - p1.y));
}

void init_circle(circle_s *c){
  c->center.x = ((double)rand() / RAND_MAX) * 200 - 100;
  c->center.y = ((double)rand() / RAND_MAX) * 200 - 100;
  c->radius = ((double)rand() / RAND_MAX) * 200 - 100;
  return;
}
  
int main(int argc, char **argv){
  if (argc != 3){
    printf("Wrong number of parameters : waiting for x and y of a point.\n");
    return EXIT_FAILURE;
  }

  // Initialization of the given point
  point_s p = {atof(argv[1]),atof(argv[2])};

  // Initialization of 10 circles
  circle_s c[10];

  srand(time(NULL));
  int i;
  for (i=0; i<10; i++){
    init_circle(&c[i]);
  }
  
  // Computing the distances
  printf("The point (%f,%f) belongs to the disks :\n",p.x,p.y);
  for (i=0; i<10; i++){
    if (distance(c[i].center, p) <= c[i].radius){
      printf("of center (%f,%f) and radius %f\n",c[i].center.x,c[i].center.y,c[i].radius);
    }
  }

  return 0;
}
