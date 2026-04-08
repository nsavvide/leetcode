int convert(char c) {
  switch (c) {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  default:
    return 0; // Use 0 to avoid messing up math
  }
}

int romanToInt(char *s) {
  int total = 0;

  for (int i = 0; s[i] != '\0'; i++) {
    int current = convert(s[i]);
    int next = convert(s[i + 1]);

    if (current < next) {
      total -= current;
    } else {
      total += current;
    }
  }

  return total;
}
