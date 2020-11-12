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
			friend class Myself;
			Alive();
			Alive(std::string name, int m, int h, int f, int ex, int c);
			int getexp()const {return exp;}
			Alive& setexp(int a){ exp = a; return *this; }
			int getcond()const {return condition;}
			Alive& setcond(int c){ condition = c; return *this;}
		//	int wound(Myself& me);
	};
	class Undead: public Enemy{
		std::string type;
		public:
			std:: string gettype()const{ return type;}
			Undead& settype(std::string t){ type = t; return *this;}
			Undead(Alive& a, std::string str);
		friend class Myself;
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
			//tab* T;
			std::vector <tab> V;
			std::vector <tab> :: iterator iter;
		public:
			friend class Alive;
			friend class Undead;
			Myself();
			int getexp() const{ return exp; }
			int getmax_hp() const {return max_hp;}
			int getmax_mana() const {return max_mana;}
			int gethp() const { return hp;}
			int getlevel()const { return level;}
			int getfr()const { return fr;}
			int getmana()const { return mana; }
			std::vector <tab> getV()const { return V; }
			Myself& setV(std::vector <tab> T){V = T; return *this;} 
			Myself& setmax_hp(){ max_hp=level*2+5; return *this; }
			Myself& setmax_mana(){max_mana = level*5; return *this; }	
			Myself& setexp(int a){exp=a; return *this;}
			Myself& sethp(int a){ hp=a; return *this;}
			Myself& setlevel(int a){ level = a; return *this;}
			Myself& increase_level();
			Myself& setfr(int f){ fr = f; return *this;}
			void draining_mana(Alive& enem);
			int wounded(Alive& en);
			void draining_hp(Alive& enem);
			std::vector <Undead> necromancy(Alive& enem, char c, std::vector <Undead> u);
			void curse(Alive& enem);
	};
	Myself Readme();
	Alive* Readfile( int* n);
		
}
