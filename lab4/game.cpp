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
extern cell Cell[width][height];
int x, y;
eDirection dir;
en e;

extern std::vector <Undead> u;
std::vector <Undead> :: iterator it;
std::vector <tab> T;
std::vector <Prizivatel> p;
//std::vector <tab> :: iterator iter;
std::vector <coef> C;
void SetUp(){
	gameOver = false;
	dir = STOP;
	x = width/2;
	y = 0;
	for (int i = 0; i<height; i++){
	       for (int j = 0; j<width; j++){
		       if (j == 0 || j == width - 1){
			       Cell[i][j].settype(1);
			       Cell[i][j].setwho(0);
			       Cell[i][j].setObj(nullptr);
		       }
		       else{
		   Cell[j][i].settype(0);
		   Cell[j][i].setObj(nullptr);
		   Cell[j][i].setwho(0); }
	       }
	}
	Cell[y][x].settype(0);
	Cell[y][x].setwho(1);
	       		   
}

void Draw(Myself& me){
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
	for (int i = 0; i<height; i++){
		for (int j = 0; j<width; j++){
			if (Cell[i][j].getwho() == 0 && Cell[i][j].gettype()==0)
				printw(" ");
			if (Cell[i][j].getwho() ==-1)
				printw("-");
			if(Cell[i][j].getwho() == 1)
				printw("@");
			if(Cell[i][j].getwho() == 2){
				std::string str = Cell[i][j].getObj()->getname();
				printw("%c", str[0]);	
			}
			if (Cell[i][j].getwho() == 3){
				std::string str = Cell[i][j].getObj()->gettype();
				printw("%c", str[0]);}
			if (Cell[i][j].getwho() == 4){
				
				std::string str = Cell[i][j].getObj()->gettype();
				if (str=="Alive"){
					std::string name = Cell[i][j].getObj()->getname();
					printw("%c", name[0]);
				}
				else	
					printw("%c", str[0]);
			}
			if (x>j-3 && x<j+3 &&y<i+3 && y>i-3 && Cell[i][j].getwho()>1){
				Unit* it = Cell[i][j].getObj();
				printw(" %s, hp: %d, fraction: %d",  it->getname().c_str(), it->gethp(), it->getfr());
			}
			if (j==0 || j == width-1){
				printw("#");
			}
		}
		printw("\n");
	}
	for(int i = 0; i<width+1; i++)
		printw("#");
	printw("\n");
}
void MoveMe(Myself& me, int x1, int y1, int x2, int y2){
		Cell[y2][x2].setwho(1);
		Cell[y2][x2].setObj(&me);
		Cell[y1][x1].setwho(0);
		Cell[y1][x1].setObj(nullptr);
}

int P(int r){
	if (r==0 || r ==1)
		return 0;
	else
		return r-2;
}
void enemy_attack(){
	for (int i = 0; i<height; i++){
		for (int j = 0; j<width; j++){
			if (Cell[i][j].getwho()>1){
				Unit *q = Cell[i][j].getObj();
				for (int k = P(i); k<i+3; k++){
					for( int l = P(j); l<j+3; l++){
						if (Cell[k][l].getwho()>0&& (k!=i || l!=j)){
							Unit* r = Cell[k][l].getObj();
							int a = rand()%10000;
							if (a !=0)
								break;
							int m =q->hit_enem(r);
							if (m ==0){
								if (Cell[k][l].getwho() == 2){
									Cell[k][l].getObj()->setcond(0);
									Cell[k][l].setwho(-1);
								}
								if(Cell[k][l].getwho() == 1)
									gameOver = true;
								if (Cell[k][l].getwho() == 3){
									Cell[k][l].del();
								}
							}
						}
					}
				}
			}
		}
	}
}
void Prizivatel_attack(){
	for (int i = 0; i<height; i++){
		for (int j = 0; j< width; j++){
			if (Cell[i][j].getwho()==4){
				int a = rand()%10000;
				if (a == 5){
					Cell[i][j].getObj()->create_slaves();
					//u.push_back(U);
				}
			}
		}
	}
}
void Input( Myself& me){
//	while(TRUE){
		//char x = getch();
	//if (_kbhit()){//проверка, нажата ли клавиша
		switch(getch())// какая именно клавиша нажата
		{
			
			case 'h':
				if (x>1&& Cell[y][x-1].gettype()==0 &&Cell[y][x-1].getwho()==0){
					x--;
					MoveMe(me, x+1, y, x, y);
				}
					
				break;
			case 'j':
				if (y>1 && Cell[y-1][x].gettype()==0&&Cell[y-1][x].getwho() ==0){
					y--;
					MoveMe(me, x, y+1, x, y);
				}
				break;
			case 'k':
				if(x<width-1&& Cell[y][x+1].gettype()==0&& Cell[y][x+1].getwho()==0){
					x++;
					MoveMe(me, x-1, y, x, y);
				}

				break;
			case 'l':
				if (y<height&& Cell[y+1][x].gettype()==0 && Cell[y+1][x].getwho()==0){
					y++;
					MoveMe(me, x, y-1, x, y);
				}
				break;
			case 'd':
				for (int i = P(x); i<x+3; i++){
					for(int j = P(y); j<y+3; j++){
					       if(Cell[j][i].getwho()==-1){
						       Unit* a = Cell[j][i].getObj();
						       int p =me.draining(a);
						       if (p == 0){
							       Cell[j][i].setwho(0);
							       Cell[j][i].setObj(nullptr);
						       }
					       }
					}
				}
				break;
			case 'b': 
				for (int i = P(x); i<x+3; i++){
					for (int j = P(y); j<y+3; j++){
						if (Cell[j][i].getwho()>1){
							Unit* a = Cell[j][i].getObj();
							int p =me.hit_enem(a);
							if (p == 0)
								Cell[j][i].del();
							if (p==2)
								Cell[j][i].setwho(-1);
					       	}
					}
				}
				break;
			/*case 's':
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
				break;*/
			case 'x':
				gameOver= true;
				break;
			/*case 'p':
				for (int i = 0; i<n; i++){
				if (e[i].getx() <x+3 && e[i].getx()>x-3&&e[i].gety()<y+3 && e[i].gety()>y-3){
					u =me.necromancy(e[i], 'p', u, C);
				}}
				break;*/
			default:
				enemy_attack();
				Prizivatel_attack();
				break;
		}
}
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
int printCell(){
	for (int i = 0; i<height; i++){
		for (int j = 0; j<width; j++){
			if (Cell[i][j].getObj()!=nullptr){
			std::cout<<i<<" "<<j<<std::endl;
			//if(Cell[i][j].getObj()!=nullptr)
				std::cout<<Cell[i][j].getObj()->getname()<<" "<<Cell[i][j].getObj()->gethp()<<std::endl;
		}}
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
	p = ReadPrizivatel(Cell);
       	e=Readfile( n, Cell);
	u=ReadUndead(Cell);
	Myself me= Readme();
	me.setname("me");
	Cell[0][width/2].setObj(&me);
	while (!gameOver){
	//	printen(e, n);
		Draw( me);
		Input(me);
	}
	endwin();
	//printv(me);
	printCell();
	//printenu();
	return 0;
}

