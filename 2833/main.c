
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int a, int b) { return (a > b) ? a : b; }

int furthestDistanceFromOrigin(char *moves) {
  if (*moves == '\0') {
    return 0;
  }

  int n = strlen(moves);
  int distance_left = 0;
  int distance_right = 0;

  for (size_t i = 0; i < n; i++) {
    char move = moves[i];

    if (move == 'L') {
      distance_left--;
      distance_right--;
    } else if (move == 'R') {
      distance_left++;
      distance_right++;
    } else {
      distance_left--;
      distance_right++;
    }
  }

  return max(abs(distance_left), abs(distance_right));
}

int main() {
  char moves[] = "_R__LL_";
  int distance = furthestDistanceFromOrigin(moves);
  printf("%d", distance);
}
