#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
  char line[1024];
  FILE *file = fopen("./VanGogh.md", "r"); // Open the file
  if (file==NULL) {
    fprintf(stderr,"Error while openning the file VanGogh.md\n");
    return EXIT_FAILURE;
  }
  FILE *fileCopy = fopen("./VanGoghCopy.md", "w");
  if (fileCopy==NULL) {
    fprintf(stderr,"Error with the file VanGoghCopy.md.\n");
    fclose(file);
    return EXIT_FAILURE;
  }
  // read until 1023 characters or line break
  if (fscanf(file, "%1023[^\n]", line) != EOF){
    if (fprintf(fileCopy, "%s\n", line) < 0)
      fprintf(stderr, "Error while writing VanGoghCopy.txt.\n");
  } else
    fprintf(stderr, "Error while reading VanGogh.md.\n");
  fclose(fileCopy); // Close the files
  fclose(file);
  return EXIT_SUCCESS;
}




