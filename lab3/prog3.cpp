#include <iostream>
#include "lab3.h"

namespace Prog3{
	Dice::Dice(){
		a=rand()%7;
		b=rand()%7;
	}
	Dice::Dice(int a1, int b1){
		a=a1;
		b=b1;
	}
	Domino::Domino(){
		Dice d;
		DD[0]=d;
		N=1;
	}
	Domino::Domino(int n){
		N=0;
		for (int i = 0; i<n; i++){
			Dice dice;
			int p = findDice(dice.a, dice.b);
			while (p != -1){
				dice.a=(dice.a+1)%7;
				dice.b = (dice.b+rand())%7;
				p = findDice(dice.a, dice.b);
			}
			SetAdd(dice);
		}
	}
	Domino::Domino(int n, Dice dices[]){
		N=0;
		for(int i = 0; i<n; i++){
			SetAdd(dices[i]);
		}
	}
	Domino& Domino::SetAdd(Dice dice){
		DD[N]=dice;
		N+=1;
		return *this;
	}
	
	int Domino::findDice(int a1, int b1){
		for (int i =0; i<N; i++){
			if ((DD[i].a==a1 && DD[i].b==b1)||(DD[i].a==b1 && DD[i].b==a1))
				return i;
		}
		return -1;
	}

	std::ostream& operator<<(std::ostream& out, Domino& Dom){
		for (int i = 0; i<Dom.N;i++){
			std::cout<<"   ________"<<std::endl;
			out<<i+1<<".| "<<Dom.DD[i].a<<" | "<<Dom.DD[i].b<<" |"<<std::endl;		
			std::cout<<"   --------"<<std::endl;
		}
		return out;
	}
	std::istream& operator >> (std::istream &in, Dice& dice){
		std::cout << "input two numbers on the dice"<< std::endl;
		try{
		in >> dice.a;
		in >> dice.b;
		}
		catch(const std::exception &e){
			std::cout << "Exception!"<<std::endl;
		}
		return in;
	}
	Domino& Domino::operator ++(int a){
		Dice dice;
		int p = findDice(dice.a, dice.b);
		while (p != -1){
				dice.a=(dice.a+1)%7;
				dice.b = (dice.b+rand())%7;
				p = findDice(dice.a, dice.b);
			}
		SetAdd(dice);
		return *this;
	}
	Domino& Domino::operator -=(const Dice& dice){
		int p = findDice(dice.a, dice.b);
		if (p == -1){
			std::cout<<"There is no such dice"<<std::endl;
			return *this;
		}
		DD[p]=DD[N-1];
		N-=1;
		return *this;
	}
	int Domino::operator [](int k){
		if (k>N||k<1)
			return 0;
		Domino Do(1, DD+k-1);
		std::cout<<Do;
		//Dice dice(DD[k].a, DD[k].b);
		return 1;
	}
	Domino& Domino::DomSort(){
		for (int i = 0; i<N-1; i++){
			for( int j = 0; j<N-1; j++){
				if (DD[j].a+DD[j].b>DD[j+1].a+DD[j+1].b){
					Dice D = DD[j];
					DD[j]=DD[j+1];
					DD[j+1]=D;
				}
			}
		}
		return *this;
	}
	Domino* Domino::pdgr(int k){
		//std::cout<<"Input the number"<<std::endl;
		//int k; getNum(k);
		Dice* dices = new Dice[N];
		int n =0;
		for(int i = 0; i<N; i++){
			if (DD[i].a == k || DD[i].b == k){
				dices[n]=DD[i];
				n+=1;
			}
		}
		
		Domino Do(n, dices);
		std::cout<<Do;
		Domino* D = &Do;
		return D;
	}
}
		

		

