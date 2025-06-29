#include <stdio.h>
#include <stdlib.h>

/*
  myecho : the simple echo function
 */
int main(int argc, char **argv) {
  for (int i=1;i<argc;i++) { 
    printf("%s ", argv[i]);
  }
  printf("\n");
  return EXIT_SUCCESS;
}




