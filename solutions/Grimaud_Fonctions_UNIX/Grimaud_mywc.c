
#include <stdio.h>
#include <stdlib.h>

int count_lines(char *filename){
  FILE *file;
  int lines;
  int c;
  
  file = fopen(filename, "r");
  if (file==NULL) {
    fprintf(stderr, "Error while openning the file %s.\n", filename);
    return EXIT_FAILURE;
  }

  lines = 0;
  while ((c = fgetc(file)) != EOF) {
    if (c=='\n')
      lines++;
  }
  fclose(file);
  return lines;

}

int count_words(char *filename){
  FILE *file;
  int words;
  int c, c_old;
  
  file = fopen(filename, "r");
  if (file==NULL) {
    fprintf(stderr, "Error while openning the file %s.\n", filename);
    return EXIT_FAILURE;
  }
  
  words = 0;
  c_old = ' ';
  while ((c = fgetc(file)) != EOF) {
    while (c==' ' || c=='\n') {
      c=fgetc(file);
      c_old = ' ';
    }

    if (c_old == ' ' && !(c ==' ' || c== '\n' || c==EOF)){
      words++;
    }
    c_old = c;
  }

  fclose(file);
  return words;
}
  
int count_bytes(char *filename){
  FILE *file;
  int octets;
  int c;
  file = fopen(filename, "r");

  if (file==NULL) {
    fprintf(stderr, "Error while openning the file %s.\n", filename);
    return EXIT_FAILURE;
  }
  octets = 0;
  while ((c = fgetc(file)) != EOF) {
    octets++;
  }
  
  fclose(file);
  return octets;
}

void mywc_help(void){
  printf("Usage : ./mywc opt filename1 filename2 ...\n");
  printf("\t -l : display the number of lines on the given filename(s).\n");
  printf("\t -w : display the number of words on the given filename(s).\n");
  printf("\t -c : display the number of bytes on the given filenale(s).\n");
  printf("\t no option : display the number of lines, words and bytes of the given filename(s).\n");
  printf("\t wrong option : display this message.\n");
  return;
}

int main(int argc, char **argv) {
  int lines, words, bytes;
  int tlines, twords, tbytes;
  int i;

  if(argc<2){
    fprintf(stderr, "Missing parameters.\n");
    mywc_help();
    return EXIT_FAILURE;
  }
  
  switch(argv[1][0]){
  case '-':
    switch(argv[1][1]){
    case 'l':
      tlines = 0;
      for (i=2;i<argc;i++) {
	lines = count_lines(argv[i]);
	tlines = tlines + lines;
	printf("%d\t %s\n", lines, argv[i]);
      }
      if (argc>3)
	printf("%d\t total\n", tlines);
      break;
    case 'w':
      twords = 0;
      for (i=2;i<argc;i++) {
	words = count_words(argv[i]);
	twords = twords + words;
	printf("%d\t %s\n", words, argv[i]);
      }
      if (argc>3)
	printf("%d\t total\n", twords);
      break;
    case 'c':
      tbytes = 0;
      for (i=2;i<argc;i++) {
	bytes = count_bytes(argv[i]);
	tbytes = tbytes + bytes;
	printf("%d\t %s\n", bytes, argv[i]);
      }
      if (argc>3)
	printf("%d\t total\n", tbytes);
      break;
    default:
      mywc_help();
      break;
    }
    break;
  default:
    tlines = 0;
    twords = 0;
    tbytes = 0;
    for (i=1;i<argc;i++) {
      // Count the number of lines
      lines = count_lines(argv[i]);
      tlines = tlines+lines;
      // Count the number of words
      words = count_words(argv[i]);
      twords=twords+words;
      // Count the number of bytes
      bytes = count_bytes(argv[i]);
      tbytes = tbytes+bytes;
      printf("%d\t %d\t %d\t %s\n", lines, words, bytes, argv[i]);
    }
    if (argc>3)
      printf("%d\t %d\t %d\t total\n", tlines, twords, tbytes);
    break;
  }
  

  return EXIT_SUCCESS;
}
