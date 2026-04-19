#include <stddef.h>
#include <stdio.h>

// read from the back to prevent overwriting
void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
  // nums1 = [1, 2, 3, 0, 0, 0],
  // nums2 = [2, 5, 6]
  if (n == 0) {
  }

  if (m == 0) {
    for (size_t i = 0; i < nums1Size; i++) {
      nums1[i] = nums2[i];
    }

    return;
  }

  int read_idx1 = m - 1;
  int read_idx2 = n - 1;
  int write_idx = m + n - 1;

  // we only have to check nums2Size because if n < m, the elements are already
  // in nums1 if m > n, we simply copy them over
  while (read_idx2 >= 0) {
    if (read_idx1 >= 0 && nums1[read_idx1] > nums2[read_idx2]) {
      nums1[write_idx--] = nums1[read_idx1--];
    } else {
      nums1[write_idx--] = nums2[read_idx2--];
    }
  }
}
