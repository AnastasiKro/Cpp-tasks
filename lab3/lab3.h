#include <iostream>

namespace Prog3{
	template <class T>
	int getNum(T &a){
		int b = 0;
		do{
			std::cin>>a;
			if (!std::cin.good()){
				std::cin.clear();
				std::cin.ignore();
				//std::cout << "There shold be a digit, try again" <<std::endl;
			} else
				b = 1;
		}while(b==0);
		return 0;
	}
	struct Dice{
		int a;
		int b;
		Dice();
		Dice(int a1, int b1);
		friend std::istream & operator >> (std::istream& in, Dice& dice);
		//~Dice();
	};
	class Domino{
		private:
			struct Dice DD[28];
			int N;
		public:
			Domino();
			Domino(int n);
			Domino(int n, Dice* dices);
			Domino& SetAdd(Dice dice);
			int del(){
				delete this;
				return 0;
			}
			//~Domino();
			friend std::ostream & operator << (std::ostream& out, Domino& Dom);
			int findDice(int a1, int b1);
			//friend std::istream & operator >> (std::istream& in, Dice& dice);
			Domino & operator -= (const Dice &dice);
			Domino & operator ++(int a);
			Domino* operator [](Domino* D);
			Domino & DomSort();
			Domino* pdgr();

	};
}

		
			

