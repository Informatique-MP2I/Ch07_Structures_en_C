#include <stdio.h>
typedef struct {
  long ln;
  char *array;
} struct_a;
typedef struct {
  long ln;
  char array[16];
} struct_b;
int main(int argc,char **argv){
  struct_a a={8,"ABCDEFG"};
  struct_b b={8,"ABCDEFGHIJKLMNOP"};
  printf("sizeof(struct_a)=%lu\n",sizeof(a));
  printf("sizeof(struct_b)=%lu\n",sizeof(b));
  return 0;
}
