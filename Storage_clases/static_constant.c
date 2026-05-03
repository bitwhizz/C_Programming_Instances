/*
using Static const struct is a hallmark of efficient c programming.
using this keywords , you ensure the data is private to the file, immutable and memmory-efficient.

static - limits the isibility of the variable to the file it is defined in.
const - Tells the compiler that the data is read-only. On many systems, this allows the compiler to store the data in the .rodata (read only data) segment 
of the binary, which can save RAM by staying in the Flash/ROM.

This example demonstrates a Command Dispatch Table , where a static const struct is used to map string commands to specific functions.

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Define a function pointer type for our commands
typedef void (*CommandAction)(void);

//Define the function the struct will point to
void handle_help(void){
    printf("Available commands : help, status, quit\n");
}

void handle_status(void){
    printf("System Status : 100%% Operational.\n");
}

//Define stature and the staic const array
//This table is read-only and private to this file.
static const struct{
    const char *name;
    CommandAction execute;
} CommandTable[] = {
    {"help",handle_help},
    {"status",handle_status}
};

#define COMMAND_COUNT (sizeof(CommandTable)/sizeof(CommandTable[0]))

int main(){
    char input[32];
    bool running = true;

    printf("Welcome to the System Console. Type 'help' for options. \n");

    while(running){
        printf("> ");
        scanf("%31s",input);

        if(strcmp(input, "quit") == 0){
            running = false;
            continue;
        }

        bool found = false;
        //look up the command in our static const struct
        for(int i = 0; i < COMMAND_COUNT; i++){
            if(strcmp(input,CommandTable[i].name) == 0){
                CommandTable[i].execute();  //Execute the mapped function
                found = true;
                break;
            }
        }

        if(!found){
            printf("Unknown Command : %s\n",input);
        }
    }

    printf("Exiting ...\n");
    return 0;
}