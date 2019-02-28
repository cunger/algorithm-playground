
int indexOf(int element, int sequence[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    if (sequence[i] == element) {
      return i;
    }
  }

  return -1;
}
