#include <stdio.h>
#include <string.h>

char *_strcpy(char str1[],char str2[])
{
    int i=0;
    while(str2[i]!='\0')
    {
        str1[i]=str2[i];
        i++;
    }
    str1[i]='\0';
    return str1;
}

int main(void)
{
    char str1[10],str2[10];

    printf("Enter the first string  : ");
    scanf("%s",str1);
    printf("Enter the second string : ");
    scanf("%s",str2);

    _strcpy(str1,str2);
    printf("First string : %s \t\t Second string : %s\n",str1,str2);
    _strcpy(str1,"cocacola");
    _strcpy(str2,"pepsi");    
    printf("First string : %s \t\t Second string : %s\n",str1,str2);   
}


/*
Enter the first string  : Apple
Enter the second string : Avocado
First string : Avocado 		 Second string : Avocado
First string : cocacola 		 Second string : pepsi
*/