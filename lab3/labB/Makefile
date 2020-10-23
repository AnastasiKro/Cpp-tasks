CC=g++
CFLAGS=-c -Wall

all: lab3 #то, что будет по итогу компиляции


lab3: main3.o Dialog.o prog3.o 
	$(CC) main3.o Dialog.o prog3.o -o lab3

main3.o: main3.cpp
	$(CC) $(CFLAGS) main3.cpp

Dialog.o: Dialog.cpp
	$(CC) $(CFLAGS) Dialog.cpp

prog3.o: prog3.cpp
	$(CC) $(CFLAGS) prog3.cpp

clean:
	rm -rf *.o lab3
