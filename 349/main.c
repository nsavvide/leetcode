/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

#include "uthash.h"

typedef struct {
  int val;
  int count;
  UT_hash_handle hh;
} h_entry;

int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size,
                  int *returnSize) {

  *returnSize = 0;

  if (nums1Size == 0 || nums2Size == 0) {
    return NULL;
  }

  int size_res = nums1Size > nums2Size ? nums1Size : nums2Size;
  int *res = (int *)malloc(sizeof(int) * size_res);
  h_entry *hashmap = NULL;

  for (size_t i = 0; i < nums1Size; i++) {
    h_entry *existing_entry;
    HASH_FIND_INT(hashmap, &nums1[i], existing_entry);
    if (existing_entry != NULL) {
      existing_entry->count++;
    } else {
      h_entry *new_entry = (h_entry *)malloc(sizeof(h_entry));
      new_entry->count = 1;
      new_entry->val = nums1[i];

      HASH_ADD_INT(hashmap, val, new_entry);
    }
  }

  for (size_t i = 0; i < nums2Size; i++) {
    h_entry *entry;
    HASH_FIND_INT(hashmap, &nums2[i], entry);
    if (entry != NULL && entry->count != 0) {
      res[(*returnSize)++] = entry->val;
      entry->count = 0;
    }
  }

  h_entry *current_entry, *tmp;
  HASH_ITER(hh, hashmap, current_entry, tmp) {
    HASH_DEL(hashmap, current_entry);
    free(current_entry);
  }

  return res;
}
