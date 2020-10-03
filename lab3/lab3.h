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
				std::cout << "There shold be a digit, try again" <<std::endl;
			} else
				b = 1;
		}while(b==0);
		return 0;
	}
	struct Dice{
		int a;
		int b;
		Dice(){
			a=rand()%7;
			b=rand()%7;
		}
		Dice(int a1, int b1){
			a=a1; b= b1; }
		~Dice();
	};
	class Domino{
		private:
			struct Dice DD[28];
			int N;
		public:
			Domino();
			Domino(int n);
			Domino& SetAdd(Dice dice);
			int del(){
				delete this;
				return 0;
			}
			~Domino();
			//friend std::ostream & operator << ();
			friend std::istream & operator >> (std::istream in, Dice& dice);
			Domino & operator -= (const Dice &dice);
			Domino & operator ++();
			Dice &operator [](int k);
			//Domino & pdgr(int k);

	};
}

		
			

