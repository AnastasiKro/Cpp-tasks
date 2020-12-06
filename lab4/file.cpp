#include <iostream>
#include <fstream>
#include "Cave.h"
using namespace MyClass;
const int width = 20;
const int height = 20;
extern std::vector <Necromancer::Undead> u;
extern Necromancer::cell Cell[width][height];
namespace Necromancer{
	//extern std::vector <Undead> u;
	void Game::Paste( Unit* a, int k, int i, int j){
		int s = 0; int x1; int y1;
		//std::cout<<"i j "<<i<<" "<<j<<std::endl;
		do{
			if (k == 6){
				do{
				 	x1 = i-4 + rand()%8;
				 	y1 = j-4+rand()%8;
				}while(x1<1 || x1>width-1 ||y1<1 ||y1>height-1);
			}
			else{
				x1 = i;
				y1 = j;
			}
			//std::cout<<"x y "<<x<<" "<<y<<std::endl;
			if (Cell[y1][x1].getObj() == nullptr&& Cell[y1][x1].gettype()==0){
				Cell[y1][x1].setObj(a);
				Cell[y1][x1].setwho(k);
				if (k==6){
					a->setx(x1); a->sety(y1);
				//	Cell[y1][x1].setwho(3);
					//std::cout<<x1<<" "<<y1<<std::endl;
				}
				s = 1;
			}
		}while (s == 0);
	}
	void Game::Readlevel(){
		char line[2]; int l;
		std::ifstream in("/home/avtobus/3sem/lab2/3sem/lab4/mygame/Cave");
		if (in.is_open()){
			in.getline(line, 2);
			l = atoi(line);
			setlevel(l);
			std::cout<<l<<std::endl;
			in.close();
		}
	}
	void Game::Readme(std::string s1){
		Myself Me;
		char line[3];
		char str[20];
		std::vector <tab> T;
		std::ifstream in(s1);//"/home/avtobus/3sem/lab2/3sem/lab4/config/myself");
		if (in.is_open()){
			in.getline(line, 3);
			Me.setexp(atoi(line));
			in.getline(line, 3);
			Me.setlevel(atoi(line));
			in.getline(line, 3);
			Me.setmana(atoi(line));
			in.getline(line, 3);
			Me.setfr(atoi(line));
			Me.setdamage(me.getlevel());
			in.getline(line, 3);
			x = atoi(line);
			in.getline(line, 3);
			y = atoi(line);
			while (!in.eof()){
				tab t1;
				in.getline(str, 20);
				if (in.eof())
					break;
				t1.name = str;
				in.getline(str, 20);
				t1.parent = str;
				in.getline(line, 3);
				t1.mana = atoi(line);
				in.getline(line, 3);
				t1.charact = atoi(line);
				T.push_back(t1);
				Me.setV(T);
			}
			in.close();
		}
		Me.setname("me");
		setme(Me);
	}
	void Game::ReadCoef(){
		char line[10];
		std::ifstream in("/home/avtobus/3sem/lab2/3sem/lab4/config/coefficient");
		if (in.is_open()){
			while(!in.eof()){
				in.getline(line, 10);
				if(in.eof())
					break;
				coef co;
				co.name =line;
				in.getline(line, 10);
				co.c = atoi(line);
				C.push_back(co);
			}
			in.close();
		}
	}
	void Game::ReadUndead(std::string str){
		char line[10];
		//std::vector <Undead> u;
		std::ifstream in(str);//"/home/avtobus/3sem/lab2/3sem/lab4/config/Undead");
		if (in.is_open()){
			while(!in.eof()){
				in.getline(line, 10);
				if(in.eof())
					break;
				Undead U ;
				U.setname(line);
				in.getline(line, 10);
				U.settype(line);
				in.getline(line, 10);
				U.setmax_hp(atoi(line));
				in.getline(line, 10);
				U.sethp(atoi(line));
				in.getline(line, 10);
				U.setdamage(atoi(line));
				in.getline(line, 10);
				U.setfr(atoi(line));
				in.getline(line, 10);
				U.setx(atoi(line));
				in.getline(line, 10);
				U.sety(atoi(line));
				u.push_back(U);
		}
			in.close();
		}
		for (int i = 0; i<u.size(); i++){
			Paste(&(u[i]), 3, u[i].getx(), u[i].gety());
		}
	}
void Game::ReadSummoner(std::string str){
		char line[10];
		int k; int q;
		//std::vector <Su> p;
		std::ifstream in(str);//"/home/avtobus/3sem/lab2/3sem/lab4/config/Prizivately");
		if (in.is_open()){
			while(!in.eof()){

				in.getline(line, 10);
				std::string type = line;
				if(in.eof())
					break;
				if (type == "Alive")
					k=1;
				else 
					k=2;
				//Summoner S; 
				Unit P;
				//P.settype(line);
				in.getline(line, 10);
				P.setname(line);
				in.getline(line, 10);
				std::string S=line;
				in.getline(line, 10);
				q = atoi(line);
				in.getline(line, 10);
				P.setmax_hp(atoi(line));
				in.getline(line, 10);
				P.sethp(atoi(line));
				in.getline(line, 10);
				P.setdamage(atoi(line));
				in.getline(line, 10);
				P.setfr(atoi(line));
				in.getline(line, 10);
				P.setx(atoi(line));
				in.getline(line, 10);
				P.sety(atoi(line));
				if (k == 1){
					Summoner_Alive sa(S, P, q);
					SA.push_back(sa);
				}
				else{
					Summoner_Undead su(S, P, type, q);
					SU.push_back(su);
				}
				//Paste(&U, Cell);
		}
			in.close();
		}
		for (int i = 0; i<SA.size(); i++)
				Paste(&(SA[i]), 4, SA[i].getx(), SA[i].gety());
		for (int i = 0; i<SU.size(); i++)
				Paste(&(SU[i]), 5, SU[i].getx(), SU[i].gety());
	}
	void Game::ReadAlive(std::string str){
	char line[10];
	char m[3];
		std::ifstream in(str);//"/home/avtobus/3sem/lab2/3sem/lab4/config/enemies");
	if (in.is_open()){
		while (!in.eof()){
			Alive* a = new Alive;
			in.getline(line, 10);
			if (in.eof())
				break;
			in.getline(m, 3);
		//	std::cout<<m<<std::endl;
			if (in.eof())
				break;
			a->setname(line);
			//std::cout<<line<<std::endl;
			a->setmax_hp(atoi(m));
			in.getline(m,3);
			a->sethp(atoi(m));
			in.getline(m, 3);
			a->setexp(atoi(m));
			in.getline(m, 3);
			a->setfr(atoi(m));
			in.getline(m, 3);
			a->setdamage(atoi(m));
			in.getline(m, 3);
			a->setx(atoi(m));
			in.getline(m, 3);
			a->sety(atoi(m));
			a->setcond(1);
			Paste(a, 2, a->getx(), a->gety());
			e.add(a);
		}
	}
	in.close();
	}
	void Game::Readmap(std::string name){
		char m[2]; int a;
		std::ifstream in(name);
		if (in.is_open()){
		for (int i=1; i <height; i++){
			for (int j = 1; j<width; j++){
				in.getline(m, 2);
				a = atoi(m);
				Cell[i][j].settype(a);
			}
		}
		}
	}

	
}
