#include <stdio.h>
#include <string.h>

/* define simple structure */
struct
{
unsigned int widthValidated;
unsigned int heightValidated;
} status1;

/* define a structure with bit fields */
struct
{
unsigned int widthValidated : 1;
unsigned int heightValidated : 1;
} status2;

int main( )
{
	printf( "Memory size occupied by status1 : %d\n", sizeof(status1));
	printf( "Memory size occupied by status2 : %d\n", sizeof(status2));
	return 0;
}

/*
(gdb) ptype status1
type = struct {
    unsigned int widthValidated;
    unsigned int heightValidated;
}
(gdb) ptype status2
type = struct {
    unsigned int widthValidated : 1;
    unsigned int heightValidated : 1;
}
(gdb) sizeof(status1)
Undefined command: "sizeof".  Try "help".
(gdb) p sizeof(status1)
$5 = 8
(gdb) p sizeof(status2)
$6 = 4

*/