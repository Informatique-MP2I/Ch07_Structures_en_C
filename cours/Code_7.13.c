#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
  FILE *file = fopen("./VanGogh.md", "r"); // Open the file
  if (file==NULL) {
    fprintf(stderr,"Error while openning the file VanGogh.md.\n");
    return EXIT_FAILURE;
  }
  fclose(file); // Close the file
  return EXIT_SUCCESS;
}
