#include <iostream>
#include <fstream>
#include "lab4.h"
//#include <ncurses.h>
using namespace Necromancer;
en Readfil( int* n){
	char line[10];
	char m[3];
	en* enemy = new en;
		std::ifstream in("/home/avtobus/3sem/lab2/3sem/lab4/config/enemies");
	if (in.is_open()){
		while (!in.eof()){
			Alive* a = new Alive;
			in.getline(line, 10);
			if (in.eof())
				break;
			in.getline(m, 3);
			std::cout<<m<<std::endl;
			if (in.eof())
				break;
			*n+=1;
			a->setname(line);
			std::cout<<*n<<" "<<line<<std::endl;
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
			if (*n == 1){
				delete enemy;
				en* enemy = new en(*a);
			}
			else
				enemy->add(*a);	
		}
	}
	in.close();
	return *enemy;
}
int printen(en e, int n){
	Iterator It;
	for (It = e.begin(); It<e.end(); It++){
		//std::cout<<"aaa"<<std::endl;
		std::cout<< It.getit()->get_e().getname().c_str()<<std::endl;
		std::cout<< It.getit()->get_e().getmax_hp();
		std::cout<< It.getit()->get_e().gethp();
	}
	return 0;
}
int main(){
	//initscr();
	//cbreak();
	//noecho();
	//scrollok(stdscr, TRUE);
	//nodelay(stdscr, TRUE);
	int n = 0;
	en e = Readfil(&n);
	//initscr();
	printen(e, n);
	//endwin();
	return 0;
}
