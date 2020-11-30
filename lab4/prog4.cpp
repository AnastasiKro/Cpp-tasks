#include "lab4.h"
#include <ncurses.h>
#include <cstring>
#include <iostream>
//const int width = 20;
//const int height = 20;
namespace Necromancer{
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
		setexp(ex);
		setcond(1);
	}
	std::vector <tab> CreateTable(){
		std::vector <tab> T;
	tab t1;
	t1.name="draining";
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
	tab t7;
	t7.name = "spoilage";
	t7.parent = "";
	t7.mana= 1;
	t7.charact = 1;
	T.push_back(t7);
	tab t8;
	t8.name = "pain";
	t8.parent = "spoilage";
	t8.mana = 2;
	t8.charact = 1;
	T.push_back(t8);
	tab t9;
	t9.name = "agony";
	t9.parent = "pain";
	t9.mana =3;
	t9.charact = 1;
	T.push_back(t9);
	t1.name = "exhastion";
	t1.parent = "";
	t1.mana = 1;
	t1.charact = 1;
	T.push_back(t1);
	t2.name= "rot";
	t2.parent = "exhastion";
	t2.mana = 2;
	t2.charact = 1;
	T.push_back(t2);
	t3.name = "desecration";
	t3.parent = "";
	t3.mana = 3;
	t3.charact = 1;
	T.push_back(t3);
	t1.name = "madness";
	t1.parent = "desecration";
	t1.mana = 3;
	t1.charact = 1;
	T.push_back(t1);
	return T;
}
	Unit::Unit(){
		setx(rand()%20);
		sety(rand()%20);
	}
	int Unit::hit_enem(Unit* enem){
		if ((getfr() == enem->getfr()) && getcond()!=2)
			return 1;
		enem->sethp(enem->gethp()-getdamage());
		if (enem->gethp()<=0){
			enem->sethp(0);
			setexp(getexp()+1);
			return 0;
		}
		return 1;
	}
	Undead::Undead(){
		setx(rand()%20);
		sety(rand()%20);
	}
	Undead::Undead(Unit* enem, std::string c, int k){
		setname(enem->getname());
		setmax_hp(enem->getmax_hp());
		sethp(getmax_hp());
		setx(enem->getx());
		sety(enem->gety());
		setdamage((enem->getdamage()+k)/2);
		setfr(1);
		settype(c);
	}
	/*Summoner::Summoner(){
		setx(rand()%20);
		sety(rand()%20);
	}*/
	Undead* Summoner::create_slaves(){
		Undead* U = new Undead;
		U->settype(getslaves_type());
		U->setmax_hp(rand()%5+1);
		U->sethp(U->getmax_hp());
		return U;
		//U.setname(getname());
		//U.setx(getx()+rand()%4+1);
		//U.sety(gety()+rand()%4+1);
		//U.setfr(getfr());
		//u.push_back(U);
		//Paste(&(u[u.size()-1]),  3, getx(), gety());
	}
	Unit* Summoner_Alive::Create(){
		Undead* U = create_slaves();
		U->setfr(getfr());
		U->setname(getname());
		return U;
		//u.push_back(U);
		//Paste(&(u[u.size()-1], 3, Cell[i][j].getObj()->getx(), Cell[i][j].getObj()->gety()));
	}
	Unit* Summoner_Undead::Create(){
		Undead* U = create_slaves();
		U->setfr(getfr());
		U->setname(getname());
		return U;
		//u.push_back(U);
		//Paste(&(u[u.size()-1], 3, Cell[i][j].getObj()->getx(), Cell[i][j].getObj()->gety()));
	}
	Summoner_Alive::Summoner_Alive(std::string S, Unit P){
		setslaves_type(S);
		setmax_hp(P.getmax_hp());
		sethp(P.gethp());
		setfr(P.getfr());
		setname(P.getname());
		setdamage(P.getdamage());
	}
	Summoner_Undead::Summoner_Undead(std::string S, Unit P, std::string type){
		setslaves_type(S);
		setmax_hp(P.getmax_hp());
		sethp(P.gethp());
		setfr(P.getfr());
		setname(P.getname());
		setdamage(P.getdamage());
		settype(type);
	}	
		
	Myself::Myself(){
		setexp(0);
		sethp(7);
		setlevel(1);
		setdamage(1);
		mana = 0;
		setfr(1);
		setmax_hp(getlevel()*2+5);
		max_mana = getlevel()*5+10;
		V = CreateTable();
	}
	tab Myself::find_in_table(std::string str){
		for (iter = V.begin(); iter<V.end(); iter++){
			if (iter->name == str){
				return *iter; }
		}
		//return nullptr;
	}
	Myself& Myself::increase_level(){
		if (getexp()<5)
			return *this;
		setlevel(getlevel()+1);
		setdamage(getlevel());
		exp = 1;
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
	//void Myself::make_available(std::string str){

	int Myself::draining(Unit* enem){
		int k;
		for(iter=V.begin(); iter <V.end(); iter++){
			if (iter->name == "draining")
				k = iter->charact;
		}
		int f = 0;
		if (enem->getcond() == 0){
			while (f == 0){
				mvwprintw(stdscr, 25, 0, "enemy is dead, press 1 to turn his exp into hp, 2 - into mana");
				switch(getch()){
					case '1':
						sethp(gethp()+k+enem->getexp());
						f = 1;
						if (gethp()>getmax_hp())
							sethp(getmax_hp());
						break;
					case '2':
						mana+=k+enem->getexp();
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
			return 0;
		}
		return 1;
	}
	cell& cell::del(){
		setwho(0);
		setObj(nullptr);
		return *this;
	}
}	
