/*
 * =====================================================================================
 *
 *       Filename:  p48.c
 *
 *    Description:  Penguin and chipmunk solve project euler number 48 
 *
 *        Version:  1.0
 *        Created:  12/17/20 22:05:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Penguin and Chipmunk, 
 *   Organization:  Penguin and Chipmunk Corporation, incorporated
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
  /*  Start the clock  */
  clock_t begin = clock();

  /*  "sum" stores the total sum and "tens" is 10^10; longs are required  */
  long sum = 0;
  long tens = 1E10;

  /*  Iterate from 1 to 1000  */
  for (int i = 1; i <= 1000; i++){
    /*  Need to calculate i^i, but this can be too large for computer  */
    /*  Workaround is to take it modulo "tens"; create variable "summand" to compute i^i  */
    long summand = 1;

    /*  For instance, for i = 4, j ranges from 1 to 4, and each time we multiply by 4  */
    for (int j = 1; j <= i; j++){
      /*  After each multiplication, it is necessary to take modulo "tens"; otherwise numbers get too large, ie 1000^1000 too big  */
      summand = summand * i;
      summand = summand % tens;
    }

    /*  We then add each summand corresponding to i, back into "sum" */
    /*  Once again, need to take modulo "tens"  */
    sum = sum + summand;
    sum = sum % tens;
  }

  /*  Stop the clock  */
  clock_t end = clock();
  double elapsed = (double)(end - begin) / CLOCKS_PER_SEC;
  
  /*  Print results  */
  printf("%ld \n", sum);
  printf("this took %f seconds \n", elapsed);
}
