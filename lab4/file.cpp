#include <iostream>
#include <fstream>
#include "lab4.h"
namespace Necromancer{
	Myself Readme(){
		Myself me;

		char line[3];
		char str[10];
		std::ifstream in("/home/avtobus/3sem/lab2/3sem/lab4/myself");
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
			std::vector <tab> T;
			while (!in.eof()){
				tab t1;
				in.getline(str, 10);
				if (in.eof())
					break;
				t1.name = str;
				in.getline(str, 10);
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
		return me;
	}

		
Alive* Readfile( int* n){
	char line[10];
	Alive* e;
		std::ifstream in("/home/avtobus/3sem/lab2/3sem/lab4/enemies");
	if (in.is_open()){
		while (!in.eof()){
			in.getline(line, 10);
			if (in.eof())
				break;
			char* max_hp = new char[3];
			*n+=1;
			Alive* ee = new Alive[*n];
			for (int i = 0; i<*n-1; i++)
				ee[i]=e[i];
			ee[*n-1].setname(line);
			in.getline(max_hp, 3);
			ee[*n-1].setmax_hp(atoi(max_hp));
			//std::cout<<x1<<std::endl;
			//if (in.eof())
			//	break;
			in.getline(max_hp,3);
			//std::cout<<y1<<std::endl;
			ee[*n-1].sethp(atoi(max_hp));
			in.getline(max_hp, 3);
			ee[*n-1].setexp(atoi(max_hp));
			in.getline(max_hp, 3);
			ee[*n-1].setfr(atoi(max_hp));
			ee[*n-1].setx(rand()%20);
			ee[*n-1].sety(rand()%20);
			ee[*n-1].setcond(1);
			if (*n>2)
				delete[] e;
			delete[] max_hp;
			e = ee;
		}
	}
	in.close();
	return e;
}

}
