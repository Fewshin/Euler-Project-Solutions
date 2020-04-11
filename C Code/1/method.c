#include <stdio.h>
#include <stdlib.h>

int main () {
  int * threes = malloc(1000 * sizeof(int));
  int * fives = malloc(1000 * sizeof(int));
  int threeCount = 0;
  int fiveCount = 0;
  for (int i = 3; i < 1000; i++) {
    if (i % 3 == 0 /*&& i % 5 != 0*/) {
      *(threes + threeCount) = i;
      threeCount++;
    }
    else if (i % 5 == 0 && i % 3 != 0) {
      *(fives + fiveCount) = i;
      fiveCount++;
    }
  }
  threes = realloc(threes, threeCount * sizeof(int));
  fives = realloc(fives, fiveCount * sizeof(int));
  int threeTotals = 0;
  int fiveTotals = 0;
  printf("Printing Multiples of Three.\n");
  for (int i = 0; i < threeCount; i++) {
    threeTotals += *(threes + i);
    printf("%d\n", *(threes + i));
  }
  free(threes);
  printf("Printing Multiples of Five that aren't also multiples of Three.\n");
  for (int i = 0; i < fiveCount; i++) {
    fiveTotals += *(fives + i);
    printf("%d\n", *(fives + i));
  }
  free(fives);
  printf("The sum of all multiples of three: %d\n", threeTotals);
  printf("The sum of all multiples of five: %d\n", fiveTotals);
  printf("The sum of both is: %d\n", threeTotals + fiveTotals);
  return 0;
}