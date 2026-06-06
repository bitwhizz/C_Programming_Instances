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


/*
without const :
The RAM Penalty: At startup, the initialization code (called crt0) physically copies those bytes from Flash into a allocated space in your RAM (.data segment).
Result: You are now consuming memory space in both Flash and RAM for the exact same data.

saif@saif-Inspiron-5547:~/programmer/C_Programming_Instances $ size  Storage_clases/static_constant 
   text    data     bss     dec     hex filename
   2064     624       8    2696     a88 Storage_clases/static_constant
saif@saif-Inspiron-5547:~/programmer/C_Programming_Instances $ time Storage_clases/static_constant 
Welcome to the System Console. Type 'help' for options. 
> status
System Status : 100% Operational.
> quit
Exiting ...

real    0m3.829s
user    0m0.003s
sys     0m0.000s

with const : 
The RAM Savings: Because it is marked read-only, the startup code skips copying it to RAM.
Result: When your code needs to read message, the CPU reads it directly out of the Flash/ROM memory.
Your RAM usage for this variable drops to 0 bytes.

saif@saif-Inspiron-5547:~/programmer/C_Programming_Instances $ size  Storage_clases/static_constant 
   text    data     bss     dec     hex filename
   2128     576       8    2712     a98 Storage_clases/static_constant

saif@saif-Inspiron-5547:~/programmer/C_Programming_Instances $ time Storage_clases/static_constant 
Welcome to the System Console. Type 'help' for options. 
> status
System Status : 100% Operational.
> quit
Exiting ...

real    0m9.664s
user    0m0.003s
sys     0m0.000s

*/