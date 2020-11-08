//#include <iostream>
#include <ncurses.h>
#include <iostream>
#include "lab4.h"
#include <string>
#include <fstream>
#include <cstdlib>
using namespace Necromancer;
bool gameOver;
//Alive[5] enemies;


enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
const int width=20;
const int height=20;
int x, y, en_x, en_y, un_x, un_y;
eDirection dir;

void SetUp(){
	gameOver = false;
	dir = STOP;
	x = width/2;
	y = 0;
	//Alive e("ogr", 5, 3, 2, 1, 1);
	en_x = 10; en_y = 2; un_x = -1; un_y = -1;
}

void Draw(Alive* e,Myself& me,int n){
	//initscr();
	printw("%d\n", x);
	printw("%d\n", y);
	//system("clear");
	for(int i = 0; i<width+1; i++)
		printw("#");
	printw("   level: %d; hp: %d, experience: %d, mana: %d, fraction: %d", me.getlevel(), me.gethp(), me.getexp(), me.getmana(), me.getfr());
	printw("\n");
	
	for (int i = 0; i<height+1; i++){
		for (int j = 0; j<width+1; j++){
			if (j==0 || j == width){
				printw("#");
			}
			int p = 0;
			if (j == x && i == y){
				printw("@");
				p = 1;
			}
			
			for (int k = 0; k<n; k++){
			if (j == e[k].getx() && i == e[k].gety()){
				p = 1;
				printw("$");}
			}
			//else if (j == un_x && i == un_y)
			//	printw("G");
			 if ( p == 0)
				printw(" ");
		}	
		printw("\n");
	}
	for(int i = 0; i<width+1; i++)
		printw("#");
	printw("\n");
	//printw("%d", un_x);
	//printw("%d", un_y);
	
}
void Input(Alive* e, Myself& me, int n){
	/*initscr();
	cbreak();
	noecho();
	scrollok(stdscr, TRUE);
	nodelay(stdscr, TRUE);*/
//	while(TRUE){
		//char x = getch();
	//if (_kbhit()){//проверка, нажата ли клавиша
		switch(getch())// какая именно клавиша нажата
		{
			
			case 'h':
				printw("%d\n", x);
				dir = LEFT;
				if (x>0)
					x--;
				break;
			case 'j':
				dir = UP;
				if (y>0)
					y--;
				break;
			case 'k':
				dir = RIGHT;
				if(x<width-1)
					x++;
				break;
			case 'l':
				dir = DOWN;
				if (y<height)
					y++;
				break;
			case 'd':
				for (int i = 0; i<n; i++){

				if (e[i].getx() <x+3 && e[i].getx()>x-3&&e[i].gety()<y+3 && e[i].gety()>y-3){
					me.draining_hp(e[i]);
					e[i].setx(-1);e[i].sety(-1); }}
				break;
			case 'D':
				for (int i = 0; i<n; i++){
				if (e[i].getx() <x+3 && e[i].getx()>x-3&&e[i].gety()<y+3 && e[i].gety()>y-3){
					me.draining_mana(e[i]);
					e[i].setx(-1);e[i].sety(-1); }}
				break;
			case 'n':
			//	if (en_x <x+2 && en_x>x-2&&en_y<y+2 && en_y>y-2){
			//		Undead u =me.necromancy(e);
				un_x = en_x;
				un_y = en_y;
				en_x=-1; en_y = -1;//}
				break;
			case 'x':
				gameOver= true;
				break;
		//	default:
		//		printw("hllo");
		//		break;

		}
	//	break;
		//printw("aaa");
	//}
}
void Logic(){
/*	switch (dir){
		case LEFT:
		//	printw("hhh");
			if (x>1)
				x--;
			break;
		case RIGHT:
			if (x<width)
				x++;
			break;
		case UP:
			if (y<height)
				y++;
			break;
		case DOWN:
			if (y>1)
				y--;
			break;/
	}*/
}
Alive* Readfile(Alive* e, int* n){
	//e = new Alive[1];
	char line[10];
	//char x[2]; char y[2];
	//std::string line;
	//if (j==1)
	//	std::ifstream in("/home/avtobus/3sem/lab2/3sem/lab4/enemies");
	//else
		std::ifstream in("/home/avtobus/3sem/lab2/3sem/lab4/enemies");
	if (in.is_open()){
		while (!in.eof()){
			in.getline(line, 10);
			if (in.eof())
				break;
			char* x1 = new char[3];
			*n+=1;
			Alive* ee = new Alive[*n];
			for (int i = 0; i<*n-1; i++)
				ee[i]=e[i];
			ee[*n-1].setname(line);
			//printw(line);
			in.getline(x1, 3);
			ee[*n-1].setx(atoi(x1));
			//std::cout<<x1<<std::endl;
			//if (in.eof())
			//	break;
			in.getline(x1,3);
			//std::cout<<y1<<std::endl;
			ee[*n-1].sety(atoi(x1));
			delete[] e;
			delete[] x1;// delete[] y1;
			e = ee;
			//if (in.eof())
			//	break;
		}
	}
	in.close();
	return e;
}

int printen(Alive* e, int n){
	for (int i = 0; i<n; i++){
		printw("%s", e[i].getname());
		printw("\n%d\n", e[i].getx());
		printw("%d\n", e[i].gety());
	}
	return 0;
}
int main(){
	SetUp();
	//while (!gameOver){
	initscr();
	cbreak();
	noecho();
	scrollok(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	int n = 0;
	Alive* e;
       	e =Readfile(e, &n);
	Myself me;
	while (!gameOver){
		printen(e, n);
		Draw(e, me, n);
		Input(e, me, n);
		Logic();
	}
	endwin();
	
	return 0;
}

