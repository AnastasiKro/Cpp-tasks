#include <string>
#include <vector>
namespace Necromancer{
//	template <class T>
	class Enemy{
		private:
			std::string name;
			int max_hp;
			int hp;
			int fr;
			int x;
			int y;
		public:
			std::string getname()const{ return name; }
			int getmax_hp()const{ return max_hp;}
			int gethp()const{ return hp;}
			int getfr() const {return fr;}
			int getx()const { return x;}
			int gety()const { return y; }
			Enemy& setx(int a) {x=a; return *this; };
			Enemy& sety(int a){ y =a; return *this; }
			Enemy& sethp(int h){ hp = h; return *this; }
			Enemy& setname(std::string str){ name =str; return *this;}
			Enemy& setmax_hp(int mh){ max_hp = mh; return *this;}
			Enemy& setfr(int f){ fr = f; return *this;}
	
	};
	class Alive: public Enemy{
		int exp;
		int condition;
		public:
			Alive();
			Alive(std::string name, int m, int h, int f, int ex, int c);
			int getexp()const {return exp;}
			Alive& setexp(int a){ exp = a; return *this; }
			int getcond()const {return condition;}
	};
	class Undead: public Enemy{
		std::string type;
		public:
			Undead(Alive& a, char str);
	};
	struct tab{
		std::string name;
		std::string parent;
		int mana;
		int charact;
	};
	class Myself{
		private:
			int exp;
			int max_hp;
			int max_mana;
			int hp;
			int level;
			int fr;
			int mana;
			tab* T;
			//std::vector <tab> V;
		public:
			Myself();
			int getexp() const{ return exp; }
			int getmax_hp() const {return max_hp;}
			int getmax_mana() const {return max_mana;}
			int gethp() const { return hp;}
			int getlevel()const { return level;}
			int getfr()const { return fr;}
			int getmana()const { return mana; }
			Myself& setmax_hp(){ max_hp=level*2+5; return *this; }
			Myself& setmax_mana(){max_mana = level*5; return *this; }	
			Myself& setexp(int a){exp=a; return *this;}
			Myself& sethp(int a){ hp=a; return *this;}
			Myself& setlevel(){ level+=1; return *this;}
			void draining_mana(Alive& enem);
			void draining_hp(Alive& enem);
			Undead necromancy(Alive& enem);
			void curse(Alive& enem);
	};
		
}
