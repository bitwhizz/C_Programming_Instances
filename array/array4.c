#include<stdio.h>
int main()
{
	int i;
	int j=100;
	int m[5]={10,20,30,40,50};
	
	m[-1]=200;
	
	for(i=0;i<5;i++)
	{
		printf("m[%d] address=%x\n",i,(int)&m[i]);
		printf("m[%d] values=%d\n",i,m[i]);
	}
	printf("address of m[-1]=%x\n",(int)&m[-1]);
	printf("address of i=%x\n",(int)&i);
	printf("address of m[6]=%x\n",(int)&m[6]);
	printf("address of j=%x\n",(int)&j);
	printf("value of i=%d\n",i);
	printf("value of j=%d\n",j);
	printf("\n");
        return 0;
}
