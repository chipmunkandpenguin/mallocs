#include <stdio.h>

int main() {
  /* initialize variables */
  int a = 1;
  int b = 1;
  int n = 0;
  int c;

  /* check if b is even and less than 1 mil if not then move on */
  while (b < 4000000) {
    if (b % 2 == 0) {
      n = n + b;
    }

  /* update fib using placeholder var */
  c = a + b;
  a = b;
  b = c;
  }
  printf("%d\n", n);
}
