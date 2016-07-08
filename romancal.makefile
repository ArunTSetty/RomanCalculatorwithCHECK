CFLAGS=-Wall

LIBS =`pkg-config --cflags --libs check`

all: romancal

romancal: main.o implementation.o
	gcc -o romancal main.o implementation.o

main.o: main.c implementation.h
	gcc $(CFLAGS) -c main.c

implementation.o: implementation.c implementation.h
	gcc $(CFLAGS) -c implementation.c

test: romancal-test
	./romancal-test

romancal-test: implementation-test.o implementation.o
	gcc -o romancal-test implementation.o implementation-test.o $(LIBS)

implementation-test.o: implementation-test.c implementation.h
	gcc $(CFLAGS) -c implementation-test.c

implementation-test.c: implementation-test.check
	~/checkmk implementation-test.check >implementation-test.c
