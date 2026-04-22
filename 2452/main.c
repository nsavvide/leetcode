/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// solution is O(n * m * l);

#include <stdlib.h>
#include <string.h>
char **twoEditWords(char **queries, int queriesSize, char **dictionary,
                    int dictionarySize, int *returnSize) {

  /* for (string s in queries) { */
  /*   for (string d in dictionary) { */
  /*   } */
  /*   int errors = 0; */
  /*   while (errors != 2) { */
  /*     if (s[i] != d[i]) { */
  /*       errors++; */
  /*     } */
  /*   } */
  /**/
  /*     if(errors != 2){ */
  /*   result.append(string); */
  /* } */
  /* } */

  char **result = (char **)malloc(sizeof(char *) * queriesSize);
  int idx = 0;

  for (int i = 0; i < queriesSize; i++) {
    char *query = queries[i];
    int length = strlen(query);

    for (int j = 0; j < dictionarySize; j++) {
      char *word = dictionary[j];

      int k = 0;
      int errors = 0;
      while (k < length && errors <= 2) {
        if (word[k] != query[k])
          errors++;

        k++;
      }

      if (errors <= 2) {
        // found an element
        result[idx] = query;
        idx++;
        break;
      }
    }
  }

  *returnSize = idx;
  return result;
}
