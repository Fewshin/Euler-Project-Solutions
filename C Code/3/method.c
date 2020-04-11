#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long factorCount (long value) {
  long count = 0;
  for (long i = 0; i < (long) value/2; i++) {
    if (value % i == 0) {
      count++;
    }
  }
  return count;
}

int main () {
  long value = 600851475143;
  long size = factorCount(value);
  long * factorArray = malloc(size * sizeof(long));
  printf("Ping\n");
  long count = 0;
  for (long i = 2; i < (long) value/2; i++) {
    if (value % i == 0) {
      long isPrime = 1;
      for (long j = 0; j < i/2; j++) {
        if (i % j == 0) {
          isPrime = 0;
          break;
        }
      }
      if (isPrime) {
        *(factorArray + count) = i;
        count++;
      }
    }
  }
  printf("Displaying all prime factors\n");
  for (long i = 0; i < count; i++) {
    printf("%ld\n", *(factorArray + i));
  }
  return 0;
}