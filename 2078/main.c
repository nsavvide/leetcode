int max(int left, int right) {
  if (left > right) {
    return left;
  } else {
    return right;
  }
}

int maxDistance(int *colors, int colorsSize) {

  int left = 0;
  int right = colorsSize - 1;

  if (colors[left] != colors[right]) {
    return right - left;
  }

  int j = right;
  while (colors[left] == colors[j]) {
    j--;
  }

  int k = left;
  while (colors[right] == colors[k]) {
    k++;
  }

  return max(j - left, right - k);
}
