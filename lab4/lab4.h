#include "Unit.h"

namespace Necromancer{
	//class cell;
	class Alive: public Unit{
		int exp;
		int condition;
		//stack <cell> St;
		public:
			std::stack <point> St;
			Alive();
			~Alive();
			Alive(std::string name, int m, int h, int f, int ex, int c);
			int getexp()const override{return exp;}
			void setexp(int a)override{ exp = a; }
			int getcond()const override {return condition;}
			void setcond(int c) override{ condition = c;}
			std::stack<point> getstack()const {return St;}
			void setstack(std::stack <point> S){St = S;}
	};
/*	class Undead: public Unit{
		std::string type;
		public:
			std::string gettype()const override{ return type;}
			Undead& settype(std::string t){ type = t; return *this;}
			Undead(Unit* a, std::string str, int k);
			Undead();
	};*/
	class Summoner{
		std::string slaves_type;
		int qs;
		public:
			int getqs()const {return qs;}
			void setqs(int q){ qs = q;}
			std::string getslaves_type(){return slaves_type;};
			void setslaves_type(std::string str){ slaves_type = str; }
			Undead* create_slaves();
	};
	class Summoner_Alive: public Alive, public Summoner{
		public:
			int getq()const override {return getqs();}
			void setq(int q)override{ setqs(q);}
			Summoner_Alive(std::string S, Unit P, int q);
			Undead *Create() override;
	};
	class Summoner_Undead: public Undead, public Summoner{
		public:
			int getq()const override {return getqs();}
			void setq(int q)override { setqs(q);}
			Summoner_Undead(std::string S, Unit P, std::string type, int q);
			Undead* Create() override;
	};
	struct tab{
		std::string name;
		std::string parent;
		int mana;
		int charact;
	};
	class Myself: public Unit{
		private:
			int exp;
			int max_mana;
			int mana;
			std::vector <tab> V;
			std::vector <tab> :: iterator iter;
		public:
			Myself();
			~Myself(){ V.clear(); }
			int getexp() const override{ return exp; }
			int getmax_mana() const {return max_mana;}
			int getmana()const { return mana; }
			tab find_in_table(std::string);
			std::vector <tab> getV()const { return V; }
			Myself& setV(std::vector <tab> T){V = T; return *this;} 
			Myself& setmax_mana(){max_mana = getlevel()*5; return *this; }
			Myself& setmana(int m){ mana = m; return *this;}	
			void setexp(int a) override{exp=a; increase_level();}
			Myself& increase_level();
			int draining(Unit* enem);
	};
	class Curse{
		char c;
		public:
			Curse(){ c=0;}
			int spoilage(Unit* enem, Myself& me);
			int pain(Unit* enem, Myself& me);
			int agony(Unit* enem, Myself& me);
			int exhastion(Unit* enem, Myself& me);
			int rot(Unit* enem, Myself& me);
			int desecration(Unit* enem, Myself& me);
			int madness(Unit* enem, Myself& me);
	};
}
