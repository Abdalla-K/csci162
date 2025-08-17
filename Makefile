#Abdalla Kharoub
#665282497

CC = gcc
CFLAGS = -Wall -Wextra -g

Target = bin/main

OBJS = src/main.o src/convert.o

all: $(Target)

bin/main: src/main.o src/convert.o
	$(CC) $(CFLAGS) -o $(Target) $(OBJS) -lm

main.o: src/main.c include/convert.h
	$(CC) $(CFLAGS) -c $<

convert.o: src/convert.c include/convert.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(Target) $(OBJS)