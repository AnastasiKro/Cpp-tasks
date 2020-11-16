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
//std::vector <tab> :: iterator iter;
std::vector <coef> C;
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
	printw("g - gul, gh - ghost, s - skeleton, z - zombie, p - phantom\n");
	for(int i = 0; i<width+1; i++)
		printw("#");
	printw("   level: %d; hp: %d, experience: %d, mana: %d, fraction: %d, available: ", me.getlevel(), me.gethp(), me.getexp(), me.getmana(), me.getfr());
	std::vector <tab> :: iterator iter;
	for (iter = me.getV().begin(); iter<me.getV().end(); iter++){
		if (iter->charact!=0)
		       printw("%s, ", iter->name.c_str());
	}	
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
					if(it->gettype() == "ghost")
						printw("gh");
					if (it->gettype() == "zombie")
						printw("z");
					if (it->gettype() == "phantom")
						printw("p");
					if (x>j-3 && x<j+3 &&y<i+3 && y>i-3)
						printw(" %s, %s, hp: %d, fraction: %d", it->gettype().c_str(), it->getname().c_str(), it->gethp(), it->getfr());
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
void enemy_attack(Alive* e, Myself& me,int n){
	for (int i = 0; i<n; i++){
		int x1 = e[i].getx(); int y1 = e[i].gety();
		if (e[i].getcond()==1 && x1 <x+3 && x1>x-3&&y1<y+3 && y1>y-3){
			int a = rand()%10000;
			if (a == 1){
				int b =me.wounded(e[i]);
				if (b==0)
					gameOver = true;
				}
		}
		for (int j = 0; j<n; j++){
			int x2 = e[j].getx(); int y2 = e[j].gety();
			if (e[i].getfr()!=e[j].getfr() &&e[i].getcond() == 1&& e[j].getcond() !=0  && x1< x2+3 && x1>x2-3 && y1>y2-3 && y1<y2+3){
				e[i].hitenem(e[j]);}
		}
		for (it = u.begin(); it<u.end(); it++){
			int x2 = it->getx(); int y2 = it->gety();
			if (e[i].getfr() != it->getfr() &&e[i].getcond()==1 && x1 >x2-3 && x1 < x2+3 && y1 >y2-3 && y1 < y2+3){
				int a = rand()%10005;
				if (a == 1)
					it->wounded(e[i]);
				if (a == 2)
					it->hitenem(e[i]);
			}
		}
		int ab = rand()%30000;
		if (e[i].getPr()==1&& ab == 3){
			Undead U =Create_slaves(e[i], u);
			u.push_back(U);
		}
	}
}
void undead_attack(Alive* e, Myself& me, int n){
	for (it = u.begin(); it<u.end(); it++){
		int x1 = it->getx(); int y1= it->gety();
		if (it->getfr()!=1 && x1<x+3 && x1>x-3&& y1>y-3&&y1<y+3){
			int a = rand()%10000;
			if (a==0){
				int b =me.wound(*it);
				if (b == 0)
					gameOver = true;
				}
		}
		std::vector <Undead> :: iterator ij;
		for (ij = u.begin(); ij< u.end(); ij++){
			int x2 = ij->getx(); int y2 = ij->gety();
			if (it->getfr()!=ij->getfr() && x1>x2-3&&x1<x2+3&&y1>y2-3&&y1<y2+3){
				int a = rand()%10000;
				if (a ==0)
					it->hiten(*ij);
				if (a == 1)
					ij->hiten(*it);
			}
		}
		int ab = rand()%30000;
		if (it->getPr()==1 && ab == 4){
			Undead U =create_slaves(*it, u);
			//std::cout<<U.gettype()<<std::endl;
			u.push_back(U);
		}
	}
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
					me.draining(e[i]);
					e[i].setx(-10);e[i].sety(-10);
					 }}
				//for (it = u.begin(); it<u.end(); it++){
					
				break;
			case 'b': 
				for (int i = 0; i<n; i++){

				if (e[i].getx() <x+3 && e[i].getx()>x-3&&e[i].gety()<y+3 && e[i].gety()>y-3){
					me.hit(e[i]); }}
				for (it = u.begin(); it<u.end(); it++){
				if (it->getx() <x+3 && it->getx()>x-3&&it->gety()<y+3 && it->gety()>y-3){
					me.hit(*it); }}		
				break;
			case 's':
				for (int i = 0; i<n; i++){
				if (e[i].getx() <x+3 && e[i].getx()>x-3&&e[i].gety()<y+3 && e[i].gety()>y-3){
					u =me.necromancy(e[i], 's', u, C);
				}}	
				break;
			case 'g':
				for (int i = 0; i<n; i++){
				if (e[i].getx() <x+3 && e[i].getx()>x-3&&e[i].gety()<y+3 && e[i].gety()>y-3){
					u =me.necromancy(e[i], 'g', u, C);
				}}
				break;
			case 'f':
				for (int i = 0; i<n; i++){
				if (e[i].getx() <x+3 && e[i].getx()>x-3&&e[i].gety()<y+3 && e[i].gety()>y-3){
					u =me.necromancy(e[i], 'f', u, C);
				}}
				break;
			case 'z':
				for (int i = 0; i<n; i++){
				if (e[i].getx() <x+3 && e[i].getx()>x-3&&e[i].gety()<y+3 && e[i].gety()>y-3){
					u =me.necromancy(e[i], 'z', u, C);
				}}
				break;
			case 'c':
				for (int i = 0; i<n; i++){
				if (e[i].getx() <x+3 && e[i].getx()>x-3&&e[i].gety()<y+3 && e[i].gety()>y-3){
					me.curse(e[i]);
				}}
				break;
			case 'x':
				gameOver= true;
				break;
			case 'p':
				for (int i = 0; i<n; i++){
				if (e[i].getx() <x+3 && e[i].getx()>x-3&&e[i].gety()<y+3 && e[i].gety()>y-3){
					u =me.necromancy(e[i], 'p', u, C);
				}}
				break;
			default:
				enemy_attack(e, me,n);
				undead_attack(e, me,n);
				break;
		}
}
/*void Logic(){
	switch (dir){
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
	}
}*/
int printv(Myself me){
	std::vector <tab> T = me.getV();
	std::vector <tab> :: iterator iter; 
	for (iter = T.begin(); iter<T.end(); iter++){
		std::cout<<iter->name<<" "<<iter->parent<<" "<< iter->mana<<" "<<iter->charact<<std::endl;
	}
	return 0;
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
	initscr();
	cbreak();
	noecho();
	scrollok(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	int n = 0;
	C = ReadCoef();
       	Alive* e =Readfile( &n);
	u=ReadUndead();
	Myself me= Readme();
	while (!gameOver){
	//	printen(e, n);
		Draw(e, me, n);
		Input(e, me, n);
	}
	endwin();
	printv(me);
	//printenu();
	return 0;
}

