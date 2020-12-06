#include <string>
#include <iostream>
namespace MyClass{
	template <class T>
	class Iterator;
	template <class T>
	class list{
		//friend class Iterator<T>;
		T* e;
		list* next;
		public:
			list(){ next = nullptr; e = nullptr;}
			list* getnext()const {return next;}
			list& setnext(list* L){next = L; return *this;}
			T* get_e()const { return e;}
			void set_e(T* a){e = a;}
		friend class Iterator<T>;
	};
template <class T>
	class en{
		//friend class Iterator<T>;
		list<T> L;
		int size;
		public:
			int Size()const { return size;}
			en(T* enemy);
			en(){ size = 0;}
			en& add(T* enemy);
			list<T>* begin();
			//list <T> getlist()const {return L;}
			list<T>* end(){return nullptr;}
			en& del(int k);
			T* operator [](int k);
			void clear();
			//void setL(list<T> l){L=l;}
	};
template <class T>
	class Iterator{
		friend class list<T>;
		//list<T>* it;
		public:
			T* item()const{ return it->get_e();}
			list<T>* it;
			list<T>* getit()const{ return it;}
			Iterator();
			Iterator<T> & operator =(list<T>* enemy);
			Iterator & operator ++(int a);
			bool operator == (list<T>* enemy);
			bool operator < (list<T>* enemy);
			bool operator > (list<T>* enemy);
			//Alive & operator --(int a);
	};
	template <class T>
	Iterator<T>::Iterator(){
		it = nullptr;
	}
	template <class T>
	Iterator<T>& Iterator<T>::operator =(list<T>* enemy){
		it = enemy;
		return *this;
	}
	template <class T>
	Iterator<T>& Iterator<T>::operator ++(int a){
		it = it->next;
		return *this;
	}
	template <class T>
	bool Iterator<T>::operator <(list<T>* enemy){
		return (it != enemy);
	}
	template <class T>
	bool Iterator<T>::operator >(list<T>* enemy){
		return (it!=enemy);
	}
	template <class T>
	bool Iterator<T>::operator ==(list<T>* enemy){
		return (it==enemy);
	}
		template <class T>
	en<T>::en(T* enemy){
		size = 1;
		L.set_e(enemy);
		L.setnext(nullptr);
	}
	template <class T>
	list<T>* en<T>::begin(){
		if (size == 0)
			return nullptr;
		return &L;
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
		if (k<0 ||k>=size)
			return *this;
		if (k>0){
			list<T>* N = begin();
		for (int i = 0; i<k-1;i++){
			N = N->getnext();
			if (N->getnext()==nullptr)
				return *this;
		}
		list<T>* n =N->getnext();
		N->setnext(n->getnext());
		delete n;
		size-=1;
		}
		return *this;
	}
	template <class T>
	void en<T>::clear(){
		if (size!=0){
		list<T>* N = begin();
		delete N->get_e();
		N->set_e(nullptr);
		N->setnext(nullptr);
		list<T>* N2 = N->getnext();
		while(N2!=nullptr){
			//delete N->e;
			//N2 = N->getnext();
			delete N2->get_e();
			N=N2->getnext();
			delete N2;
			N2=N;
		}
		size = 0;}
	}

	template <class T>
	en<T>& en<T>::add(T* enemy){
		if (size == 0){
			//list<T> n;
			L.set_e(enemy);
			L.setnext(nullptr);
			size = 1;
			
			return *this;
		}
		list<T>* N = begin();
		while (N->getnext()!=nullptr){
			N = N->getnext();
	       	}
		list<T>* l = new list<T>;
		l->set_e(enemy);
		N->setnext(l);
		size+=1;
		return *this;
	}
	template <class T>
	T* en<T>::operator[](int k){
		list<T>* N = L;
		for (int i = 0; i<k; i++){
			if ( N->getnext()== nullptr)
				throw std::invalid_argument("invalid k");
			N = N->getnext();
		}
		return N->get_e();
	}
		
}
