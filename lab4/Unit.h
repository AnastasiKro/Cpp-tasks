#include <string>
#include <stack>
#include <vector>
#include <queue>
#include "ContClass.h"
//#ifndef UNIT_H
//#define UNIT_H
namespace Necromancer{
	class Undead;
	class Unit{
		private:
			std::string name;
			int max_hp;
			int hp;
			int fr;
			int hit;
			int damage;
			int x;
			int y;
			int level;
		public:
			std::string getname()const{ return name; }
			int getmax_hp()const{ return max_hp;}
			int gethp()const{ return hp;}
			int gethit()const {return hit;}
			int getlevel(){ return level; }
			int getdamage()const{ return damage;}
			int getfr() const {return fr;}
			int getx()const { return x;}
			int gety()const { return y; }
			Unit& sethit(int h){ hit = h; return *this; }
			Unit& setdamage(int d){ damage = d; return *this; }
			Unit& setx(int a) {x=a; return *this; };
			Unit& sety(int a){ y =a; return *this; }
			Unit& sethp(int h){ hp = h; return *this; }
			Unit& setlevel(int l){ level = l; return *this; }
			Unit& setname(std::string str){ name =str; return *this;}
			Unit& setmax_hp(int mh){ max_hp = mh; return *this;}
			Unit& setfr(int f){ fr = f; return *this;}
			Unit();
			int hit_enem(Unit* enemy);
			virtual int getcond()const { return 10; }
			virtual void setcond(int c){ c = 0; }
			virtual int getexp()const {return 0; }
			virtual void setexp(int a) {a=0; }
			virtual std::string gettype()const{ return "";}
			virtual Undead* Create(){return nullptr;}
			virtual int getq()const{ return 0; }
			virtual void setq(int q){q=0;}
	};struct coef{
		std::string name;
		int c;
	};
	struct point{
		int x2;
		int y2;
		point(int px, int py){x2 = px; y2 = py;}
	};
	class Undead: public Unit{
		std::string type;
		public:
			std::string gettype()const override{ return type;}
			Undead& settype(std::string t){ type = t; return *this;}
			Undead(Unit* a, std::string str, int k);
			Undead();
	};
}
//#endif UNIT_H
