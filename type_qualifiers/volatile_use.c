/* Compile code without optimization option */
#include <stdio.h>

/*
When you declare a variable as const volatile int x;, you are specifically telling the compiler that hardware
 (like an Interrupt Service Routine, a DMA controller, or a memory-mapped peripheral) has the authority to change that value, 
 even though your software does not.

 The const qualifier is a compile-time contract for the software you are currently writing.
  It tells the compiler: "If you see me (the programmer) try to write local = 5;, stop me with an error."

However, const does not physically lock the memory chip or prevent the hardware's electrical signals from changing the bits at that memory address.
Hardware ignores software-level "const" restrictions.
*/

int main(void)
{
    const volatile int local = 10;
    int *ptr = (int*) &local;
 
    printf("Initial value of local : %d \n", local);
 
    *ptr = 100;
 
    printf("Modified value of local: %d \n", local);
 
    return 0;
}
