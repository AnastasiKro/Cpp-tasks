#include "gtest/gtest.h"
#include "lab3.h"
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
	Dice* dices = new Dice[5]; 
	Dice d1(1, 0);
	dices[0] = d1;
	Dice d2(2, 3);
	dices[1] = d2;
	Dice d3(4, 0);
	dices[2] = d3;
	Dice d4( 6, 6);
	dices[3] = d4;
	Dice d5(3, 1);
	dices[4]=d5;
	Domino d0( 5, dices);
	ASSERT_NO_THROW(d0.DomSort());
	ASSERT_EQ(4, d0.getA(1));
	ASSERT_EQ(0, d0.getB(1));
	ASSERT_EQ(3, d0.getA(2));
	ASSERT_EQ(1, d0.getB(2));	
	ASSERT_NO_THROW(d0.pdgr(3));
	Domino Do = d0.pdgr(3);
	ASSERT_EQ(2, Do.getN());
	ASSERT_EQ(3, Do.getA(0));
	ASSERT_EQ(1, Do.getB(0));
	ASSERT_EQ(2, Do.getA(1));
	ASSERT_EQ(3, Do.getB(1));
	Dice d(5, 5);
	ASSERT_EQ(4, d0.findDice(6,6));
	d0.SetAdd(d);
	ASSERT_EQ(5, d0.getA(d0.getN()-1));
	ASSERT_EQ(5, d0.getB(d0.getN()-1));
	Dice* dices2 = new Dice[2];
	//dices2[0] = Dice a1(3, 4);
	//dices2[1] = Dice
	//ASSERT_EQ(d1.getN()-1, d1.findDice(1, 0));
}
TEST(Domino_operators, exceptions){
	Domino d1(4);
	Dice* dices = new Dice[2];
	Dice a1(3, 4);
	dices[0] = a1;
	Dice a2(5, 1);
	dices[1] =a2;
	d1.SetDD(2, dices);
	ASSERT_NO_THROW(d1++);
	ASSERT_EQ(3, d1.getN());
	d1 -=a2;
	ASSERT_EQ(2, d1.getN());
	Dice dice = d1[0];
	ASSERT_EQ(3, dice.get1());
	ASSERT_EQ(4, dice.get2());
	ASSERT_NO_THROW(std::cout<<d1);
	ASSERT_NO_THROW(std::cin>>dice);
}

	int main(int argc, char* argv[])
	{
		::testing::InitGoogleTest();
		return RUN_ALL_TESTS();
	}



