CC=g++
CFLAGS=-c -Wall

all: game #то, что будет по итогу компиляции


game: game.o prog4.o file.o container.o
	$(CC) game.o prog4.o file.o container.o -o game -lncurses -g
container.o: container.cpp
	$(CC) $(CFLAGS) container.cpp
game.o: game.cpp
	$(CC) $(CFLAGS) game.cpp -lncurses
file.o: file.cpp
	$(CC) $(CFLAGS) file.cpp -lncurses
prog4.o: prog4.cpp
	$(CC) $(CFLAGS) prog4.cpp -lncurses

clean:
	rm -rf *.o game
