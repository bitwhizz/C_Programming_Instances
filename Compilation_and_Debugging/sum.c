#include<stdio.h>


#define A 5


int main()
{
	int a,b,sum;
	scanf("%d %d",&a,&b);
	sum=a+b+A;
	printf("compiled sum:%d\n",sum);
	return 0;
}


/*
1. Preprocessing (-E)

The preprocessor handles directives that begin with #. It expands macros, includes header files, and strips comments.

    Command: gcc -E sum.c -o sum.i

    Output: sum.i (Intermediate preprocessed source code).

    What happens: The #include <stdio.h> is replaced by the actual contents of the header file, and any #define constants are swapped for their literal values.

2. Compilation (-S)

In this stage, the preprocessed code is translated into Assembly Language specific to your computer's architecture (e.g., x86_64).

    Command: gcc -S sum.i -o sum.s

    Output: sum.s (Assembly source code).

    What happens: This is where the compiler performs syntax checking and optimization. If you open program.s, you will see human-readable low-level instructions like movl, addl, and pushq.

3. Assembly (-c)

The assembler takes the assembly code and converts it into Machine Code (binary), creating an "Object File."

    Command: gcc -c sum.s -o sum.o

    Output: sum.o (Object file).

    What happens: This file contains instructions the CPU understands, but it isn't a finished program yet. If your code calls functions from other files or libraries (like printf), those addresses are left as placeholders.

4. Linking (Final Executable)

The linker combines your object file with library object files (like the standard C library) to create the final executable.

    Command: gcc sum.o -o sum

    Output: sum (Executable file).

    What happens: The linker resolves those placeholders, pointing them to the actual memory addresses where the library functions reside.

*/
