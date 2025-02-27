#include <stdio.h>
#include <stdlib.h>     //need this library for malloc function

#define MALLOC_CHAR (char *)malloc

#define FREE_CHARS() \
if (char1 != NULL) free(char1);\
if (char2 != NULL) free(char2);

int main()
{
  char *char1;
  char *char2;

  int charSize = sizeof(char);
  char1 = MALLOC_CHAR(charSize);
  char2 = MALLOC_CHAR(charSize);

  if (char1 == NULL || char2 == NULL) {
    printf("Problem allocating memory.");
    FREE_CHARS()
    exit(1);
  }

  printf("Input two characters:\n");
  if (scanf(" %c %c", char1, char2) != 2) {
    printf("Invalid input! Only two characters allowed.");
    FREE_CHARS();
    exit(1);
  }

  printf("\nYou gave me '%c' and '%c'.\n", *char1, *char2);

  FREE_CHARS()

  return 0;
}
