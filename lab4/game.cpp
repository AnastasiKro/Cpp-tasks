//#include <iostream>
#include <ncurses.h>
#include <iostream>
#include "lab4.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace Necromancer;
bool gameOver;
//Alive[5] enemies;


enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
const int width=20;
const int height=20;
int x, y, en_x, en_y, un_x, un_y;
eDirection dir;
std::vector <Undead> u;
std::vector <Undead> :: iterator it;
std:: vector <tab> T;
std::vector <tab> :: iterator iter;
void SetUp(){
	gameOver = false;
	dir = STOP;
	x = width/2;
	y = 0;
}

void Draw(Alive* e,Myself& me,int n){
	mvprintw(24, 1,"%d\n", x);
	printw("%d\n", y);
	printw("W - Werewolf, O - ogr, G - goblin, D - dwarf, T - troll\n");
	printw("g - gul, gh - ghowl, s - skeleton, z - zombie\n");
	for(int i = 0; i<width+1; i++)
		printw("#");
	printw("   level: %d; hp: %d, experience: %d, mana: %d, fraction: %d", me.getlevel(), me.gethp(), me.getexp(), me.getmana(), me.getfr());
	printw("\n");
	for (int i = 0; i<height+1; i++){
		for (int j = 0; j<width+1; j++){
			if (j==0 || j == width){
				printw("#");
			}
			int p = -10;
			if (j == x && i == y){
				printw("@");
				p = -1;
			}
			
			for (int k = 0; k<n; k++){
			if (j == e[k].getx() && i == e[k].gety()){
				p = k;
				if (e[k].getname() == "Werewolf")
					printw("W");
				if (e[k].getname() == "Ogr")
					printw("O");
				if (e[k].getname() == "Goblin")
					printw("G");
				if (e[k].getname() == "Troll")
					printw("T");
				if (e[k].getname() == "Dwarf")
					printw("D");
				}
			}
			for (it = u.begin(); it<u.end(); it++)
				if (j ==it->getx() && i == it->gety()){
					if (it->gettype() == "skeleton")
						printw("s");
					if (it->gettype() == "gul")
						printw("g");
					if(it->gettype() == "ghowl")
						printw("gh");
					if (it->gettype() == "zombie")
						printw("z");
					p = -2;
				}
		
			 if ( p == -10)
				printw(" ");
			 if ((p> -1) && (e[p].getx() < x+3) && (e[p].getx()>x-3)&& (e[p].gety() >y-3) && (e[p].gety()< y+3)){
				 printw(" %s, exp: %d, hp: %d, fraction: %d", e[p].getname().c_str(), e[p].getexp(), e[p].gethp(), e[p].getfr());
			 }
			 
		}	
		printw("\n");
	}
	for(int i = 0; i<width+1; i++)
		printw("#");
	printw("\n");
}
void Input(Alive* e, Myself& me, int n){
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
					//e[i].setx(-10);e[i].sety(-10);
					 }}
				break;
			case 'D':
				for (int i = 0; i<n; i++){
				if (e[i].getx() <x+3 && e[i].getx()>x-3&&e[i].gety()<y+3 && e[i].gety()>y-3){
					me.draining_mana(e[i]);
					e[i].setx(-10);e[i].sety(-10); }}
				break;
			case 's':
				for (int i = 0; i<n; i++){
				if (e[i].getx() <x+3 && e[i].getx()>x-3&&e[i].gety()<y+3 && e[i].gety()>y-3){
					u =me.necromancy(e[i], 's', u);
					e[i].setx(-10);
					e[i].sety(-10);
				}
				}	
			//	if (en_x <x+2 && en_x>x-2&&en_y<y+2 && en_y>y-2){
			//		Undead u =me.necromancy(e);
				break;
			case 'g':
				for (int i = 0; i<n; i++){
				if (e[i].getx() <x+3 && e[i].getx()>x-3&&e[i].gety()<y+3 && e[i].gety()>y-3){
					u =me.necromancy(e[i], 'g', u);
					e[i].setx(-10);
					e[i].sety(-10);
				}
				}
				break;
			case 'f':
				for (int i = 0; i<n; i++){
				if (e[i].getx() <x+3 && e[i].getx()>x-3&&e[i].gety()<y+3 && e[i].gety()>y-3){
					u =me.necromancy(e[i], 'f', u);
					e[i].setx(-10);
					e[i].sety(-10);
				}
				}
				break;
			case 'z':
				for (int i = 0; i<n; i++){
				if (e[i].getx() <x+3 && e[i].getx()>x-3&&e[i].gety()<y+3 && e[i].gety()>y-3){
					u =me.necromancy(e[i], 'z', u);
					e[i].setx(-10);
					e[i].sety(-10);
				}
				}
				break;
			case 'x':
				gameOver= true;
				break;
			default:
				for (int i = 0; i<n; i++){
					if (e[i].getcond()==1 && e[i].getx() <x+3 && e[i].getx()>x-3&&e[i].gety()<y+3 && e[i].gety()>y-3){
					
						int a = rand()%10000;
						if (a == 1){
							int b =me.wounded(e[i]);
							if (b==0)
								gameOver = true;
							}
						}
				}
		}
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

int printenu(){
	for (it = u.begin(); it<u.end(); it++){
		std::cout<<it->getname()<<std::endl;
		std::cout<<" "<<it->getx()<<" "<<it->gety()<<std::endl;
		//printw("%s", e[i].getname());
		//printw("\n%d\n", e[i].getx());
		//printw("%d\n", e[i].gety());
	}
	return 0;
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
	//wresize(stdscr, 22, 22);
	int n = 0;
	//Alive* e;
       	Alive* e =Readfile( &n);
	//std::vector <Undead> u;
	Myself me= Readme();
	while (!gameOver){
	//	printen(e, n);
		Draw(e, me, n);
		Input(e, me, n);
		Logic();
	}
	endwin();
	printenu();
	return 0;
}

