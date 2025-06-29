#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
  FILE *file = fopen("./VanGogh.md", "r"); // Open the file
  if (file==NULL) {
    fprintf(stderr,"Error while openning the file VanGogh.md\n");
    return EXIT_FAILURE;
  }
  // Open the second file
  FILE *fileCopy = fopen("./VanGoghCopy.md", "w"); 
  if (fileCopy==NULL) {
    fprintf(stderr, "Error with the file VanGoghCopy.md\n");
    fclose(file);
    return EXIT_FAILURE;
  }
  // read 3 characters and write them on fileCopy
  for(int i=0;i<3;i++) {
    int c = fgetc(file); // c is in [0..255] (8 bits) or -1 (EOF)
    if(c == EOF) break;
    fputc(c, fileCopy); 
  }
  fclose(fileCopy); // Close the files
  fclose(file);
  return EXIT_SUCCESS;
}




