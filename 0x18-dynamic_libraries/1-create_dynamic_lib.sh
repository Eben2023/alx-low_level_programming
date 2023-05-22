#!/bin/bash

# Collect all the .c files in the current directory
c_files=$(find . -maxdepth 1 -type f -name '*.c')

# Compile the .c files into object files
gcc -c -Wall -Werror -fpic ${c_files}

# Create the dynamic library
gcc -shared -o liball.so *.o

# Clean up object files
rm -f *.o
