CC=g++
CFLAGS=-c -Wall

all: game #то, что будет по итогу компиляции


game: game.o prog4.o file.o
	$(CC) game.o prog4.o file.o -o game -lncurses -g

game.o: game.cpp
	$(CC) $(CFLAGS) game.cpp -lncurses
file.o: file.cpp
	$(CC) $(CFLAGS) file.cpp -lncurses
prog4.o: prog4.cpp
	$(CC) $(CFLAGS) prog4.cpp -lncurses

clean:
	rm -rf *.o game
