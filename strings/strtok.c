#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *_strtok(char *str,const char delim)
{
    static char *previous_state;
    char *token;

    if(str == NULL)
        str = previous_state;

    //skip up-front delims
    while(*str && *str == delim)
        str++;

    if(!(*str)) {
        previous_state = str;
        return NULL;
    }

    //save token start
    token = str;

    //search for delimeter
    for(;*str && (*str != delim); str++);

    if(*str == 0) {
        previous_state = str;
    }
    else {
        *str = '\0';
        previous_state = str + 1;
    }

    return token;
}

#define BUFFER_SIZE 1024

void tokenize_test(void){
    char *string_to_split = malloc(BUFFER_SIZE);
    sprintf(string_to_split,"Chamomile ,lavender ,Melissa ,frankincense");

    char *token = _strtok(string_to_split, ',');
    int token_count = 0;

    while(token){
        printf("%d:  %s\n",token_count++, token);
        token = _strtok(NULL, ',');
    }
}

int main(){
    tokenize_test();
    return EXIT_SUCCESS;
}