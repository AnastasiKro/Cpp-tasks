#include <iostream>
#include "lab3.h"
namespace Prog3{

void print_menu(){	
		std::cout << "Input 0 to leave " << std::endl;
		std::cout <<"1 add new dice with random numbers"<<std::endl;
		std::cout <<"2 add new dice with your numbers"<< std::endl;
		std::cout <<"3 delete the dice"<<std::endl;
		std::cout<< "4 to open the dice"<<std::endl;
		std::cout<<"5 to sort the dice"<<std::endl;
		std::cout<<"6 to create subgrope of the dices with the number k"<<std::endl;
		std::cout<<"7 to print all the Domino"<<std::endl;
		std::cout<<"8 to create the Domino with n dices"<<std::endl;
}

void OpenDice( Domino &Dom){	
		std::cout<<"Input number of the dice"<<std::endl;
		int k; getNum(k);
		Dice d=Dom[k];
		Domino Do;
		Do.SetDD(1, &d);
		std::cout<<Do;
}
void Subgroup(const Domino &Dom){
		std::cout<<"Input the number"<<std::endl;
		int k; getNum(k);
		pdgr(Dom, k);
}
}
