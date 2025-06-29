#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
  FILE *file = fopen("./VanGogh1.md", "r"); // Open the file
  if (file==NULL) {
    fprintf(stderr,"Error while openning VanGogh1.md.\n");
    return EXIT_FAILURE;
  }
  // read 3 caracteres and prints them on stdout
  for(int i=0;i<3;i++) {
    int c = fgetc(file); // c is in [0..255] (8 bits) or -1 (EOF)
    if(c == EOF) break;
    printf("%c",c);
  }
  fclose(file); // Close the file
  return EXIT_SUCCESS;
}
