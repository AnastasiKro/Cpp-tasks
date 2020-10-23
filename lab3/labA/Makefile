
CFLAGS=-c -Wall

all: lab3 #то, что будет по итогу компиляции
lab3: main3.o prog3.o 
	g++ main3.o prog3.o -o lab3
main.o: main3.cpp
	g++ -c main3.cpp
prog3.o: prog3.cpp
	g++ -c prog3.cpp

clean:
	rm -rf *.o lab3
