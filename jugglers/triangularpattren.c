#include<stdio.h>
void main()
{
	int n=0;
	int index=0,pattern=0,space=0;
	int c=1;	//c = *;
	
	printf("enter the no of rows:");
	scanf("%d",&n);
	for (index=1;index<=n;index++)
	{
	  for(space=n-index;space>=1;space--)
	    {
	      printf(" ");
	    }

	for(pattern=1;pattern<=(2*index)-1;pattern++)
	  {
	    printf("%d",c);
	  }
	printf("\n");
	}
}

