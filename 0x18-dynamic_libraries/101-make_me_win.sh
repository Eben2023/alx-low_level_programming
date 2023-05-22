#!/bin/bash
echo -e '#include <stdio.h>\nunsigned long int strtoul(const char *nptr, char **endptr, int base) { return 1; }' > fake_strtoul.c
gcc -shared -o fake_strtoul.so -fPIC fake_strtoul.c
LD_PRELOAD=./fake_strtoul.so ./gm 9 8 10 24 75 9
