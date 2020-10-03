#include <iostream>
#include "lab3.h"

namespace Prog3{
	Domino::Domino(){
		Dice d;
		DD[0]=d;
		N=1;
	}
	Domino::Domino(int n){
		N=0;
		for (int i = 0; i<n; i++){
			int a1= rand()%7;
			int b1= rand()%7;
			Dice d(a1, b1);
			SetAdd(d);
			//DD[i] = d;
			//N+=1;
		}
	}
	Domino& Domino::SetAdd(Dice dice){
		DD[N]=dice;
		N+=1;
		return *this;
	}
		
	/*std::ostream& Domino::operator<<(std::ostream& out, Domino& DD){
		out<<;
		return out;
	}*/
	std::istream& operator >>(std::istream &in, Dice &dice){
		std::cout << "Введите 2 числа на кости"<< std::endl;
		//try{
		in>> dice.a;
		in>>dice.b;
		/*}
		catch(const std::exception &e){
			std::cout << "Exception!"<<std::endl;
			return 0;
		}*/
		return in;
	}
	Domino& Domino::operator ++(){
		Dice dice;
		for (int i = 0; i<N; i++){
			if ((DD[i].a==dice.a && DD[i].b==dice.b)||(DD[i].a==dice.b && DD[i].b == dice.a)){
				//cout<< "Такая кость уже существует!"<<endl;
				//return DD;
				dice.a=(dice.a+1)%7;
				dice.b = (dice.b+rand())%7;
				i = 0;
			}
		}
		SetAdd(dice);
		//DD[N]=dice;
		//N+=1;
		return *this;
	}
	Domino& Domino::operator -=(const Dice& dice){
		//Dice dice;
		//std::cin>>dice;
		for (int i = 0; i<N; i++){
			if ((DD[i].a==dice.a && DD[i].b==dice.b)||(DD[i].a==dice.b && DD[i].b == dice.a)){
				DD[i]=DD[N-1];
				N-=1;
				break;
			}
		}
		return *this;
	}
	Dice& Domino::operator [](int k){
		Dice dice(DD[k].a, DD[k].b);
		return dice;
	}
}
		

		

