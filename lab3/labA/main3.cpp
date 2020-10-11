#include <iostream>
#include "lab3.h"
using namespace Prog3;

void print_menu();
void OpenDice(Domino Dom);
void Subgroup(Domino Dom);

int main(int argc, char* argv[]){
	int flag = 1;
	Domino Dom(5);
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
			

	}while(flag!=0);
	return 0;
}


void print_menu(){	
		std::cout << "Input 0 to leave " << std::endl;
		std::cout <<"1 add new dice with random numbers"<<std::endl;
		std::cout <<"2 add new dice with your numbers"<< std::endl;
		std::cout <<"3 delete the dice"<<std::endl;
		std::cout<< "4 to open the dice"<<std::endl;
		std::cout<<"5 to sort the dice"<<std::endl;
		std::cout<<"6 to create subgrope of the dices with the number k"<<std::endl;
		std::cout<<"7 to print all the Domino"<<std::endl;
}
void OpenDice(Domino Dom){	
		std::cout<<"Input number of the dice"<<std::endl;
		int k; getNum(k);
		//Domino* D;
		Dom[k];
}
void Subgroup(Domino Dom){
		std::cout<<"Input the number"<<std::endl;
		int k; getNum(k);
		Domino Do;
		Dom.pdgr(Do,k);
}
