#include <limits.h>
#include <stddef.h>
#include <stdio.h>
int maxDistance(int *nums1, int nums1Size, int *nums2, int nums2Size) {
  int max_distance = INT_MIN;
  int j = 0;

  for (int i = 0; i < nums1Size; i++) {
    if (j < i) {
      // make sure j is up to speed
      j = i;
    }

    while (i <= j && j < nums2Size && nums1[i] <= nums2[j]) {
      // we have found a match
      if (j - i > max_distance) {
        max_distance = j - i;
      }

      j++;
    }
  }

  if (max_distance != INT_MIN) {
    return max_distance;
  }

  return 0; // no valid pair has been found
}

int main() {
  int nums1[5] = {55, 30, 5, 4, 2};
  int nums2[5] = {100, 20, 10, 10, 5};

  int max_distance = maxDistance(nums1, 5, nums2, 5);
  printf("Max distance is = %d\n", max_distance);

  return 0;
}
