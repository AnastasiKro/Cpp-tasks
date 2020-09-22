#include <iostream>
#include <stdio.h>
#include <cstring>
#include "lab2.h"
#include <cmath>
using namespace std;
namespace Prog2{
	Lemn::Lemn(){
		Point f1, f2;
		f1.x=1;
		f1.y=0;
		f2.x=-1;
		f2.y=0;
		F1=f1;
		F2=f2;
		c=1;
	}
	Lemn::Lemn(Point f1){	
		Point f2;
		f2.x=-1;
		f2.y=0;
		c=sqrt((f2.x-f1.x)*(f2.x-f1.x)+(f2.y-f1.y)*(f2.y-f1.y))/2;
		f1.x=c;
		f1.y=0;
		f2.x=-c;
		F1=f1;
		F2=f2;
	}
	Lemn::Lemn(Point f1, Point f2){
		c =sqrt((f2.x-f1.x)*(f2.x-f1.x)+(f2.y-f1.y)*(f2.y-f1.y))/2;
		F1.x=c;
		F1.y=0;
		F2.x=-c;
		F2.y=0;
	}
	Lemn& Lemn::set1f(Point f1){
		c =sqrt((F2.x-f1.x)*(F2.x-f1.x)+(F2.y-f1.y)*(F2.y-f1.y))/2;
		F1.x=c;
		F1.y=0;
		F2.x=-c;
		F2.y=0;
		return *this;
	}
	Lemn& Lemn::set2f(Point f1, Point f2){
		c =sqrt((f2.x-f1.x)*(f2.x-f1.x)+(f2.y-f1.y)*(f2.y-f1.y))/2;
		F1.x=c;
		F1.y=0;
		F2.x=-c;
		F2.y=0;
		return *this;
	}
	char* Lemn::frm()const{
		const char* s1 ="(x^2 + y^2)^2 = 2*  (x^2 - y^2)";
		int l = strlen(s1);
		char* buf = new char[20];
		sprintf(buf, "%.2f", c);
		l+=strlen(buf);
		char* s = new char[l];
		sprintf(s, "%s", "(x^2 + y^2)^2 = 2*");
		int k = strlen(s);
		sprintf(s+k, "%.2f", c);
		k = strlen(s);
		sprintf(s+k, "*(x^2 - y^2)");
		return s;
	}
	double Lemn::Rasst(double a)const {
			double R=sqrt(2)*c*sqrt(abs(cos(2*a)));
			return R;
	}
	double Lemn::Rad1(double a)const{
		if(c==0)
			return 0;
		if(cos(2*a)==0)
			return 0;
			return sqrt(2)/(3*sqrt(abs(cos(2*a))));
	}
	double Lemn::Rad2(double d)const{
		if (d<=0 || d>c*sqrt(2)){
			cout<<"illegal d"<<endl;
			return 0;
		}
			//throw exception("illegal argument d");
		return (2*c)/(3*d);
	}
	double Lemn::Ssect(double a)const{
		while(a-2*3.141592>=0){
			a=a-2*3.141592;
		}
			return (c*c*abs(sin(2*a)))/2;
	}
}



