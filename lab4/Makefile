CC=g++
CFLAGS=-c -Wall

all: game #то, что будет по итогу компиляции


game: game.o prog4.o file.o Game.o curses.o Battle.o infile.o alg.o
	$(CC) game.o prog4.o file.o infile.o Game.o Battle.o curses.o alg.o -o game -lncurses -g
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
alg.o: alg.cpp
	$(CC) $(CFLAGS) alg.cpp
Battle.o: Battle.cpp
	$(CC) $(CFLAGS) Battle.cpp
clean:
	rm -rf *.o game
