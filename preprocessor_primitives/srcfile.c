/*
To prevent same header file getting included multiple times.

The ifndef will check whether macro HDRFILE_H_ is defined or not. 
If it is not defined, it will define the macro.
From next time onward the statements inside ifndef will not be included.
*/
#ifndef _HDRFILE_H_

#define _HDRFILE_H_

#endif

#include "hdrfile.h"

int main(void)
{
    say_hello();
}