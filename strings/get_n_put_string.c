#include <stdio.h>

int main()
{
    char str[100];
    
    printf("Enter a value: ");
    
    // Use fgets instead of gets for safety. 
    // It reads up to 99 characters and leaves room for the null-terminator (\0).
    fgets(str, sizeof(str), stdin);
    
    printf("\nYou entered: ");
    
    // Simply pass the variable name into the function to call it
    puts(str);
    
    return 0;      
}