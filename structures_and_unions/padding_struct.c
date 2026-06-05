/*
Most modern CPUs do not read data from memory 1 byte at a time. Instead, they read memory in chunks of word sizes (typically 4 bytes on a 32-bit system, or 8 bytes on a 64-bit system).

To maximize efficiency, the CPU expects data types to be stored at memory addresses that are multiples of their own size:

    A char (1 byte) can be stored at any address.

    A short (2 bytes) should be stored at an even address (multiple of 2).

    An int or float (4 bytes) should be stored at an address divisible by 4.

    A double or long long (8 bytes) should be stored at an address divisible by 8.

If data is misaligned, the CPU might have to make two memory accesses instead of one to fetch a single variable, severely degrading performance.

*/

#include<stdio.h>

struct a
{
short int a;
char b;
short int c;
char d;
};

int main()
{
	printf("%d \n",sizeof(struct a));
}


/*
Aligned vs. Misaligned Memory AccessLet's look at how a 32-bit architecture fetches a 4-byte integer (int) depending on its position in these banks.
Scenario 1: Aligned Data (With Padding)If an integer is stored at a memory address that is a multiple of 4 (e.g., address 0x00), it maps perfectly across the banks:
Byte 0 → Bank 0
Byte 1 → Bank 1
Byte 2 → Bank 2
Byte 3 → Bank 3
CPU Action: The CPU issues a request for address 0x00. 
The memory controller activates all 4 banks at once and retrieves the entire integer in 1 memory cycle.

Scenario 2: Misaligned Data (Without Padding)If you packed your structure and the integer got pushed to address 0x01, its bytes are now split like this:
Byte 0 → Bank 1 (at address row 0)
Byte 1 → Bank 2 (at address row 0)
Byte 2 → Bank 3 (at address row 0)
Byte 3 → Bank 0 (at address row 1 — the next row of memory)

CPU Action: The CPU cannot read two different rows of a memory bank at the same time.
Therefore, it must perform 2 memory cycles:Cycle 1: Read the first row to get bytes 0, 1, and 2 from Banks 1, 2, and 3.

Cycle 2: Read the second row to get byte 3 from Bank 0.Shift & Merge: The CPU internally shifts and glues these pieces together before your code can use it.

Compiler structure padding is simply the compiler looking at your data types, looking at the layout of the hardware memory banks, 
and intentionally leaving certain banks empty (inserting slack bytes) so that the next heavy variable aligns perfectly with Bank 0.
*/
