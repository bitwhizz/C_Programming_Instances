#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[10],str2[10];

    printf("Enter the first string  : ");
    scanf("%s",str1);
    printf("Enter the second string : ");
    scanf("%s",str2);

    if((_strcmp(str1,str2))==0)
        printf("strings are same \n");
    else
        printf("String are not same \n");
}

int _strcmp(char str1[],char str2[])
{
    int i=0;

    while(str1[i]!='\0' && str2[i] != '\0' && str1[i] == str2[i])
        i++;

        if(str1[i] == str2[i])
            return 0;
        else
            return ((str1[i]) - str2[i]);
}
