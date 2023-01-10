CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal $(shell pkg-config --cflags check)

all: my_lib.dll my_lib.so test.exe

test.exe: test.o lib.o
	$(CC) -o test.exe test.o lib.o `pkg-config --cflags --libs check`

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $< -o $@

my_lib.dll: lib.o
	$(CC) -shared lib.o -o lib.dll

my_lib.so: lib.o
	$(CC) -shared -o lib.so lib.o

.PHONY: clear

clear:
	rm -r -f *.o *.exe *.a *.so *.dll
