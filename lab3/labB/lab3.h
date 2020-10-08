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
			struct Dice* DD;
			int N;
		public:
			Domino();
			Domino(int n);
			Domino(int n, Dice dices[]);
			Domino(const Domino& Dom);
			Domino& SetAdd(Dice dice);
			int getA(int k) const {return DD[k].a; }
			int getB(int k) const {return DD[k].b; }
			int getN() const {return N;}
			~Domino(){
				delete[] DD;
				//std::cout<<"Destructor worked here!"<<std::cout;
			}
			friend std::ostream & operator << (std::ostream& out, Domino& Dom);
			int findDice(int a1, int b1);
			//friend std::istream & operator >> (std::istream& in, Dice& dice);
			Domino & operator -= (const Dice &dice);
			Domino & operator ++(int a);
			int operator [](int k);
			Domino& operator =( Domino& Dom);
			Domino & DomSort();
			//void pdgr(int k)const;

	};
	void pdgr(const Domino& Dom, int k);
}

		
			

