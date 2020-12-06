#include <iostream>
#include "ContClass.h"
#include <string>
using namespace MyClass;
int main(){
	std::string str = "ogr";
	int* m= new int(5); int* h =new int(4); int* f = new int(2); int* ex = new int(0); int* c = new int(1);
	//Alive enemy(str, m, h, f, ex, c);
	en<int> e;
	e.add(h);
	e.add(m);
	e.add(f);
	e.add(ex);
	e.del(1);
	/*Alive a1("werewolf", 6, 6, 2, 1, 2);
	Alive a2("gul", 4, 3, 3, 1, 1);
	e.add(a1);
       	e.add(a2);
	e.add(a1);*/
	Iterator <int> It;
	for ( It = e.begin(); It<e.end(); It++){
		std::cout<<*(It.it->get_e())<<std::endl;
		//std::cout<< It.getname()<<std::endl;
		//std::cout<< It.gethp()<<std::endl;
		//std::cout<< It.getfr()<<std::endl;
	}

	e.clear();
	e.add(m);
	for ( It = e.begin(); It<e.end(); It++)
		std::cout<<*(It.it->get_e())<<std::endl;
	return 0;
}


