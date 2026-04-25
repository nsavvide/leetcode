#include <stdbool.h>

int getNext(int n) {
  int sum = 0;
  while (n > 0) {
    int digit = n % 10;
    sum += digit * digit;
    n /= 10;
  }

  return sum;
}

bool isHappy(int n) {
  if (n <= 0) {
    return false;
  }

  int slow = n;
  int fast = getNext(n);
  while (fast != slow && fast != 1) {
    slow = getNext(slow);
    fast = getNext(getNext(fast));
  }

  return fast == 1;
}
