#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
  char line[1024];
  FILE *file = fopen("./VanGogh.md", "r"); // Open the file
  if (file==NULL) {
    fprintf(stderr, "Error while openning VanGogh.md.\n");
    return EXIT_FAILURE;
  }
  // read until 1023 characters or line break
  if (fscanf(file, "%1023[^\n]", line) != EOF)
    printf("%s\n", line);
  else
    fprintf(stderr, "Error while reading VanGogh.md.\n");
  fclose(file); // Close the file
  return EXIT_SUCCESS;
}
