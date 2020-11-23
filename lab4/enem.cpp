#include <iostream>
#include "lab4.h"
#include <string>
using namespace Necromancer;
int create(en& e){
	Alive a1("werewolf", 6, 6, 2, 1, 2);
	Alive a2("gul", 4, 3, 3, 1, 1);
	e.add(a1);
       	e.add(a2);
	e.add(a1);
	return 0;
}
int main(){
	std::string str = "ogr";
	int m = 5; int h = 4; int f = 2; int ex = 0; int c = 1;
	Alive enemy(str, m, h, f, ex, c);
	en e(enemy);
	create( e);
	/*Alive a1("werewolf", 6, 6, 2, 1, 2);
	Alive a2("gul", 4, 3, 3, 1, 1);
	e.add(a1);
       	e.add(a2);
	e.add(a1);*/
	Iterator It;
	for ( It = e.begin(); It<e.end(); It++){
	//	std::cout<<"aaa"<<std::endl;
		std::cout<< It.getname()<<std::endl;
		std::cout<< It.gethp()<<std::endl;
		std::cout<< It.getfr()<<std::endl;
	}
	return 0;
}


