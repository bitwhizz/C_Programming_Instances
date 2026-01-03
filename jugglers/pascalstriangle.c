#include<stdio.h>
void main()
{
	int noofRows;
	printf("number of rows to be printed\n");
	scanf("%d",&noofRows);
	int row,colspaces,colchar;
	for(row=0;row<noofRows;row++)
	{
		for(colspaces=noofRows-row;colspaces>=1;colspaces--)
		{
		printf(" ");
		}
		int printchar=1;
		int num=row;
		int den=1;
		for(colchar=0;colchar<=row;colchar++)
		{
			printf("%d",printchar);
			printchar=printchar*num;
			printchar=printchar/den;
			num--;
			den++;
		}
		printf("\n");
	}
}
/*
number of rows to be printed
10
          1
         11
        121
       1331
      14641
     15101051
    1615201561
   172135352171
  18285670562881
 193684126126843691

*/