/*
Write code to Calculate frequency of characters in a string

This problem asks to calculate the frequency of each character in a given string.

    The goal is to determine how many times each character appears in the string.
    Example for string “hello”:
        ‘h’ appears 1 time
        ‘e’ appears 1 time
        ‘l’ appears 2 times
        ‘o’ appears 1 time

*/

#include<stdio.h>

int main() {
  //Initializing variables.
  char str[100];
  int i;
  int freq[256] = {
    0
  };

  //Accepting inputs.
  printf("Enter the string: ");
  gets(str);

  //Calculating frequency of each character.
  for (i = 0; str[i] != '\0'; i++) {
    freq[str[i]]++;
  }

  //Printing frequency of each character.
  for (i = 0; i < 256; i++) {
    if (freq[i] != 0) {
      printf("The frequency of %c is %d\n", i, freq[i]);
    }
  }
  return 0;
}