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
			DD[i] = d;
			N+=1;
		}
	}
	/*std::ostream& Domino::operator<<(std::ostream& out, Domino& DD){
		out<<;
		return out;
	}*/
	std::istream& Domino::operator >>(std::istream in, Dice &dice){
		std::cout << "Введите 2 числа на кости"<< endl;
		try{
		in>> dice.a;
		in>>dice.b
		}
		catch(const std::exception &e){
			cout << "Exception!"<<endl;
			return 0;
		}
		return in;
	}
	Domino& Domino::operator ++(Domino DD){
		Dice dice;
		for (int i = 0; i< DD.N; i++){
			if (DD[i].a==dice.a && DD[i].b==dice.b){
				cout<< "Такая кость уже существует!"<<endl;
				return DD;
			}
		}
		DD[DD.N]=dice;
		DD.N+=1;
		return DD;
	}
	Domino& Domino:: operator -=(Domino DD){
		Dice dice;
		std::cin>>dice;
		for (int i = 0; i< DD.N; i++){
			if (DD[i].a==dice.a && DD[i].b==dice.b){
				DD[i]=DD[N-1];
				delete DD[N-1];
				DD.N-=1;
				break;
			}
		}
		return DD;
	}
	Dice& Domino::operator [](const Domino DD, int k){
		Dice dice(DD[k].a, DD[k].b);
		return dice;
	}
		

		

