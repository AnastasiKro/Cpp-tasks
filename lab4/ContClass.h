#include <string>
#include <iostream>
namespace MyClass{
template <class T>
	class en{
		T* e;
		en* next;
		int size;
		//Iterator It;
		public:
			int Size()const { return size;}
			T* get_e()const { return e;}
			en& set_e(T& a){e = a; return *this;}
			en* getnext()const {return next; }
			en& setnext(en* enemy){ next = enemy; return *this;}
			en(T* enemy);
			en(){ size = 0;next = nullptr;}
			en& add(T* enemy);
			en* begin() { return this; }
			en* end(){return nullptr;}
			en& del(int k);
			T* operator [](int k);
	};
template <class T>
	class Iterator{
		en<T>* it;
		public:
			en<T>* getit()const{ return it;}
			Iterator();
			Iterator<T> & operator =(en<T>* enemy);
			Iterator & operator ++(int a);
			bool operator == (en<T>* enemy);
			bool operator < (en<T>* enemy);
			bool operator > (en<T>* enemy);
			//Alive & operator --(int a);
	};
	template <class T>
	Iterator<T>::Iterator(){
		it = nullptr;
	}
	template <class T>
	Iterator<T>& Iterator<T>::operator =(en<T>* enemy){
		it = enemy;
		return *this;
	}
	template <class T>
	Iterator<T>& Iterator<T>::operator ++(int a){
		it = it->getnext();
		return *this;
	}
	template <class T>
	bool Iterator<T>::operator <(en<T>* enemy){
		return (it != enemy);
	}
	template <class T>
	bool Iterator<T>::operator >(en<T>* enemy){
		return (it!=enemy);
	}
	template <class T>
	bool Iterator<T>::operator ==(en<T>* enemy){
		return (it==enemy);
	}
		template <class T>
	en<T>::en(T* enemy){
		size = 1;
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
	template <class T>
	en<T>& en<T>::del(int k){
		if (k>0){
			en<T>* N = this;
		for (int i = 0; i<k-1;i++){
			N = N->getnext();
			if (N->getnext()==nullptr)
				return *this;
		}
		N->setnext(N->next->next);
		size-=1;
		}
		return *this;
	}

	template <class T>
	en<T>& en<T>::add(T* enemy){
		en<T>* N = begin();
		if (size == 0){
			e = enemy;
			size = 1;
			return *this;
		}
		while (N->next!=nullptr){
			N = N->next;
	       	}
		N->next=new en<T>(enemy);
		size+=1;
		return *this;
	}
	template <class T>
	T* en<T>::operator[](int k){
		en<T>* enemy = this;
		for (int i = 0; i<k; i++){
			if ( enemy->getnext()== nullptr)
				throw std::invalid_argument("invalid k");
			enemy = enemy->getnext();
		}
		return enemy->get_e();
	}
		
}
