CC=g++
CFLAGS=-c -Wall

all: game #то, что будет по итогу компиляции


game: game.o prog4.o file.o Game.o curses.o infile.o
	$(CC) game.o prog4.o file.o infile.o Game.o curses.o -o game -lncurses -g
game.o: game.cpp
	$(CC) $(CFLAGS) game.cpp -lncurses
file.o: file.cpp
	$(CC) $(CFLAGS) file.cpp -lncurses
prog4.o: prog4.cpp
	$(CC) $(CFLAGS) prog4.cpp -lncurses
Game.o: Game.cpp
	$(CC) $(CFLAGS) Game.cpp
curses.o: curses.cpp
	$(CC) $(CFLAGS) curses.cpp
infile.o: infile.cpp
	$(CC) $(CFLAGS) infile.cpp
clean:
	rm -rf *.o game
