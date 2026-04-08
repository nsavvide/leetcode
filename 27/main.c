int removeElement(int *nums, int numsSize, int val) {
  if (numsSize == 0) {
    return 0;
  }

  int read_idx;
  int write_idx = 0;

  for (read_idx = 0; read_idx < numsSize; read_idx++) {
    if (nums[read_idx] != val) {
      nums[write_idx++] = nums[read_idx];
    }
  }

  return write_idx;
}
