/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include "uthash.h"

typedef struct hashTable {
  int key;
  int value;
  UT_hash_handle hh;
} hashTable;

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  int *result = (int *)malloc(sizeof(int) * 2);

  hashTable *hashmap = NULL;
  hashTable *element, *tmp;

  for (size_t i = 0; i < numsSize; i++) {
    int complement = target - nums[i];
    HASH_FIND_INT(hashmap, &complement, element);
    if (element != NULL) {
      result[0] = element->value;
      result[1] = i;
      *returnSize = 2;

      HASH_ITER(hh, hashmap, element, tmp) {
        HASH_DEL(hashmap, element);
        free(element);
      }

      return result;
    }

    element = (hashTable *)malloc(sizeof(hashTable));
    element->value = i;
    element->key = nums[i];
    HASH_ADD_INT(hashmap, key, element);
  }

  // clear hashtable
  HASH_ITER(hh, hashmap, element, tmp) {
    HASH_DEL(hashmap, element);
    free(element);
  }

  *returnSize = 0;
  free(result);
  return NULL;
}
