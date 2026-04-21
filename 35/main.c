#include <math.h>
#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target) {
  // perform binary search
  // if left == right -> target was not found
  // check if larger or smaller (+ 1 or -1)

  int left = 0;
  int right = numsSize - 1;
  int mid = floor((right) / 2);

  while (left <= right) {
    // base
    if (nums[mid] == target) {
      return mid;
    }

    if (nums[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }

    mid = left + floor((right - left) / 2);
  }

  return mid;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};

  int size = 5;
  int target = 5;
  int result = searchInsert(arr, size, target);

  printf("result: %d\n", result);

  return 0;
}
