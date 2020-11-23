#include "lab4.h"
#include <iostream>
#include <string>
namespace Necromancer{
	Iterator::Iterator(){
		it = nullptr;
	}
	Iterator& Iterator::operator =(en* enemy){
		it = enemy;
		return *this;
	}
	Iterator& Iterator::operator ++(int a){
		it = it->getnext();
		return *this;
	}
	bool Iterator::operator <(en* enemy){
		return (it != enemy);
	}
	bool Iterator::operator >(en* enemy){
		return (it!=enemy);
	}
	bool Iterator::operator ==(en* enemy){
		return (it==enemy);
	}
	


	en::en(Alive enemy){
		e = enemy;
		next = nullptr;
	}
	/*en* en::end(){
		en* enemy = this;
		while(enemy->getnext()!=nullptr)
			enemy = enemy->getnext();
		enemy = enemy->getnext();
		return enemy;
	}*/
	en& en::del(int k){
		if (k>0){
			en* N = this;
		for (int i = 0; i<k;i++){
			N = N->getnext();
			if (N->getnext()==nullptr)
				return *this;
		}
		N->setnext(N->next->next);
		}
		return *this;
	}


	en& en::add(Alive enemy){
		en* N = begin();
		while (N->next!=nullptr){
			//std::cout<<"sd" <<N->e.getname().c_str()<<std::endl;
			N = N->next;
	       	}
		N->next=new en(enemy);
		return *this;
	}
	Alive en::operator[](int k){
		en* enemy = this;
		for (int i = 0; i<k; i++){
			if ( enemy->getnext()== nullptr)
				throw std::invalid_argument("invalid k");
			enemy = enemy->getnext();
		}
		return enemy->get_e();
	}
		

		

}
