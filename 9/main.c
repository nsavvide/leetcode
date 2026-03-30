#include <stdbool.h>
#include <stdio.h>

const int length(char *str) {
  int len = 0;
  while (str[len] != '\0') {
    len++;
  }

  return len;
}

bool isPalindrome(int x) {
  char str[12]; // int can be at most 10 digits + sign + null terminator
  sprintf(str, "%d", x);
  const int len = length(str);
  int l = 0;
  int r = len - 1;

  while (l < r) {
    if (str[l] != str[r]) {
      return false;
    }

    l++;
    r--;
  }

  return true;
}
