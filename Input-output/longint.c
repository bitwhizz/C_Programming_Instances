/*4. Print an entered long int.*/

/*
The modifier h can be used before conversion specification d,i,o,u,x to specify short integer,
likewise the modifier l can be used to specify long integer.
*/


#include<stdio.h>
main()
{
	long int a;
	scanf("%ld",&a);
	printf("%ld\n",a);
}
/*for long integer the defining symbol is %ld,
here we r printing long int and scanf is used to enter no in 
terminal windows itself,this gives command option in o/p window itself*/
