#!/bin/bash

# Collect all .c files in the current directory
C_FILES=$(ls *.c 2>/dev/null)

# Check if any .c files exist
if [ -z "$C_FILES" ]; then
  echo "Failure!!! No .c files in current directory."
  exit 1
fi

# Compile each .c file into individual object files
for file in $C_FILES; do
  gcc -c -fPIC "$file" -o "${file%.c}.o"
done

# Create the dynamic library from the object files
gcc -shared -o liball.so *.o

# Clean up object files
rm *.o

echo "Success!!! Dynamic library was creaated!"
