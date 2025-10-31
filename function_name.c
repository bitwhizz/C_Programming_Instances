/*
 * function_name.c
 *
 *  Created on: 30-Dec-2018
 *      Author: saif
 */



#include "stdio.h"

void foo(void)
{
   printf("func : %s\n",__func__);
   printf("file : %s\n",__FILE__);
   printf("line : %d\n",__LINE__);
}

void bar(void)
{
	printf("%s\n",__func__);
}

int main()
{
   foo();
   bar();
   return 0;
}


