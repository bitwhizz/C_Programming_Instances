#include <stdio.h>

#define SETREG(reg, pos, width, val) \
    ((reg) = ((reg) & ~(((1U << (width)) - 1) << (pos))) | (((val) & ((1U << (width)) - 1)) << (pos)))

#define GETREG(reg, pos, width) (((reg) >> (pos)) & ((1U << (width)) - 1))

int main(void)
{
    int num = 0;

    num = SETREG(num,4,6,0xf);
    printf("Set = %x\n",num);

    printf("Get = %x\n",GETREG(num,4,6));

    return (0);
}