#include <stdio.h>
#include <stdlib.h>

int arraySizer () {
  int store[3] = {0, 1, 2};
  int count = 0;
  //int count = 2
  while (store[2] < 4000000) {
    store[0] = store[1];
    store[1] = store[2];
    store[2] = store[0] + store[1];
    if (store[2] % 2 == 0) count++;
    //if (store[2] % 2 == 0) count += store[2];
  }
  return count;
}

int main () {
  int size = arraySizer();
  int * evenFib = malloc(size * sizeof(int));
  int buff[3] = {0, 1, 2};
  for (int i = 0; buff[2] < 4000000; i) {
    buff[0] = buff[1];
    buff[1] = buff[2];
    buff[2] = buff[0] + buff[1];
    if (buff[2] % 2 == 0) {
      *(evenFib + i) = buff[2];
      i++;
    }
  }
  int total = 2;
  printf("Displaying all even numbered Fibonacci values below 4E6.\n");
  for (int i = 0; i < size; i++) {
    printf("%d\n", *(evenFib + i));
    total += *(evenFib + i);
  }
  printf("Total: %d\n", total);
  return 0;
}