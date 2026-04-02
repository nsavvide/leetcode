#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

int my_strlen(const char *s) {
  if (s == NULL) {
    return 0;
  }

  int length = 0;
  while (*s != '\0') {
    length++;
    s++;
  }

  return length;
}

bool isValid(char *s) {
  int length = my_strlen(s);
  char stack[length];
  int top = -1;

  for (size_t i = 0; i < length; i++) {
    char c = s[i];

    if (c == '(' || c == '[' || c == '{') {
      stack[++top] = c;
    } else {
      if (top == -1)
        return false;

      char top_c = stack[top];
      if (c == ')' && top_c == '(' || c == ']' && top_c == '[' ||
          c == '}' && top_c == '{')
        top--;
      else
        return false;
    }
  }

  return top == -1;
}
