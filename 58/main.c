#include <stdio.h>
#include <string.h>
int lengthOfLastWord(char *s) {
  if (*s == '\0') {
    return 0;
  }

  int length = strlen(s);
  char *p = s + length - 1;

  while (p >= s && *p == ' ') {
    p--;
  }

  int length_of_last_word = 0;
  while (p >= s && *p != ' ') {
    p--;
    length_of_last_word++;
  }

  return length_of_last_word;
}

int main() {
  char sentence[] = "hello world";
  int length_of_last_word = lengthOfLastWord(sentence);

  printf("length of last word is %d", length_of_last_word);

  return 0;
}
