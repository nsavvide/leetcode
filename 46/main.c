/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

unsigned int factorial(unsigned int N) {
  int fact = 1, i;
  for (i = 1; i <= N; i++) {
    fact *= i;
  }
  return fact;
}

void backtrack(int *nums, int numsSize, int start_index, int **result,
               int *current_row_ptr) {
  // BASE CASE: We have swapped all the way to the end of the array
  if (start_index == numsSize) {
    // We found a complete permutation!
    int *new_array = (int *)malloc(numsSize * sizeof(int));

    // Copy all elements from the current 'nums' into this new array
    for (int i = 0; i < numsSize; i++) {
      new_array[i] = nums[i];
    }

    result[*current_row_ptr] = new_array;

    (*current_row_ptr)++;
    return;
  }

  // RECURSIVE STEP: Try placing every available number at the 'start_index'
  for (int i = start_index; i < numsSize; i++) {

    swap(&nums[start_index], &nums[i]);

    backtrack(nums, numsSize, start_index + 1, result, current_row_ptr);

    swap(&nums[start_index], &nums[i]);
  }
}

int **permute(int *nums, int numsSize, int *returnSize,
              int **returnColumnSizes) {
  int total_permutations = factorial(numsSize);

  *returnSize = total_permutations;

  int **result = (int **)malloc(total_permutations * sizeof(int *));

  *returnColumnSizes = (int *)malloc(total_permutations * sizeof(int));
  for (int i = 0; i < total_permutations; i++) {
    (*returnColumnSizes)[i] = numsSize;
  }

  int current_row = 0;

  backtrack(nums, numsSize, 0, result, &current_row);

  return result;
}
