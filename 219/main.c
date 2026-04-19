#include <stdbool.h>
#include <stdlib.h>
#include <uthash.h>

struct hash_entry {
  int key;
  int index;
  UT_hash_handle hh;
};

bool containsNearbyDuplicate(int *nums, int numsSize, int k) {
  struct hash_entry *map = NULL;
  struct hash_entry *map_value, *tmp;

  for (int i = 0; i < numsSize; i++) {
    HASH_FIND_INT(map, &nums[i], map_value);

    if (map_value != NULL) {
      if (i - map_value->index <= k) {

        HASH_ITER(hh, map, map_value, tmp) {
          HASH_DEL(map, map_value);
          free(map_value);
        }
        return true;

      } else {
        map_value->index = i;
      }

    } else {
      struct hash_entry *new_item = malloc(sizeof(struct hash_entry));
      new_item->key = nums[i];
      new_item->index = i;

      HASH_ADD_INT(map, key, new_item);
    }
  }

  HASH_ITER(hh, map, map_value, tmp) {
    HASH_DEL(map, map_value);
    free(map_value);
  }

  return false;
}
