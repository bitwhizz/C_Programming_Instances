#include <stdio.h>
#include <stdint.h>

// #pragma pack(1)
typedef struct
{
    /* data */
    int8_t hours;
    uint32_t micros;
    uint16_t seconds;
}timebase_t;

int main()
{
    timebase_t t = {.hours=12,.micros=0x12345678,.seconds = 0xDEAD};
    printf("%lu",sizeof(t));
}


/*

(gdb) p sizeof(t)
$1 = 12
(gdb) x &t
0x7fffffffdc74:	0x00007f0c
(gdb) x/12 &t
0x7fffffffdc74:	0x00007f0c	0x12345678	0x0000dead	0x00400540
0x7fffffffdc84:	0x00000000	0xf7a2d840	0x00007fff	0x00000000
0x7fffffffdc94:	0x00000000	0xffffdd68	0x00007fff	0x00000000
(gdb) x/12x &t
0x7fffffffdc74:	0x00007f0c	0x12345678	0x0000dead	0x00400540
0x7fffffffdc84:	0x00000000	0xf7a2d840	0x00007fff	0x00000000
0x7fffffffdc94:	0x00000000	0xffffdd68	0x00007fff	0x00000000
(gdb) x/12b &t
0x7fffffffdc74:	0x0c	0x7f	0x00	0x00	0x78	0x56	0x34	0x12
0x7fffffffdc7c:	0xad	0xde	0x00	0x00
(gdb) x/3xw &t
0x7fffffffdc74:	0x00007f0c	0x12345678	0x0000dead

Afet using  #pragma pack(1)

(gdb) p sizeof(t)
$1 = 7

x Command alternatives : 
x/5xh &t (halfwords)
x/5i  &t  (instr .)
x/5s  &t  (string)

*/