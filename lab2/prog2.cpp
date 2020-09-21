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
		c=sqrt(f1.x*f1.x+f1.y*f1.y);
		f1.x=c;
		f1.y=0;
		F1=f1;
		Point f2;
		f2.x=-c;
		f2.y=0;
		F2=f2;
	}
	Lemn::Lemn(Point f1, Point f2){
		double C =sqrt((f2.x-f1.x)*(f2.x-f1.x)+(f2.y-f1.y)*(f2.y-f1.y));
		F1.x=C;
		F1.y=0;
		F2.x=-C;
		F2.y=0;
		c=C;
	}
	Point Lemn::getP1(){
		return F1;
	}
	Point Lemn::getP2(){
		return F2;
	}
	char* Lemn::frm(){
		char* s1 ="(x^2 + y^2)^2 = 2*  (x^2 - y^2)";
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
	double Lemn::Rasst(double a){
		if(cos(2*a)<0)
			return 0;
		double R=sqrt(2)*c*sqrt(cos(2*a));
		return R;
	}
	double Lemn::Rad1(double a){
		if(cos(2*a)<0)
			return 0;
		return sqrt(2)/(3*sqrt(cos(2*a)));
	}
	double Lemn::Rad2(double d){
		if (d<=0){
			cout<<"illegal d"<<endl;
			return 0;
		}
			//throw exception("illegal argument d");
		return (2*c)/(3*d);
	}
	double Lemn::Ssect(double a){
		if (a> -3,141592/4&&a<3,141592/4)
			return (c*c*sin(2*a))/2;
		else{
			cout<<"wrong angle, you need [-pi/4; pi/4]"<< endl;
			return -1;
		}
	}
}



