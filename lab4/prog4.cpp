#include "lab4.h"
#include <ncurses.h>
#include <cstring>
#include <iostream>
namespace Necromancer{
	//template <class T>
	//Myself& Myself::setmax(){
		//if (level == 1){
			//max_hp = 7;

	void Myself::draining_hp(Alive& enem){
		//std::cout<<
		//printw("Enemy is dead, input 1 to turn him into health; 2 to turn him into mana");//<<std::endl;
		//int n = getch();
		//if (n == '2'){
		//	mana+=enem.getexp();
		int k;
		for(iter=V.begin(); iter <V.end(); iter++){
			if (iter->name == "draining")
				k = iter->charact;
		}
		enem.sethp(enem.gethp()-1);
		if (enem.gethp()<=0){
			enem.setcond(0);
			int f = 0;
			while (f == 0){
				mvwprintw(stdscr, 25, 0, "enemy is dead, press 1 to turn his exp into hp, 2 - into mana");
				switch(getch()){
					case '1':
						hp+=k+enem.getexp();
						f = 1;
						if (hp>max_hp)
							hp = max_hp;
						break;
					case '2':
						mana+=k+enem.getexp();
						f = 1;
						if(mana>max_mana)
							mana=max_mana;
						break;
				}
			}
			exp+=k;
			if (exp>5){
				increase_level();
				exp=1;
			}
			enem.setx(-10);
			enem.sety(-10);
		}
	}
	int Myself::wounded(Alive& en){
		en.exp+=1;
		hp-=1;
		if (hp <=0)
			return 0;
		return 1;
	}
	Myself& Myself::increase_level(){
		level++;
		int f = 0;
		while(f == 0){
			mvwprintw(stdscr, 25, 0, "press 1 to encrease draining level, 2 to make next undead available");
			
			switch(getch()){
				case '1':

					for(iter= V.begin(); iter< V.end(); iter++){
						if (iter->name == "draining")
							iter->charact++;
					}
					return *this;
					break;

				case '2':
					for(iter = V.begin(); iter<V.end(); iter++){
				 		if (iter->charact == 0){
							if (iter->parent == ""){
								iter->charact = 1;
								return *this; }
							else{
								std::vector <tab> :: iterator i;
								for (i = V.begin(); i<V.end(); i++){
									if (i->name == iter->parent){
										if (i->charact == 1){
										iter->charact = 1;
										return *this; }
									}
								}
							}
						}
					}
					break;
			}
		}
	return *this;
	}

	Alive::Alive(){
		setname("");
		setmax_hp(0);
		setexp(rand()%5+1);
	}
			
	Alive::Alive(std::string str, int m, int h, int f, int ex, int c){
		setname(str);
		setmax_hp(m);
		sethp(h);
		setfr(f);
		exp= ex;
		condition = 1;
	}
	Undead::Undead(Alive& enem, std::string c){
		setname(enem.getname());
		setmax_hp(enem.getmax_hp());
		sethp(getmax_hp());
		setx(enem.getx());
		sety(enem.gety());
		setfr(1);
		type = c;
	}
	std::vector <tab> CreateTable(){
		std::vector <tab> T;
	tab t1;
	t1.name = "draining";
	t1.parent = "";
	t1.mana = 0;
	t1.charact = 1;//level of draining
	T.push_back(t1); 
	tab t2;
	t2.name = "skeleton";
	t2.parent = "";
	t2.mana = 2;
	t2.charact = 1;//is available
	T.push_back(t2);
	tab t3;
	t3.name = "gul";
	t3.parent = "skeleton";
	t3.mana = 4;
	t3.charact = 0; //is not available
	T.push_back(t3);
	tab t4;
	t4.name = "ghost";
	t4.parent = "";
	t4.mana = 5;
	t4.charact = 0;
	T.push_back(t4);
	tab t5;
	t5.name = "phantom";
	t4.parent = "ghost";
	t4.mana = 7;
	t4.charact = 0;
	T.push_back(t5);
	tab t6;
	t6.name = "zombie";
	t6.parent = "";
	t6.mana = 10;
	t6.charact = 0;
	T.push_back(t6);
	return T;
}
	Myself::Myself(){
		exp = 0;
		hp = 7;
		level = 1;
		mana = 0;
		fr = 1;
		max_hp = level*2+5;
		max_mana = level*5+10;
		V = CreateTable();
	}
	void Myself::curse(Alive& enem){
	}
	std::vector <Undead> Myself::necromancy(Alive& enem, char c, std::vector <Undead> u){
		std::string type;
		if (c == 's')
			type = "skeleton";
		if (c == 'g')
			type = "ghost";
		if (c == 'f')
			type = "gul";
		if (c == 'z')
			type = "zombie";
		if (c == 'p')
			type = "phantom";
		std::vector <tab> :: iterator iter;
		for (iter = V.begin(); iter<V.end(); iter++){
			if (iter->name == type){
				if (iter->charact == 0 || (iter->mana > mana)){
					//hp-=1;
					return u;
				}
				mana -=iter->mana;
				//std::cout<<mana<<std::endl;

			}
		}

		Undead U(enem, type);	
		u.push_back(U);
		enem.setx(-10);
		enem.sety(-10);
		exp+=1;
		//delete &enem;
		return u;

	}
	
}	
