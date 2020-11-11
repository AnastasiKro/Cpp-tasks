#include <ncurses.h>
#include <cstring>

int main(){
	int row=20; int col=20;;
	initscr();
	wresize(stdscr, 20, 20);
	getmaxyx(stdscr,row, col); 
	int flag = 0;

	while(flag == 0){
	//wprintw(stdscr, "aaa");
	mvwprintw(stdscr,row/2, col/2, "aaa");
	getch();	
	}
	endwin();
	return 0;
}
