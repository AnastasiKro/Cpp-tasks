#include <iostream>
#include "lab3.h"
using namespace Prog3;
int main(int argc, char* argv[]){
	int flag = 1;
	Domino Dom;
	do {
		std::cout << "Input 0 to leave " << std::endl;
		std::cout << "1 to create Domino of n elements "<<std::endl;
		std::cout <<"2 add new dice with random numbers"<<std::endl;
		std::cout <<"3 add new dice with your numbers"<< std::endl;
		std::cout <<"4 delete the dice"<<std::endl;
		std::cout<< "5 to open the dice"<<std::endl;
		std::cout<<"6 to sort the dice"<<std::endl;
		getNum(flag);
		if (flag ==1){
			Dom.~Domino();
			//Dom.del();
			int n;
			getNum(n);
			Domino Dom(n);
		}
		if (flag==2){
			Dom++;
		}
		if (flag==3){
			Dice dice;
			std::cin>>dice;
		}
		if (flag == 4){
			Dice dice;
			std::cin>>dice;
			Dom-=dice; 
		}
		//if (flag == 5){
			

	}while(flag!=0);
	return 0;
}
