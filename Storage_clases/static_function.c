/*
Unlike global functions in C , access to statis functions is restricted to the file (or translation unit) where they are declared (internal linkage).

Therefore , when we want to restrict access to functions, we make them static.
Another reason fo making functions static can be the reuse of the same function name in other files.

By making a function static we can achive two things.

* Data hiding as we can hide the function from otehr traslation units or files.
* Avaoiding function name clashes in multi-file program.

*/

#include<stdio.h>
static add(int a,int b)
{
	printf("add=a+b= %d\n",a+b);
	return 0;
}

