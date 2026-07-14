#include<stdio.h>
int main()
{
	int i;
	int j=100;
	int m[5]={10,20,30,40,50};
	
	m[-1]=200;
	
	for(i=0;i<5;i++)
	{
		printf("m[%d] address=%p\n",i,(int *)&m[i]);
		printf("m[%d] values=%d\n",i,m[i]);
	}
	printf("address of m[-1]=%p\n",(int *)&m[-1]);
	printf("address of i=%p\n",(int *)&i);
	printf("address of m[6]=%p\n",(int *)&m[6]);
	printf("address of j=%p\n",(int *)&j);
	printf("value of i=%d\n",i);
	printf("value of j=%d\n",j);
	printf("\n");
        return 0;
}

/*
gcc -fsanitize=address -g array4.c -o array4
./array4

==6494==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7fff3faf696c at pc 0x000000400c08 bp 0x7fff3faf68c0 sp 0x7fff3faf68b0
WRITE of size 4 at 0x7fff3faf696c thread T0
    #0 0x400c07 in main /home/saif/programmer/C_Programming_Instances /array/array4.c:8
    #1 0x7fdb745a383f in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2083f)
    #2 0x400908 in _start (/home/saif/programmer/C_Programming_Instances /array/array4+0x400908)

Address 0x7fff3faf696c is located in stack of thread T0 at offset 156 in frame
    #0 0x4009c1 in main /home/saif/programmer/C_Programming_Instances /array/array4.c:3

  This frame has 3 object(s):
    [32, 36) 'i'
    [96, 100) 'j'
    [160, 180) 'm' <== Memory access at offset 156 underflows this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism, swapcontext or vfork
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-buffer-overflow /home/saif/programmer/C_Programming_Instances /array/array4.c:8 in main
Shadow bytes around the buggy address:
  0x100067f56cd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100067f56ce0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100067f56cf0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100067f56d00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100067f56d10: 00 00 00 00 00 00 00 00 00 00 f1 f1 f1 f1 04 f2
=>0x100067f56d20: f2 f2 f2 f2 f2 f2 04 f2 f2 f2 f2 f2 f2[f2]00 00
  0x100067f56d30: 04 f2 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100067f56d40: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100067f56d50: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100067f56d60: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100067f56d70: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==6494==ABORTING
*/
