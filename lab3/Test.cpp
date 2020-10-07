#include "gtest/gtest.h"
#include "prog3.cpp"
#include <cmath>
using namespace Prog3;
//g++ Test.cpp -o TEST -lgtest -lpthread
TEST(DominoConstructor, DefaultConstructor)
{
	Domino a1;
	ASSERT_EQ(1, a1.getN());
	ASSERT_NO_THROW(Domino a1);
	ASSERT_NO_THROW(Domino d(5));
	Domino a2(6);
	ASSERT_EQ(6, a2.getN());
	}
TEST(Domino_functions, results){
	Domino d1;
	ASSERT_NO_THROW(d1.DomSort());
	ASSERT_NO_THROW(d1.pdgr(3));
	Dice d(1, 0);
	d1-=d;
	d1.SetAdd(d);
	ASSERT_EQ(1, d1.getA(d1.getN()-1));
	ASSERT_EQ(0, d1.getB(d1.getN()-1));
	ASSERT_EQ(d1.getN()-1, d1.findDice(1, 0));
}
TEST(Domino_operators, exceptions){
	Domino d1(4);
	ASSERT_NO_THROW(d1++);
	Dice dice(1, 3);
	ASSERT_NO_THROW(d1 -= dice);
	ASSERT_NO_THROW(d1[4]);
	ASSERT_NO_THROW(std::cout<<d1);
	ASSERT_NO_THROW(std::cin>>dice);
}

	int main(int argc, char* argv[])
	{
		::testing::InitGoogleTest();
		return RUN_ALL_TESTS();
	}



