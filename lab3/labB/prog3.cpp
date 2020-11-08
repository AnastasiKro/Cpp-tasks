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
		DD = new Dice[1];
		DD[0]=d;
		N=1;
	}
	Domino& Domino::SetDD(int n, Dice dices[]){
			delete[] DD;
		
		DD = new Dice[n];
		N=n;
		for (int i = 0; i<n; i++)
			DD[i]=dices[i];
		return *this;
	}
	Domino::Domino(int n){
		DD= new Dice[n];
		N=0;
		for (int i = 0; i<n; i++){
			Dice dice;
			int p = findDice(dice.get1(), dice.get2());
			while (p != -1){
				dice.set1((dice.get1()+1)%7);
				dice.set2((dice.b+rand())%7);
				p = findDice(dice.get1(), dice.get1());
			}
			SetAdd(dice);
		}
	}
	Domino::Domino(int n, Dice* dices){
		N=n;
		DD = new Dice[n];
		for(int i = 0; i<n; i++){
			DD[i]= dices[i];
		}
	}
	Domino::Domino(const Domino& Dom)
	{
	//	if (N>1)
	//		delete[] DD;
		N = Dom.N;
		DD= new Dice[N];
		for (int i = 0; i< N; i++)
			DD[i]=Dom.DD[i];
		std::cout<<"Copy constructor worked!"<<std::endl;
	}
	Domino::Domino(Domino& Dom):
		N(Dom.N), DD(Dom.DD)
	{
		Dom.DD=nullptr;
	}
	Domino& Domino::SetAdd(Dice dice){
		if (findDice(dice.get1(), dice.get2())!=-1){
			std::cout<<"The dice already exists"<<std::endl;
			return *this;
		}
		Dice* DDD = new Dice[N+1];
		for (int i = 0; i<N; i++)
			DDD[i]=DD[i];
		DDD[N]=dice;
		N+=1;
			delete[] DD;
		DD=DDD;
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
			std::cout<<"There is no such dice"<<std::endl;
			return *this;
		}
		DD[p]=DD[N-1];
		Dice* DDD=new Dice[N-1];
		for (int i = 0; i< N-1; i++)
			DDD[i]=DD[i];
		//if (N>1)
			delete[] DD;
		DD=DDD;
		N-=1;
		return *this;
	}
	Dice& Domino::operator [](int k){
		if (k>=N||k<0)
			throw std::invalid_argument("invalid k!");
		return DD[k];
	}
	Domino& Domino::operator =(Domino& Dom){//replacement operator
		
		//if (N>1)
			delete[] DD;
		DD=Dom.DD;
		N=Dom.N;
		Dom.DD=nullptr;
		return *this;
	}
	Domino & Domino::operator =(const Domino& Dom){ //copy operator
		if (&Dom == this)
			return *this;

			delete[] DD;
		N= Dom.N;
		DD = new Dice[N];
		for (int i = 0; i<N; i++)
			DD[i]=Dom.DD[i];
		return *this;
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
	Domino Domino::pdgr(int k)const{
		Dice* dices = new Dice[N];
		int n =0;
		for(int i = 0; i<N; i++){
			if (DD[i].get1() == k || DD[i].get2() == k){
				dices[n]=DD[i];
				n+=1;
			}
		}
		Domino Do(n, dices);
			delete[] dices;
		return Do;
	}
}

