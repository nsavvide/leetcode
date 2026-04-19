#include <stdio.h>
#include <stdlib.h>

void rev(char *s) {
  if (*s == '\0') {
    return;
  }

  char *p = s;
  while (*p) {
    p++;
  }
  p--;

  while (s < p) {
    char tmp = *s;
    *s = *p;
    *p = tmp;

    p--;
    s++;
  }
}

int mirrorDistance(int n) {
  if (n < 10)
    return 0;

  char str[12]; // 10 (max number of digits) + 1 sign + 1 null char
  sprintf(str, "%d", n); // int -> string
  rev(str);

  int reverse_n = atoi(str);

  return abs(n - reverse_n);
}
