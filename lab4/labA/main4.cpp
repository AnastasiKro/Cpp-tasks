#include <iostream>
#include "lab4.h"
using namespace Prog4;

void print_menu(){
	std::cout<<"Input 0 to leave"<<std::endl;
	std::cout<<"1 "<<std::endl;
	std::cout<<"2"<<std::endl;
	std::cout<<"3 "<<std::endl;
	std::cout<<"4"<<std::endl;
	std::cout<<"5 "<<std::endl;
int main(){
	int flag;
	do {
		print_menu();
		getNum(flag);
		if (flag == 1)

		if (flag == 2)
		if (flag == 3)
		if (flag == 4)
		if (flag == 5)
		
	}while (flag !=0);
	return 0;
}


