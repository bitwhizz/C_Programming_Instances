/*
 * inline_fun.c
 *
 *  Created on: 29-Dec-2018
 *      Author: saif
 */


#include <stdio.h>

/*
An inline function as its name suggests , inserted inline into each function call site.
This eliminates the overhead of the function invocation and return (register saving and retore) and
allows for potentially greater optimization as the compiler can optimize both the caller and called function as one.

As a downside code size increases because the contents of the function are copied into all the callers, 
which increases memory consumptions and instruction cache footprints.


Common practice is to place inline functions in header files.

as we use static along , an exported function is not created. if an inline function is used by
only one file, it can instead be placed towards the top of just that file.

*/

static inline int square(int x) 
{ 
  return x*x; 
}

int main()
{
  int x = 36/square(6);
  printf("%d\n", x);
  return 0;
}
