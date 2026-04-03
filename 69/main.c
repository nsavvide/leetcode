int mySqrt(int x) {
  if (x == 0) {
    return 0;
  }

  int low = 1;
  int high = x;
  while (low < high) {
    int mid = low + (high - low + 1) / 2;
    if (mid <= x / mid) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }

  return low;
}
