#include <iostream>
#include <fstream>
#include "lab4.h"
namespace Necromancer{
	Myself Readme(){
		Myself me;

		char line[3];
		char str[20];
		std::vector <tab> T;
		std::ifstream in("/home/avtobus/3sem/lab2/3sem/lab4/config/myself");
		if (in.is_open()){
			in.getline(line, 3);
			me.setexp(atoi(line));
			in.getline(line, 3);
			me.setlevel(atoi(line));
		//	in.getline(line);
		//	me.setx(atoi(line));
		//	in.getline(line, 3);
		//	me.sety(atoi(line));
			in.getline(line, 3);
			me.setfr(atoi(line));
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
				me.setV(T);
			}
			in.close();
		}
		std::ifstream inn("/home/avtobus/3sem/lab2/3sem/lab4/config/Curses");
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
				me.setV(T);
			}
			inn.close();
		}
		return me;
	}
	std:: vector <coef> ReadCoef(){
		char line[10];
		std::vector <coef> c;
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
				c.push_back(co);
			}
			in.close();
		}
		return c;
	}
	std::vector <Undead> ReadUndead(){
		char line[10];
		std::vector <Undead> u;
		std::ifstream in("/home/avtobus/3sem/lab2/3sem/lab4/config/Undead");
		if (in.is_open()){
			while(!in.eof()){
				in.getline(line, 10);
				if(in.eof())
					break;
				Undead U;
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
				U.sethit(atoi(line));
				in.getline(line, 10);
				U.setfr(atoi(line));
				in.getline(line, 2);
				U.setPr(atoi(line));
				u.push_back(U);
		}
			in.close();
		}
		return u;
	}

		
Alive* Readfile( int* n){
	char line[10];
	Alive* e;
		std::ifstream in("/home/avtobus/3sem/lab2/3sem/lab4/config/enemies");
	if (in.is_open()){
		while (!in.eof()){
			in.getline(line, 10);
			if (in.eof())
				break;
			char* m = new char[3];
			in.getline(m, 3);
			if (in.eof())
				break;
			*n+=1;
			Alive* ee = new Alive[*n];
			for (int i = 0; i<*n-1; i++)
				ee[i]=e[i];
			ee[*n-1].setname(line);
			ee[*n-1].setmax_hp(atoi(m));
			//if (in.eof())
			//	break;
			in.getline(m,3);
			ee[*n-1].sethp(atoi(m));
			in.getline(m, 3);
			ee[*n-1].setexp(atoi(m));
			in.getline(m, 3);
			ee[*n-1].setfr(atoi(m));
			in.getline(m, 3);
			ee[*n-1].setdamage(atoi(m));
			in.getline(m, 3);
			ee[*n-1].sethit(atoi(m));
			ee[*n-1].setx(rand()%20);
			ee[*n-1].sety(rand()%20);
			ee[*n-1].setcond(1);
			in.getline(m, 3);
			ee[*n-1].setPr(atoi(m));
			in.getline(line, 10);
			ee[*n-1].setslaves_type(line);
			if (*n>2)
				delete[] e;
			delete[] m;
			e = ee;
		}
	}
	in.close();
	return e;
}

}
