#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  for (int i=1; i<argc; i++){
    FILE *file = fopen(argv[i], "r");

    if (file==NULL) {
      fprintf(stderr, "Error while openning the file %s.\n", argv[i]);
      return EXIT_FAILURE;
    }

    int c; // Character c declared as int
    while ((c = fgetc(file)) != EOF) {
      fputc(c, stdout);
    }

    fclose(file);
  }
  return EXIT_SUCCESS;
}
