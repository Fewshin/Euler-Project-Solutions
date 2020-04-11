#include <stdio.h>
#include <stdlib.h>

int main () {
  int * threes = malloc(1000 * sizeof(int));
  int * fives = malloc(1000 * sizeof(int));
  int threeCount = 0;
  int fiveCount = 0;
  for (int i = 3; i <= 1000; i++) {
    if (i % 3 == 0) {
      *(threes + threeCount) = i;
      threeCount++;
    }
    if (i % 5 == 0) {
      *(fives + fiveCount) = i;
      fiveCount++;
    }
  }
  threes = realloc(threes, threeCount * sizeof(int));
  fives = realloc(fives, fiveCount * sizeof(int));
  printf("Printing Multiples of Three\n");
  for (int i = 0; i < threeCount; i++) {
    printf("%d\n", *(threes + i));
  }
  printf("Printing Multiples of Five\n");
  for (int i = 0; i < fiveCount; i++) {
    printf("%d\n", *(fives + i));
  }
  return 0;
}