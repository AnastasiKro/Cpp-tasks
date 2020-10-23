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
			int p = findDice(dice.get1(), dice.get2());
			while (p != -1){
				dice.set1((dice.get1()+1)%7);
				dice.set2((dice.get2()+rand())%7);
				p = findDice(dice.get1(), dice.get2());
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
	Domino& Domino::SetDD(int n,Dice dices[]){
		N=n;
		for(int i = 0; i<n; i++){
			DD[i]=dices[i];
		}
		return *this;
	}
	Domino& Domino::SetAdd(Dice dice){
		DD[N]=dice;
		N+=1;
		return *this;
	}
	
	int Domino::findDice(int a1, int b1){
		for (int i =0; i<N; i++){
			if ((DD[i].get1()==a1 && DD[i].get2()==b1)||(DD[i].get1()==b1 && DD[i].get2()==a1))
				return i;
		}
		return -1;
	}

	std::ostream& operator<<(std::ostream& out, Domino& Dom){
		for (int i = 0; i<Dom.N;i++){
			std::cout<<"   ________"<<std::endl;
			out<<i+1<<".| "<<Dom.DD[i].get1()<<" | "<<Dom.DD[i].get2()<<" |"<<std::endl;		
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
		int p = findDice(dice.get1(), dice.get2());
		while (p != -1){
				dice.set1((dice.get1()+1)%7);
				dice.set2((dice.get2()+rand())%7);
				p = findDice(dice.get1(), dice.get2());
			}
		SetAdd(dice);
		return *this;
	}
	Domino& Domino::operator -=(const Dice& dice){
		int p = findDice(dice.get1(), dice.get2());
		if (p == -1){
			throw std::invalid_argument("Invalid value");
			//return *this;
		}
		DD[p]=DD[N-1];
		N-=1;
		return *this;
	}
	Dice& Domino::operator []( int k){
		return DD[k];
	}
	Domino& Domino::DomSort(){
		for (int i = 0; i<N-1; i++){
			for( int j = 0; j<N-1; j++){
				if (DD[j].get1()+DD[j].get2()>DD[j+1].get1()+DD[j+1].get2()){
					Dice D = DD[j];
					DD[j]=DD[j+1];
					DD[j+1]=D;
				}
			}
		}
		return *this;
	}
	Domino Domino::pdgr( int k){
		Dice* dices = new Dice[N];
		int n =0;
		for(int i = 0; i<N; i++){
			if (DD[i].get1() == k || DD[i].get2() == k){
				dices[n]=DD[i];
				n+=1;
			}
		}
		Domino D(n, dices);
		//Do.SetDD(n, dices);
		if (n>1)
			delete[] dices;
		else
			delete dices;
		return D;
	}
}
		

		

