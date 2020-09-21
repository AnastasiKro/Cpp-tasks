#include <iostream>
using namespace std;
namespace Prog2{
	struct Point{
		double x, y;
	};
	class Lemn{
		private:
			double c;
			Point F1, F2;
		public:
			//void set_F(double f1, double f2);
			Lemn();
			Lemn(Point f1);
			Lemn(Point f1, Point f2);
			Point getP1();
			Point getP2();
			double Rasst(double a);
			double Rad1(double a);// const { return sqrt(2)/(3*sqrt(cos(2*a)));}
			double Rad2(double a);
			double Ssect(double a);//const { return c*c/	
			double area() const{ return c*c*2; }
			char* frm();
	};
	template <class T>
	int getNum(T &a){
		int b = 0;
		do{
			cin>>a;
			if(!cin.good()){
				cin.clear();
				cin.ignore();
				cout << "Nope, I need a digit" <<endl;
			}
			else
				b=1;
		}while(b==0);
		return 0;
	}	
}

			
