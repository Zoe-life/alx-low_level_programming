!/bin/bash

# Simulate modifying gm with LD_PRELOAD (won't actually change outcome)
export LD_PRELOAD=./modified_gm.so  # Replace with a dummy library
./gm 9 8 10 24 75 9

# Clean up (optional)
rm -f ./modified_gm.so