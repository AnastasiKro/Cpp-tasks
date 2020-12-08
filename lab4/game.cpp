#include <ncurses.h>
#include <iostream>
#include "Cave.h"
#include <fstream>
#include <cstdlib>
#include <sstream>
using namespace Necromancer;
const int width=20;
const int height=20;
int x, y;

void Draw(Game G){
	//cell** Cell = G.getCell();
	mvprintw(24, 1,"%d\n", G.x);
	printw("%d\n", G.y);
	printw("W - Werewolf, O - ogr, G - goblin, D - dwarf, T - troll\n");
	printw("g - gul, gh - ghost, s - skeleton, z - zombie, p - phantom\n");
	//for(int i = 0; i<width+1; i++)
	//	printw("#");
	Myself me = G.getme();
	printw("   level: %d; hp: %d, experience: %d, mana: %d, fraction: %d, available: ", me.getlevel(), me.gethp(), me.getexp(), me.getmana(), me.getfr());
	std::vector <tab> :: iterator iter;
	for (iter = me.getV().begin(); iter<me.getV().end(); iter++){
		if (iter->charact!=0)
		       printw("%s, ", iter->name.c_str());
	}	
	printw("\n");
	for (int i = 0; i<height+1; i++){
		for (int j = 0; j<width+1; j++){
			if (G.Cell[i][j].gettype()==1)
				printw("#");
			if (G.Cell[i][j].gettype()==2)
				printw("8");
			if (G.Cell[i][j].gettype()==-1)
				printw("E");
			if (G.Cell[i][j].getwho() == 0 && G.Cell[i][j].gettype()==0)
				printw(" ");
			if (G.Cell[i][j].getwho() ==-1)
				printw("-");
			if(G.Cell[i][j].getwho() == 1)
				printw("@");
			if(G.Cell[i][j].getwho() == 2){
				std::string str = G.Cell[i][j].getObj()->getname();
				printw("%c", str[0]);	
			}
			if (G.Cell[i][j].getwho() == 3|| G.Cell[i][j].getwho()==6){
				std::string str = G.Cell[i][j].getObj()->gettype();
				printw("%c", str[0]);}
			if (G.Cell[i][j].getwho() == 4){
				std::string str = G.Cell[i][j].getObj()->getname();
				printw("%c", str[0]);
			}

			if (G.Cell[i][j].getwho() == 5){
				std::string type = G.Cell[i][j].getObj()->gettype();
				printw("%c", type[0]);
			}
			if (G.x>j-3 && G.x<j+3 &&G.y<i+3 && G.y>i-3 && G.Cell[i][j].getwho()>1){
				Unit* it = G.Cell[i][j].getObj();
				printw(" %s, hp: %d, damage:%d, fraction: %d, condition %d",  it->getname().c_str(), it->gethp(), it->getdamage(),it->getfr(), it->getcond());
			}
		}
		printw("\n");
	}
	printw("\n");
}

int P(int r){
	if (r==0 || r ==1)
		return 0;
	else
		return r-2;
}
int Input( Game& G){
	if (G.getgameOver()==2){
		if(getch()=='p')
			G.setgameOver(0);
		return 0;
	}
	//if (_kbhit()){//проверка, нажата ли клавиша
		switch(getch())// какая именно клавиша нажата
		{
			
			case 'h':
				G.goleft();
				break;
			case 'j':
				G.goUp();
				break;
			case 'k':
				G.goright();
				break;
			case 'l':
				G.godown();
				break;
			case 'd':
				G.Draining();
				break;
			case 'b': 
				G.Attack();
				break;
			case 'c':{
				char a = 0; 
				int f = 0;
				while (f == 0){
				mvwprintw(stdscr, 25, 0, "Choose the curse: s - spoilage, p - pain, a - agony, r - rot\n");
				mvwprintw(stdscr, 26, 0, "e - exhaustion, d - desecration, m - madness");
				a = getch();
				if ( a =='s' || a == 'p' || a == 'a'||a =='r'||a=='e'||a=='c'||a=='d'||a=='m')
					f = 1;
				}
				G.curse(a);
				break;}
			case 'n':{
					 int f = 0; char a = 0;
					 while (f ==0){
						 mvwprintw(stdscr, 25, 0, "Choose the undead: s - skeleton, g - gul, h - ghost, p - phantom, z - zombie");
						 a = getch();
						 if (a == 's' || a == 'p'||a == 'z'||a=='h'||a =='g')
							 f = 1;
					 }
					 G.necromancy(a);
					 break;
				 }
			case 'x':
				G.setgameOver(1);
				break;
			case 'p':
				G.setgameOver(2);
				break;
			case 'o':
				G.Open_The_Door();
				break;
			default:
				int a = rand()%10000;
				G.enemy_attack();
				if (a == 3)
					G.Summoner_attack();
				if (a == 0)
					G.Alive_agression();
				if (a%5000==2)
					G.Alive_go(); 
				break;
		}
		return 0;
}/*
int printv(Myself me){
	std::vector <tab> T = me.getV();
	std::vector <tab> :: iterator iter; 
	for (iter = T.begin(); iter<T.end(); iter++){
		std::cout<<iter->name<<" "<<iter->parent<<" "<< iter->mana<<" "<<iter->charact<<std::endl;
	}
	return 0;
}
int printCell(Game G){
	for (int i = 0; i<height; i++){
		for (int j = 0; j<width; j++){
			if (G.Cell[i][j].getObj()!=nullptr){
			std::cout<<i<<" "<<j<<std::endl;
			//if(Cell[i][j].getObj()!=nullptr)
				std::cout<<G.Cell[i][j].getObj()->getname()<<" "<<G.Cell[i][j].getObj()->gethp()<<std::endl;
		}}
	}
	return 0;
}*/
int write(Game& G){
	G.WriteUndead();
	G.WriteAlive();
	G.Writeme();
	G.WriteSummoners();
	G.Writegame();
	return 0;
}
int Reload(Game& G, int l){
	write(G);
	std::stringstream ss;
	ss<<l;
	std::string s1= "/home/avtobus/3sem/lab2/3sem/lab4/config/l"+ ss.str();	
	G.new_level();
	///std::cout<<"l"<<std::endl;
	G.ReadSummoner(s1+"/Summoners");
	//std::cout<<"ss"<<std::endl;
       	G.ReadAlive(s1+"/Alive");
	//std::cout<<"aa"<<std::endl;
	G.ReadUndead(s1+"/Undead");
	//std::cout<<"uuun"<<std::endl;
	//G.Readme(s1+"/Myself");
	return 0;
}
int Gameload(Game& G){
	G.ReadCoef();
	int f=0; char a; std::string str;
	std::string s1= "/home/avtobus/3sem/lab2/3sem/lab4/";	
	while (f==0){
		
		mvwprintw(stdscr, 1, 1,"If you want to start a new game, input 1, to resume, input 2\n");
		a = getch();
		if (a == '1'){
			f =1;
			str= "config/l1";
			G.Readme(s1+str+"/Myself");
			G.SetUp(1);
		}
		if (a == '2'){
			f = 2;
			str = "mygame";
			G.Readlevel();
			G.Readme(s1+str+"/Myself");
			G.SetUp(G.getlevel());
			
		}
	}
	G.ReadSummoner(s1+str+"/Summoners");
	//std::cout<<"aa"<<std::endl;
       	G.ReadAlive(s1+str+"/Alive");
	//std::cout<<"bb"<<std::endl;
	G.ReadUndead(s1+str+"/Undead");
	//std::cout<<"cc"<<std::endl;
	return 0;
}
int main(){
	Game G;
	//G.SetUp();
	initscr();
	cbreak();
	noecho();
	scrollok(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	Gameload(G);
	while (G.getgameOver()!=1){
		Draw(G);
		Input(G);
		if (G.getgameOver()==3){
			Reload(G, G.getlevel()+1);
		}		
	}
	endwin();
//	printv(G.getme());
	if (G.getme().gethp()!=0){
	write(G);
	}
	//printCell(G);
	return 0;
}

