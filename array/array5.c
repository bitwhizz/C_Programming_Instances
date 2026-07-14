#include<stdio.h>

pass(int m[][4])				
{
	int i,j;

	int rows = (sizeof(m)*sizeof(m[0][0]))/sizeof(m[0]);
	int columns = sizeof(m[0]) / sizeof(m[0][0]);

	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
printf("\n");
}

pass_to_pointer(int (*m)[4])				
{
	int i,j;

	for(i=0;i<2;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ",*(*(m+i)+j));
		}
		printf("\n");
	}
}


int main()
{
	int a[][4]={1,2,3,4,5,6,7,8};
	pass(a);
	pass_to_pointer(a);
}

/*
(gdb) p sizeof(m)
$5 = 8
(gdb) p sizeof(m[0][0])
$6 = 4
(gdb) 4 * 8

(gdb) p sizeof(m[0])
$8 = 16
*/