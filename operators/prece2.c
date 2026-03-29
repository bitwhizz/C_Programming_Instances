#include<stdio.h>
main()
{
	char a,b= -1,c= -2,d= 3,e= 5;
	a= ++b || --c && ! d++;
	return 0;
}

/*
(gdb) info locals
a = 0 '\000'
b = 0 '\000'
c = -3 '\375'
d = 4 '\004'
e = 5 '\005'
*/
