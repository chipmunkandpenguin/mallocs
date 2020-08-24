/*
 * =====================================================================================
 *
 *       Filename:  p3.c
 *
 *    Description: penguin and chipmunk solve proj euler p3 
 *
 *        Version:  1.0
 *        Created:  08/24/20 02:07:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: Penguin and Chipmunk 
 *   Organization: Penguin and Chipmunk Enterprises Incorporated Inc. 
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// function to reallocate array of size n to size (n+1)
void longPush(long long *arr, int size) {
  arr = (long long *) realloc(arr, (size + 1) * sizeof(long long));
}

int main() {
  // get clock
  double exTime = 0.0;
  clock_t begin = clock();

  // n keeps track of the size of array, x stores number, flag is a boolean
  int n = 1;
  long long x = 600851475143;
  bool flag = true;
  int i = 2;

  // define the array as pointers
  long long *divs = (long long *) malloc(n * sizeof(long long));

  // start with 2, check if it divides x. if it does, set x = x / 2
  // otherwise move on to 3 and then 4 and so on
  // when it finally divides by p, the divisor is guaranteed to be prime
  // then set x = x / p
  
  // use first flag to signal if x == 1, in which case terminate
  while (flag) {
    // define another flag statement to signal that i divides x, in which case divide 
    bool flag2 = true;

    while (flag2) {

      // if successfully divides then push another entry into divs
      if (x % i == 0) {
        longPush(divs, n);
        // store prime in divs
        divs[n - 1] = i;
        // divide through
        x = x / i;
        // set flag to false
        flag2 = false;
      }

      // otherwise move on to next number
      else {
        i = i + 1;
      }

    }
    

    // finally, once above loop is finished, check if x is now 1
    if (x == 1) {
      // if so, terminate
      flag = false;
    }
    // regardless, size of array has increased, update size variable
    n = n + 1;
  }

  // once done, print results, note that array size is 1 more than number of divisors
  printf("largest prime is: %d \n", divs[n-2]);
  printf("number of prime divisors is: %d \n", (n-2));

  // output execution time
  clock_t end = clock();
  exTime += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("time elapsed is: %f \n", exTime);
}
