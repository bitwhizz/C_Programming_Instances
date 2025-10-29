/***********************************************************************
The above representation of ‘date’ takes 12 bytes on a compiler 
where an unsigned int takes 4 bytes. 
Since we know that the value of d is always from 1 to 31, 
value of m is from 1 to 12, we can optimize the space using bit fields.

************************************************************************/

#include <stdio.h>
 
// A space optimized representation of date
struct date
{
   // d has value between 1 and 31, so 5 bits
   // are sufficient
   unsigned int d: 5;
 
   // m has value between 1 and 12, so 4 bits
   // are sufficient
   unsigned int m: 4;
 
   unsigned int y;
};
 

 // Space optimized representation of the date
struct date_signed {
    // d has value between 0 and 31, so 5 bits
    // are sufficient
    signed int d : 5;

    // m has value between 0 and 15, so 4 bits
    // are sufficient
    signed int m : 4;

    signed int y;
};

int main()
{
   printf("Size of date is %ld bytes\n", sizeof(struct date));
   struct date dt = {21,10, 2015};
   printf("Date is %d/%d/%d\n", dt.d, dt.m, dt.y);

   
	printf("Size of date is %ld bytes\n", sizeof(struct date_signed));
   struct date_signed sdt = {31,12, 2015};
   printf("Date is %d/%d/%d\n", sdt.d, sdt.m, sdt.y);

   return 0;
}

/*
:
While using signed int for bit fields is standard, 
the exact packing and alignment of bit fields within a structure can be implementation-defined.
This means that a structure containing bit fields might have a different memory layout 
on different compilers or architectures.


(gdb) info locals
dt = {d = 21, m = 10, y = 2015}
sdt = {d = -1, m = -4, y = 2015}
(gdb) p /t dt
$1 = {d = 10101, m = 1010, y = 11111011111}
(gdb) p /t sdt
$2 = {d = 11111111111111111111111111111111, 
  m = 11111111111111111111111111111100, y = 11111011111}

*/
