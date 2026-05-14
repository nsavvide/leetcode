#include <limits.h>
#include <stdlib.h>

#include "uthash.h"
#include <stdbool.h>

typedef struct {
  int val;
  int count;
  UT_hash_handle hh;
} h_entry;

void _update_max_stats(const int n, int *max_val, int *freq) {
  if (n < *max_val) {
    return;
  }

  if (n == *max_val) {
    (*freq)++;
    return;
  }

  else {
    *freq = 1;
    *max_val = n;
    return;
  }
}

bool isGood(int *nums, int numsSize) {
  // built a hashmap
  // keep track of the max value
  // keep track of the amount of keys in hashmap and check size == max + 1
  // check if max value appears twice
  // then do iterative check
  //
  h_entry *hashmap = NULL;
  int max_val = INT_MIN;
  int freq = 0;
  for (size_t i = 0; i < numsSize; i++) {
    h_entry *existing_entry;
    HASH_FIND_INT(hashmap, &nums[i], existing_entry);
    if (existing_entry != NULL) {
      existing_entry->count++;
    } else {
      h_entry *new_entry = (h_entry *)malloc(sizeof(h_entry));
      new_entry->count = 1;
      new_entry->val = nums[i];
      HASH_ADD_INT(hashmap, val, new_entry);
    }

    _update_max_stats(nums[i], &max_val, &freq);
  }

  if (numsSize != max_val + 1) {
    goto drop;
  }

  if (freq != 2) {
    goto drop;
  }

  // values are >= 1
  for (size_t i = 1; i < numsSize; i++) {
    h_entry *existing_entry;
    HASH_FIND_INT(hashmap, &i, existing_entry);
    if (existing_entry == NULL) {
      goto drop;
    }

    if (existing_entry->val != max_val && existing_entry->count != 1) {
      goto drop;
    }
  }

  return true;
drop:
  h_entry *current_entry, *tmp;
  HASH_ITER(hh, hashmap, current_entry, tmp) {
    HASH_DEL(hashmap, current_entry);
    free(current_entry);
  }

  return false;
}
