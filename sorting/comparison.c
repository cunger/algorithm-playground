int increasing(int x, int y) {
  if (x < y) return -1;
  if (x > y) return 1;
  return 0;
}

int decreasing(int x, int y) {
  if (x > y) return -1;
  if (x < y) return 1;
  return 0;
}
