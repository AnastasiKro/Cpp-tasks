#include <iostream>
#include "ContClass.h"
#include <string>
using namespace MyClass;
int create(en<int>& e){
//	Alive a1("werewolf", 6, 6, 2, 1, 2);
//	Alive a2("gul", 4, 3, 3, 1, 1);
	e.add(3);
       	e.add(2);
	e.add(1);
	e.del(2);
	return 0;
}
int main(){
	std::string str = "ogr";
	int m = 5; int h = 4; int f = 2; int ex = 0; int c = 1;
	//Alive enemy(str, m, h, f, ex, c);
	en<int> e;
	e.add(4);
	create( e);
	/*Alive a1("werewolf", 6, 6, 2, 1, 2);
	Alive a2("gul", 4, 3, 3, 1, 1);
	e.add(a1);
       	e.add(a2);
	e.add(a1);*/
	Iterator <int> It;
	for ( It = e.begin(); It<e.end(); It++){
		std::cout<<It.getit()->get_e()<<std::endl;
		//std::cout<< It.getname()<<std::endl;
		//std::cout<< It.gethp()<<std::endl;
		//std::cout<< It.getfr()<<std::endl;
	}
	return 0;
}


