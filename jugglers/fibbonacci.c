/*
The Fibonacci series is a sequence of numbers where each number
 is the sum of the two preceding ones.
 It usually starts with 0 and 1.

The Sequence

The first few numbers in the series are: 
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144...
*/

#include<stdio.h>

int main(void)
{
	long x,y,z;
	int i,n;
	x=0;
	y=1;
	
	printf("enter the number of terms: ");
	scanf("%d",&n);
	printf("%ld  ",y);

	for(i=1;i<n;i++)
	{
		z=x+y;
		printf("%ld   ",z);
		x=y;
		y=z;
	}
	printf("\n");
}
