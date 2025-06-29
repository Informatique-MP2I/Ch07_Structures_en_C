#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
  const int MAX_ELEMENTS = 100;
  int squares[MAX_ELEMENTS];
  // Using the constant to define the size of the array
  for (int i = 0; i < MAX_ELEMENTS; i++)
    squares[i] = i * i;  // Storing the squares of numbers
  // Printing the values of the array
  for (int i = 0; i < MAX_ELEMENTS; i++)
    printf("%d ", squares[i]);
  printf("\n");
  return EXIT_SUCCESS;
}
