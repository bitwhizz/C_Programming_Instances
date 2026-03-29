#include<stdio.h>

int main()
{
  char *names[] = {"Miller","Jones","Anderson"};
  printf("%c\n",*(*(names+1)+2));   //n
  printf("%c\n",names[1][2]);       //n

  printf("%s\n",(*(names+1)));    //Jones
  return 0;
}
