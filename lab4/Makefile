CC=g++
CFLAGS=-c -Wall

all: game #то, что будет по итогу компиляции


game: game.o prog4.o
	$(CC) game.o prog4.o -o game -lncurses -g

game.o: game.cpp
	$(CC) $(CFLAGS) game.cpp -lncurses

prog4.o: prog4.cpp
	$(CC) $(CFLAGS) prog4.cpp -lncurses

clean:
	rm -rf *.o game
