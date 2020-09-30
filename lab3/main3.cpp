#include <iostream>
#include "lab3.h"
using namespace Prog3;
int main(int argc, char* argv[]){
	int flag = 1;
	Domino DD();
	do {
		std::cout << "Input 0 to leave " << endl;
		std::cout << "1 to create Domino of n elements "<<endl;
		std::cout <<"2 add new dice with random numbers"<<endl;
		std::cout <<"3 add new dice with your numbers"<< endl;
		std::cout <<"4 delete the dice"<<endl;
		st::cout<< "5 to open the dice"<<endl;
		std::cout<<"6 to sort the dice"<<endl;
		getNum(flag);
		if (flag ==1){
			delete DD;
			int n;
			getNum(n);
			Domino DD(n);
		}
		if (flag==2){
			DD++;
		}
		if (flag==3){
			Dice dice;
			std::cin>>dice;
		}
		if (flag == 4){
			DD-=; }
		//if (flag == 5){
			

	}while(flag!=0);
	return 0;
}
