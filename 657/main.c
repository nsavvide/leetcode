#include <stddef.h>
bool judgeCircle(char *moves) {
  int x = 0;
  int y = 0;

  for (size_t i = 0; moves[i] != '\0'; i++) {
    switch (moves[i]) {
    case 'U':
      y--;
      break;

    case 'D':
      y++;
      break;

    case 'L':
      x--;
      break;

    case 'R':
      x++;
      break;
    }
  }

  return x == 0 && y == 0;
}
