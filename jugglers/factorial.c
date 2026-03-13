/*29. Write a program to display the factorial of an entered integer */
#include<stdio.h>
int main()
{
	int num,i;
	scanf("%d",&num);

	int factorial=1;
	int multiplier=num;

	for(i=1;i<=num;i++)
	{
		factorial=factorial*multiplier;
		--multiplier;
	}
	printf("%d\n",factorial);
}
