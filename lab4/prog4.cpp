#include "lab4.h"
#include <ncurses.h>
#include <cstring>
#include <iostream>
namespace Necromancer{
	//template <class T>
	
	void Myself::draining_hp(Alive& enem){
		//std::cout<<
		//printw("Enemy is dead, input 1 to turn him into health; 2 to turn him into mana");//<<std::endl;
		//int n = getch();
		//if (n == '2'){
		//	mana+=enem.getexp();
		//}
		//if (n == '1'){
			hp+=enem.getexp();
		//}
		exp+=3;
		if (exp>12){
			level+=1;
			exp=1;
		}
	}
	void Myself::draining_mana(Alive& enem){
		mana+=enem.getexp();
		exp+=3;
		if(exp>12){
			level+=1;
			exp=1;
		}
	}
	Alive::Alive(){
		setname("");
		setmax_hp(0);
		setexp(rand()%7+1);
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
		setfr(1);
		if (c == 's')
			type = "skeleton";
		if (c == 'g')
			type = "ghowl";
		if (c == 'd')
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
	}
	void Myself::curse(Alive& enem){
	}
	Undead Myself::necromancy(Alive& enem){
		printw("print s to turn it intoto skeleton, g - into ghowl, d - into gul, z - zombie");
		char c = getch();
		Undead U(enem, c);
		delete &enem;
		return U;

	}
}	
