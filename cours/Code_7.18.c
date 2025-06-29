#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage : %s ReadFile WriteFile\n", argv[0]);
    return EXIT_FAILURE;
  }
  FILE *file = fopen(argv[1], "r"); // Open the file
  if (file==NULL) {
    fprintf(stderr, "Error while openning %s.\n", argv[1]);
    return EXIT_FAILURE;
  }
  FILE *fileCopy = fopen(argv[2], "w"); // Open the second file
  if (fileCopy==NULL) {
    fprintf(stderr, "Error while openning %s.\n", argv[2]);
    fclose(file);
    return EXIT_FAILURE;
  }
  
  // read 3 characters and write them on fileCopy
  for(int i=0;i<3;i++) {
    int c = fgetc(file); // c is in [0..255] (8 bits) or -1 (EOF)
    if(c == EOF) break;
    fputc(c,fileCopy);
  }
  fclose(fileCopy); // Close the files
  fclose(file); 
  return EXIT_SUCCESS;
}




