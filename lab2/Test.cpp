#include "gtest/gtest.h"
#include "prog2.cpp"
#include <cmath>
using namespace Prog2;
TEST(LemnConstructor, DefaultConstructor)
{
	Lemn a1;
	ASSERT_EQ(1, a1.getP1().x);
	ASSERT_EQ(0, a1.getP1().y);
	ASSERT_EQ(-1, a1.getP2().x);
	ASSERT_EQ(0, a1.getP2().y);
	}
TEST(LemnConstructor, InitConstructor){
	Point F1;
	F1.x = 2;
	F1.y = 4;
	Lemn a2(F1);
	ASSERT_EQ(2.5, a2.getP1().x);
	ASSERT_EQ(0, a2.getP1().y);
	Point f1; 
	Point f2;
	f1.x=5;
	f1.y=1;
	f2.x=-3;
	f2.y=1;
	Lemn a3(f1, f2);
	ASSERT_EQ(4, a3.getP1().x);
	ASSERT_EQ(0, a3.getP1().y);
	ASSERT_EQ(-4, a3.getP2().x);
	ASSERT_EQ(0, a3.getP2().y);
}
TEST(Lemnmethods, Parametrs){
	Point F1;
	F1.x = 2;
	F1.y = 4;
	const double err = 0.0001;
	Lemn a1(F1);
	ASSERT_EQ(2.5, a1.getP1().x);
	ASSERT_NEAR(sqrt(2)*2.5*sqrt(cos(0.4)), a1.Rasst(0.2), err);
	ASSERT_NEAR(sqrt(2)/(3*sqrt(cos(0.4))), a1.Rad1(0.2), err);
	ASSERT_NEAR(0.8333, a1.Rad2(2), err);
	ASSERT_EQ(12.5, a1.area());
	ASSERT_NEAR(6.25*sin(0.4)/2, a1.Ssect(0.2), err);
	ASSERT_STREQ("(x^2 + y^2)^2 = 2*2.50*(x^2 - y^2)", a1.frm());
	Point f2;
	f2.x = 3;
	f2.y = 3;
	F1.x=0;
	F1.y=7;
	Lemn a2(F1, f2);
	ASSERT_EQ(2.5, a2.getP1().x);
	ASSERT_NEAR(0, a2.Rasst(2), err);
	ASSERT_NEAR(sqrt(2)/(3*sqrt(cos(6))), a2.Rad1(3), err);
	ASSERT_NEAR(0.83333, a2.Rad2(2), err);
	ASSERT_EQ(12.5, a2.area());
	ASSERT_NEAR(6.25*abs(sin(-0.2))/2, a2.Ssect(0.1), err);
	ASSERT_STREQ("(x^2 + y^2)^2 = 2*2.50*(x^2 - y^2)", a2.frm());
}

	int main(int argc, char* argv[])
	{
		::testing::InitGoogleTest();
		return RUN_ALL_TESTS();
	}



