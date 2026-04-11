#include <string.h>
int strStr(char *haystack, char *needle) {
  if (*haystack == '\0' || *needle == '\0')
    return -1;

  int length_haystack = strlen(haystack);
  int length_needle = strlen(needle);

  if (length_needle > length_haystack)
    return -1;

  /* Input: haystack = "sadbutsad", needle = "sad" */
  /* Output: 0 */
  /* Explanation: "sad" occurs at index 0 and 6. */
  /* The first occurrence is at index 0, so we return 0. */

  for (size_t i = 0; i < length_haystack - length_needle + 1; i++) {
    int j = 0;
    while (haystack[i + j] == needle[j] && j < length_needle) {
      j++;
    }

    if (j == length_needle) {
      return i;
    }
  }

  return -1;
}
