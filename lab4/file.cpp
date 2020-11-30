#include <iostream>
#include <fstream>
#include "lab4.h"
//#include "ContClass.h"
using namespace MyClass;
const int width = 20;
const int height = 20;
extern std::vector <Necromancer::Undead> u;
extern Necromancer::cell Cell[width][height];
namespace Necromancer{
	//extern std::vector <Undead> u;
	void Game::Paste( Unit* a, int k, int i, int j){
		int s = 0; int x; int y;
		//std::cout<<"i j "<<i<<" "<<j<<std::endl;
		do{
			if (i !=-1){
				do{
				 	x = i-4 + rand()%8;
				 	y = j-4+rand()%8;
				}while(x<1 || x>width-1 ||y<0 ||y>height-1);
			}
			else{
				x = rand()%width;
				y = rand()%height;
			}
			//std::cout<<"x y "<<x<<" "<<y<<std::endl;
			if (Cell[y][x].getObj() == nullptr&& Cell[y][x].gettype()==0){
				Cell[y][x].setObj(a);
				Cell[y][x].setwho(k);
				s = 1;
			}
		}while (s == 0);
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
			Me.setfr(atoi(line));
			Me.setdamage(me.getlevel());
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
		/*std::ifstream inn("/home/avtobus/3sem/lab2/3sem/lab4/config/Curses");
		if (inn.is_open()){
			while (!inn.eof()){
				inn.getline(str, 20);
				if (inn.eof())
					break;
				tab t1;
				t1.name = str;
				inn.getline(str, 20);
				t1.parent = str;
				inn.getline(line, 3);
				t1.mana = atoi(line);
				inn.getline(line, 3);
				t1.charact = atoi(line);
				T.push_back(t1);
				Me.setV(T);
			}
			inn.close();
		}*/
		Me.setname("me");
		setme(Me);
	}
	void Game::ReadCoef(){
		char line[10];
		//std::vector <coef> c;
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
				u.push_back(U);
		}
			in.close();
		}
		for (int i = 0; i<u.size(); i++){
			Paste(&(u[i]), 3, -1, -1);
		}
	}
void Game::ReadSummoner(std::string str){
		char line[10];
		int k;
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
				P.setmax_hp(atoi(line));
				in.getline(line, 10);
				P.sethp(atoi(line));
				in.getline(line, 10);
				P.setdamage(atoi(line));
				in.getline(line, 10);
				P.setfr(atoi(line));
				if (k == 1){
					Summoner_Alive sa(S, P);
					SA.push_back(sa);
				}
				else{
					Summoner_Undead su(S, P, type);
					SU.push_back(su);
				}
				//Paste(&U, Cell);
		}
			in.close();
		}
		for (int i = 0; i<SA.size(); i++)
				Paste(&(SA[i]), 4, -1, -1);
		for (int i = 0; i<SU.size(); i++)
				Paste(&(SU[i]), 5, -1, -1);
			

		//return p;
	}
	void Game::ReadAlive(std::string str){
	char line[10];
	char m[3];
	//en<Alive>* enemy = new en;
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
			//n+=1;
			a->setname(line);
			//std::cout<<n<<" "<<line<<std::endl;
			a->setmax_hp(atoi(m));
			in.getline(m,3);
			a->sethp(atoi(m));
			in.getline(m, 3);
			a->setexp(atoi(m));
			in.getline(m, 3);
			a->setfr(atoi(m));
			in.getline(m, 3);
			a->setdamage(atoi(m));
			a->setx(rand()%20);
			a->sety(rand()%20);
			a->setcond(1);
			Paste(a, 2, -1, -1);
			/*if (n == 1){
				delete enemy;
				en* enemy = new en(*a);
			}
			else
				enemy->add(*a);	*/
			e.add(a);
		}
	}
	in.close();
}}
