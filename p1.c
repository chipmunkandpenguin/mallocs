#include <stdio.h>

int main() {
  /* initialize variables */
  int i = 1;
  int n = 0;

  /* start while loop */
  while (i < 1000) {

    /* check if divides */
    if ((i % 3 == 0) || (i % 5 == 0)) {
      /* add to sum if so */
      n = n + i;
    }

    /* cycle through i's */
    i = i + 1;
  }
  printf("%d\n", n);
  return 0;
}


