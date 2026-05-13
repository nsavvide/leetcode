#include <stddef.h>
int firstUniqChar(char *s) {
  int arr[26] = {0};

  for (size_t i = 0; s[i] != '\0'; i++) {
    arr[s[i] - 'a']++;
  }

  for (size_t i = 0; s[i] != '\0'; i++) {
    if (arr[s[i] - 'a'] == 1) {
      return i;
    }
  }

  return -1;
}
