/*
unions have a similar appearace to structs, but the memory layout has one crucial difference.
Instead of each member being stored affter the end of the previous one, all the members have an offset of zero.
The storage for the individual members is thus overlaid : only one member at a time can be strored there.
*/

#include<stdio.h>
union my
{
	int a;
	char b;
	short int c;
}
main()
{
	union my example;
	example.a = 256;
	printf("a=%d\n",example.a);
	example.b = 128;
	printf("b=%u\n",example.b);
	example.c = 1;
	printf("c=%hd\n",example.c);
}

