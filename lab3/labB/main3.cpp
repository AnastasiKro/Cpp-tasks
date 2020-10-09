#include <iostream>
#include "lab3.h"
using namespace Prog3;

int main(int argc, char* argv[]){
	int flag = 1;
	Domino Dom;
	do {
		print_menu();
		getNum(flag);
		if (flag==1){
			Dom++;
		}
		if (flag==2){
			Dice dice;
			std::cin>>dice;
			Dom.SetAdd(dice);
		}
		if (flag == 3){
			Dice dice;
			std::cin >> dice;
			Dom-=dice; 
		}
		if (flag == 4){
			OpenDice(Dom);
		}
		if (flag == 5){
			Dom.DomSort();
		}
		if (flag == 6){
			Subgroup(Dom);
		}
		
		if (flag == 7){
			std::cout << Dom;
		}
		if (flag == 8){
			std::cout<<"Input n"<<std::endl;
			int n; getNum(n);
			Domino D(n);
			Dom = D;
		}
	}while(flag!=0);
	return 0;
}
