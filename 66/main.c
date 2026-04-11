/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stddef.h>
#include <stdlib.h>
int *plusOne(int *digits, int digitsSize, int *returnSize) {
  if (digits == NULL) {
    *returnSize = 0;
    return NULL;
  }

  int carry = 1; // we want to add 1
  for (int i = digitsSize - 1; i >= 0; i--) {
    int sum = digits[i] + carry;
    if (sum == 10) {
      digits[i] = 0;
      carry = 1;
    } else {
      digits[i] = sum;
      carry = 0;
      *returnSize = digitsSize;
      return digits;
    }
  }

    int *result = (int *)malloc(sizeof(int) * (digitsSize + 1));
    result[0] = 1;
    for (size_t i = 0; i < digitsSize; i++) {
      result[i + 1] = digits[i];
    }

    *returnSize = digitsSize + 1;
    return result;
}
