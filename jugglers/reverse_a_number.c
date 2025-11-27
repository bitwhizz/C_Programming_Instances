/*
Write a code to reverse a number

To reverse a number, you need to take the digits of the number and rearrange them in the opposite order.

    Start by converting the number to a string, reverse that string, and then convert it back to an integer. This will give you the reversed version of the original number.
    Example: If the number is 908701, take digits from last → 1, 0, 7, 8, 0, 9 → and make it 107809.

*/
#include<stdio.h>

int main() {
  //Initialization of variables where rev='reverse=0'
  int number, rev = 0, store, left;

  //input a numbers for user
  printf("Enter the number\n");
  scanf("%d", & number);

  store = number;
  //use this loop for check true condition
  while (number > 0) {
    //left is for remider are left
    left = number % 10;

    //for reverse of no.
    rev = rev * 10 + left;

    //number /= 10;
    number = number / 10;

  }
  //To show the user value
  printf("Given number = %d\n", store);

  //after reverse show numbers
  printf("Its reverse is = %d\n", rev);

  return 0;
}