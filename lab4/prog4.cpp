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
		//}
		enem.sethp(enem.gethp()-1);
		if (enem.gethp()<=0){
			enem.setcond(0);
			hp+=enem.getexp();

		if (hp>max_hp)
			hp = max_hp;
		exp+=3;
		if (exp>12){
			level+=1;
			exp=1;
		}
		enem.setx(-10);
		enem.sety(-10);
		}
	}
	void Myself::draining_mana(Alive& enem){
		enem.sethp(enem.gethp()-1);
		if (enem.gethp()<=0){
			enem.setcond(0);
		mana+=enem.getexp();
		if (mana>max_mana)
			mana=max_mana;
		exp+=3;
		enem.setx(-10);
		enem.sety(-10);
		if(exp>12){
			level+=1;
			exp=1;
		}
		}
	}
	int Myself::wounded(Alive& en){
		en.exp+=1;
		hp-=1;
		if (hp <=0)
			return 0;
		return 1;
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
	Undead::Undead(Alive& enem, char c){
		setname(enem.getname());
		setmax_hp(enem.getmax_hp());
		sethp(getmax_hp());
		setx(enem.getx());
		sety(enem.gety());
		setfr(1);
		if (c == 's')
			type = "skeleton";
		if (c == 'g')
			type = "ghowl";
		if (c == 'f')
			type = "gul";
		if (c == 'z')
			type = "zombie";
	}
	Myself::Myself(){
		exp = 0;
		hp = 7;
		level = 1;
		mana = 0;
		fr = 1;
		max_hp = level*2+5;
		max_mana = level*5+10;
	}
	void Myself::curse(Alive& enem){
	}
	std::vector <Undead> Myself::necromancy(Alive& enem, char c, std::vector <Undead> u){
		//printw("print s to turn it intoto skeleton, g - into ghowl, d - into gul, z - zombie");
		Undead U(enem, c);
		//std::cout<< U.getname()<<U.gettype()<<std::endl;

		u.push_back(U);
		exp+=1;
		//delete &enem;
		return u;

	}
	
}	
