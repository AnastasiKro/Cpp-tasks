#include "gtest/gtest.h"
#include "lab4.h"
#include <ncurses.h>
using namespace Necromancer;
//g++ Test.cpp -o TEST -lgtest -lpthread
TEST(GameConstructors, DefaultConstructors)
{
	Myself me;
	ASSERT_EQ(0, me.getexp());
	ASSERT_EQ(1, me.getlevel());
	ASSERT_EQ(me.getlevel()*2+5, me.getmax_hp());
	ASSERT_EQ(me.getmax_hp(), me.gethp());
	ASSERT_EQ(0, me.getmana());
	ASSERT_EQ(1, me.getfr());
	ASSERT_EQ(me.getlevel()*5+10, me.getmax_mana());
	std::string str = "name";
	int m = 5; int h = 4; int f = 2; int ex = 0; int c = 1;
	Alive enemy(str, m, h, f, ex, c);
	ASSERT_EQ(str, enemy.getname());
	ASSERT_EQ(5, enemy.getmax_hp());
	ASSERT_EQ(4, enemy.gethp());
	ASSERT_EQ(2, enemy.getfr());
	ASSERT_EQ(0, enemy.getexp());
	ASSERT_EQ(1, enemy.getcond());
	std::string type = "skeleton"; 
	int k = 2;
	Undead U(&enemy, type, k);
	ASSERT_EQ(str, U.getname());
	ASSERT_EQ(type, U.gettype());
	ASSERT_EQ(5, U.getmax_hp());
	ASSERT_EQ(5, U.gethp());
	ASSERT_EQ(1, U.getfr());
}
TEST(Game_functions, results){
	Myself me;
	std::string str = "name";
	int m = 5; int h = 4; int f = 2; int ex = 0; int c = 1;
	Alive enemy(str, m, h, f, ex, c);
	enemy.setdamage(2);
	enemy.hit_enem(&me);
	ASSERT_EQ(5, me.gethp());
	ASSERT_EQ(0, enemy.getexp());
	me.hit_enem(&enemy);
	ASSERT_EQ(3, enemy.gethp());
	enemy.sethp(1);
	me.hit_enem(&enemy);
	ASSERT_EQ(0, enemy.gethp());
	ASSERT_EQ(1, me.getexp());
	std::string type = "skeleton"; 
	int k = 2;
	enemy.sethp(3);
	Undead U(&enemy, type, k);
	U.setfr(3);
	ASSERT_EQ(5, U.gethp());
	me.hit_enem(&U);
	ASSERT_EQ(4, U.gethp());
	U.hit_enem(&enemy);
	ASSERT_EQ(1, enemy.gethp());
	Alive en("Ogr", 6, 6, 3, 3, 1);
	en.setdamage(2);
	enemy.hit_enem(&en);
	ASSERT_EQ(4, en.gethp());
	Undead Un(&en, "ghost", 3);
}

TEST(Game_curses, results){
	Myself me;
	Alive en("Ogr", 6, 6, 3, 3, 1);
	en.setdamage(2);
	Curse Cur;
	Cur.spoilage(&en, me);// it must not work, because we do not have mana
	ASSERT_EQ(2, en.getdamage());
	me.setmana(5);
	Cur.spoilage(&en, me);
	ASSERT_EQ(1, en.getdamage());//now it does
	ASSERT_EQ(1, me.getexp());
	Cur.exhastion(&en, me);
	ASSERT_EQ(0, en.getdamage());
	ASSERT_EQ(5, en.gethp());
	ASSERT_EQ(3, me.getmana());
	me.setmana(10);
	en.setdamage(10);
	Cur.rot(&en, me);
	ASSERT_EQ(9, en.getdamage());
	ASSERT_EQ(3, en.gethp());
	ASSERT_EQ(4, me.getexp());
	me.setexp(0);
	Cur.pain(&en, me);
	ASSERT_EQ(7, en.getdamage());
	me.setexp(0);
	Cur.agony(&en, me);
	ASSERT_EQ(3, en.getdamage());
	ASSERT_EQ(3, me.getexp());
	me.setexp(0);
	Cur.desecration(&en, me);
	me.setexp(0);
	ASSERT_EQ(2, en.getcond());
	en.setcond(1);
	me.setmana(5);
	Cur.madness(&en, me);	
	ASSERT_EQ(2, en.getcond());
	ASSERT_EQ(6, en.getdamage());

}
	int main(int argc, char* argv[])
	{
		::testing::InitGoogleTest();
		return RUN_ALL_TESTS();
	}
