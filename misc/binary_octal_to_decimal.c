#include<stdio.h>

unsigned int func(unsigned int n,unsigned int base);

int main()
{
  int num,base,result;
  char choice;
  printf("Enter 'b' for binary and 'o' for octal : \n");
  scanf("%c",&choice);
  printf("Enter the number : ");
  scanf("%d",&num);

  if(choice == 'b')
  base = 2;
  else
  base = 8;
  result = func(num,base);
  printf("Decimal number is %d\n",result);
}

unsigned int func(unsigned int binary,unsigned int base)
{
  int reminder,temp,pow=1,decimal = 0;

  while(binary >0)
  {
    reminder = binary%10;  //taking the last digit

    temp=reminder*pow;
    decimal+=temp;
    pow*=base;    //add the weighted value

    binary/=10;  // skipping the last digit
  }
  return decimal;
}
