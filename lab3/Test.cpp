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
TEST(Domino_operators, exceptions){
	Domino d1;
	ASSERT_NO_THROW(d1++);
	Dice dice(1, 3);
	ASSERT_NO_THROW(d1 -= dice);
	Domino* D;
	ASSERT_NO_THROW(d1[D]);
	ASSERT_NO_THROW(d1.DomSort());
	ASSERT_NO_THROW(d1.pdgr(3));
}

	int main(int argc, char* argv[])
	{
		::testing::InitGoogleTest();
		return RUN_ALL_TESTS();
	}



