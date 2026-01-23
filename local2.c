#include<stdio.h>
int main()
{
	int local;
	{
		/*
		Duplicate variable names declared within a local block take 
		precedence over variables with the same name declared outside
		the local block.
		*/
		int local=10;
		printf("local=%d\n",local);
	}
	/*
	Also notice that when the if statement local block had ended,
	 the program had reentered the scope of the original test_var,
	 and its value was 0.
	*/
	printf("local=%d\n",local);
	return 0;
}
/*here local=10 block executes first to give 10*/
/*int local executes but does't prints ,it prints after block 1*/
