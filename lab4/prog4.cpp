#include "lab4.h"
#include <ncurses.h>
#include <cstring>
#include <iostream>
namespace Necromancer{
	//template <class T>
	//Myself& Myself::setmax(){
		//if (level == 1){
			//max_hp = 7;

	void Myself::draining(Alive& enem){
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
		/*enem.sethp(enem.gethp()-enem.gethit());
		if (enem.gethp()<=0){
			enem.setcond(0);*/
		int f = 0;
		if (enem.getcond() == 0){
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
		hp-=en.getdamage();
		if (hp <=0)
			return 0;
		return 1;
	}
	void Myself::hit(Alive& enem){
		enem.sethp(enem.gethp()-1);
		exp+=1;
		if (enem.gethp()<=0){
			enem.setcond(0);
			enem.sethp(0);
			exp+=2;
		} 
		if (exp>5)
			increase_level();
	}
	void Myself::hit(Undead& enem){
		enem.sethp(enem.gethp()-1);
	//	exp+=1;
		if (enem.gethp()<=0){
			enem.setx(-10); enem.sety(-10);
			exp+=2;
			enem.sethp(0);
		}
		if (exp>5)
			increase_level();
       	}	
	Myself& Myself::increase_level(){
		level++;
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
	Undead::Undead(Alive& enem, std::string c, int k){
		setname(enem.getname());
		setmax_hp(enem.getmax_hp());
		sethp(getmax_hp());
		setx(enem.getx());
		sety(enem.gety());
		setdamage((enem.getdamage()+k)/2);
		sethit(enem.gethit());
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
	Undead::Undead(){
		setx(rand()%20);
		sety(rand()%20);
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
	//template <class T>
	int Alive::hitenem(Alive& enem){
		enem.sethp(enem.gethp()-getdamage());
		exp+=1;
		if (enem.gethp()<=0){
			enem.sethp(0);
			enem.setcond(0);
			return 0;
		}
		return 1;
	}
	int Undead::wounded(Alive& enem){
		sethp(gethp()-enem.getdamage());
		enem.setexp(enem.getexp()+1);
		if (gethp()<=0){
			setx(-10);
			sety(-10);
			return 0;
		}
		return 1;
	}
	int Myself::wound(Undead& enem){
		hp-=enem.getdamage();
		if (hp<=0)
			return 0;
		return 1;
	}
	int Undead::hiten(Undead& enem){
		sethp(gethp()-enem.getdamage());
		if (gethp()<=0){
			setx(-10); sety(-10); }
		return 0;
	}
	int Undead::hitenem(Alive& enem){
		enem.sethp(enem.gethp()-getdamage());
		if (enem.gethp()<=0){
			enem.setcond(0);
			enem.sethp(0);
		}
		return 0;
	}



	tab Myself::find_in_table(std::string str){
		for (iter = V.begin(); iter<V.end(); iter++){
			if (iter->name == str){
				return *iter; }
		}
		//return nullptr;
	}
	/*void Myself::spoilage(Alive& enem){
		enem.setdamage(enem.getdamage()-1);
		if (enem.getdamage()<0)
			enem.setdamage(0);
	}
	void Myself::pain(Alive& enem){
		enem.setdamage(enem.getdamage()-2);
		if (enem.getdamage()<0)
			enem.setdamage(0);
	}
	void Myself::pain(Alive& enem){
		enem.setdamage(enem.getdamage()-4);
		if (enem.getdamage()<0)
			enem.setdamage(0);
	}*/
	int Myself::curse(Alive& enem){
		int f = 0;
		tab t;
		while (f == 0){
			mvwprintw(stdscr, 25, 0, "Choose the curse: s - spoilage, p - pain, a - agony, r - rot\n");
			mvwprintw(stdscr, 26, 0, "e - exhaustion, c - contagion, d - desecration, m - madness");
			switch(getch()){
				case 's':
					t = find_in_table("spoilage");
					//mvwprintw(stdscr, 27, 0, "aaaa");
					if (t.charact == 0 || t.mana > mana)
						return 0;
					enem.setdamage(enem.getdamage()-1);
					if (enem.getdamage()<0)
						enem.setdamage(0);
					mana-=t.mana;
					exp++;
					return 0;
					break;
				case 'p':
					t = find_in_table("pain");
					if (t.charact == 0 || t.mana > mana)
						return 0;
					enem.setdamage(enem.getdamage()-2);
					if (enem.getdamage()<0)
						enem.setdamage(0);
					mana -=t.mana;
					exp = exp+2;
					return 0;
					break;
				case 'a':
					t = find_in_table("agony");
					if (t.charact == 0 || t.mana > mana)
						return 0;
					enem.setdamage(enem.getdamage()-4);
					if (enem.getdamage()<0)
						enem.setdamage(0);
					mana-=t.mana;
					exp = exp+3;
					return 0;
					break;
				case 'e':
					t = find_in_table("exhastion");
					if (t.charact == 0 || t.mana > mana)
						return 0;
					enem.sethit(enem.gethit()+1);
					mana-=t.mana;
					exp++;
					return 0;
					break;
				case 'r':
					t = find_in_table("rot");
					if (t.charact == 0 || t.mana > mana)
						return 0;
					enem.sethit(enem.gethit()+3);
					mana-=t.mana;
					exp+=2;
					return 0;
					break;
				case 'c':
					t = find_in_table("contagion");
					if (t.charact == 0 || t.mana > mana)
						return 0;
					enem.sethit(enem.gethit()+1);
					mana-=t.mana;
					exp++;
					return 0;
					break;
				case 'd':
					t = find_in_table("desecration");
					if (t.charact == 0 || t.mana > mana)
						return 0;
					enem.setcond(2);
					mana-=t.mana;
					exp++;
					return 0;
					break;
				case 'm':
					t = find_in_table("madness");
					if (t.charact == 0 || t.mana > mana)
						return 0;
					enem.setcond(2);
					enem.setdamage(enem.getdamage()+3);
					enem.sethit(enem.gethit()+5);
					mana-=t.mana;
					exp+=3;
					return 0;
					break;
			}
		}
		return 0;
	}
	Undead Create_slaves(Alive& en, std::vector <Undead> u ){
		Undead U;
		U.settype(en.getslaves_type());
		U.setmax_hp(rand()%5+1);
		U.sethp(en.getmax_hp());
		U.setname(en.getname());
		U.setx(en.getx()+rand()%4+1);
		U.sety(en.gety()+rand()%4+1);
		U.setfr(en.getfr());
		//u.push_back(U);
		return U;
	}
	Undead create_slaves(Undead& en, std::vector <Undead> u){
		Undead U;
		U.settype(en.gettype());
		U.setmax_hp(rand()%5+1);
		U.sethp(en.getmax_hp());
		U.setname(en.getname());
		U.setfr(en.getfr());
		U.setx(en.getx()+rand()%4+1);
		U.sety(en.gety()+rand()%4+1);	
		//u.push_back(U);
		return U;
	}
	std::vector <Undead> Myself::necromancy(Alive& enem, char c, std::vector <Undead> u, std::vector <coef> co){
		std::string type;
		tab t;
		if (c == 's')
			type = "skeleton";
		if (c == 'g')
			type = "ghost";
		if (c == 'f')
			type = "gul";
		if (c == 'z')
			type = "zombie";
		t = find_in_table(type);
		if (t.charact == 0 || (t.mana > mana)){
					//hp-=1;
			return u;
		}
		std::vector <coef> :: iterator it;
		int k;
		for (it = co.begin(); it<co.end(); it++){
			if (type == it->name)
				k = it->c;
		}
		mana -=t.mana;
		Undead U(enem, type, k);	
		u.push_back(U);
		enem.setx(-10);
		enem.sety(-10);
		exp+=3;
		//delete &enem;
		return u;
	}
}	
