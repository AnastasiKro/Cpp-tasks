#include <iostream>
#include "lab2.h"

using namespace std;

int main(int argc, char* argv[]){
	int flag = 0;
	double n;
	Prog2::Lemn L;
	do{
		cout << "Введите 0 чтобы выйти," << endl;
		cout<< "1 ввести координаты фокусов лемнискаты"<<endl;
		cout<<"2 найти расстояние отцентра в полярной системе координат в зависимости от угла"<<endl;
		cout <<"3 радиус кривизны в зависимости от угла полярного радиуса "<<endl;
		cout << "4 to радиус кривизны в зависимости от длины полярного радиуса"<<endl;
		cout << "5 площадь полярного сектора в зависимости от угла"<<endl;
		cout << "6 площад лемнискаты"<<endl;
		cout << "7 состояние лемнискаты: фокусы и с" << endl;
		Prog2::getNum(flag);
		if (flag == 1){
			cout<<"Если хотите ввести координаты F1, введите 1, если F1 и F2, то введите 2" <<endl;
			Prog2::getNum(n);
			if (n==1 || n==2){
			Prog2::Point f1;
			Prog2::getNum(f1.x);
			Prog2::getNum(f1.y);
			if (n==1){
				L.set1f(f1);
			}
			if(n==2){
				Prog2::Point f2;
				Prog2::getNum(f2.x);
				Prog2::getNum(f2.y);
				L.set2f(f1, f2);
			}}
		}
		if (flag ==2){
			cout << "Введите угол в радинах"<<endl;
			Prog2::getNum(n);
			double r = L.Rasst(n);
			cout << "Ваше расстояние "<< r<<endl;
		}
		if (flag ==3){
			cout << "Введите угол в радинах"<<endl;
			Prog2::getNum(n);
			double r = L.Rad1(n);
			cout << "Ваш радиус "<< r<<endl;

		}
		if (flag ==4){
			cout << "Введите длину радиуса"<<endl;
			Prog2::getNum(n);
			double r =L.Rad2(n);
			cout << "Ваш радиус "<< r<<endl;

		}
		if (flag ==5){
			cout << "Введите угол в радинах"<<endl;
			Prog2::getNum(n);
			double r = L.Ssect(n);
				cout << "Площадь сектора: "<< r<<endl;

		}
		if (flag ==6){
			double r = L.area();
			cout << "Площадь Лемнискаты: "<<r<<endl;
		}
		if (flag ==7){
			Prog2::Point f1 = L.getP1();
			Prog2::Point f2 = L.getP2();
			cout << "F1:  x="<<f1.x << "  y="<<f1.y<<endl;
			cout << "F2:  x="<<f2.x <<"  y="<<f2.y<<endl;
			cout << L.frm();
		}

	}while(flag!=0);
	return 0;
}

