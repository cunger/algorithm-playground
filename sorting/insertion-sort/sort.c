#include "../../linkedlist/linkedlist.h"
#include <stddef.h>

void sort(int sequence[], int size) {
  int i;
  for (i = 1; i < size; i++) {
    int element = sequence[i];

    int j = i - 1;
    while (j >= 0 && sequence[j] > element) {
      sequence[j + 1] = sequence[j];
      j--;
    }

    sequence[j + 1] = element;
  }
}
