#!/bin/bash

# Get all the .c files in the current directory
c_files=$(ls *.c)

# Check if there are any .c files
if [[ -z "$c_files" ]]; then
  echo "Error: No .c files found in the current directory."
  exit 1
fi

# Compile all .c files with flags for dynamic library creation
objects=""
for file in $c_files; do
  gcc -c -fPIC -Wall -Wextra "$file" -o "${file%.c}.o"
  objects="$objects ${file%.c}.o"
done

# Link all object files into the dynamic library
gcc -shared -o liball.so $objects

# Remove object files (optional)
# rm -f *.o

echo "Dynamic library 'liball.so' created successfully!"