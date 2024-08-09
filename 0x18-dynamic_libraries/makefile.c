CC = gcc
CFLAGS = -fPIC -Wall -Wextra -shared -I/usr/include/python3.X  # Replace X with your Python version

all: 100-operations.so

100-operations.so: 100-operations.c
    $(CC) $(CFLAGS) -o 100-operations.so 100-operations.c

clean:
    rm -f 100-operations.so