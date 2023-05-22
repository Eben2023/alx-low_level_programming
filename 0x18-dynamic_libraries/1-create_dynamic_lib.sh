#!/bin/bash
c_files=$(find . -maxdepth 1 -type f -name '*.c')
gcc -c -Wall -Werror -fpic ${c_files}
gcc -shared -o liball.so *.o
