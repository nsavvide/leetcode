#include <limits.h>
#include <stdlib.h>
int getMinDistance(int *nums, int numsSize, int target, int start) {
  int min_distance = INT_MAX;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == target && abs(i - start) < min_distance) {
      min_distance = abs(i - start);
    }
  }

  return min_distance;
}
