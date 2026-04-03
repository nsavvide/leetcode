int removeDuplicates(int *nums, int numsSize) {
  if (numsSize == 0) {
    return 0;
  }

  int read_idx;
  int write_idx = 1;
  for (read_idx = 1; read_idx < numsSize; read_idx++) {
    if (nums[read_idx] != nums[read_idx - 1]) {
      nums[write_idx++] = nums[read_idx];
    }
  }

  return write_idx;
}
