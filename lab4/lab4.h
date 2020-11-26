#include <string>
#include <vector>
#include "ContClass.h"

namespace Necromancer{
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
			virtual Unit* Create(){return nullptr;}
	};
	class Alive: public Unit{
		int exp;
		int condition;
		public:
			Alive();
			Alive(std::string name, int m, int h, int f, int ex, int c);
			int getexp()const override{return exp;}
			void setexp(int a)override{ exp = a; }
			int getcond()const override {return condition;}
			void setcond(int c) override{ condition = c;}
	};
	class Undead: public Unit{
		std::string type;
		public:
			std:: string gettype()const override{ return type;}
			Undead& settype(std::string t){ type = t; return *this;}
			Undead(Alive& a, std::string str, int k);
			Undead();
	};
	class Summoner{
		std::string slaves_type;
		public:
			std::string getslaves_type(){return slaves_type;};
			void setslaves_type(std::string str){ slaves_type = str; }
			Undead* create_slaves();
	};
	class Summoner_Alive: public Alive, public Summoner{
		public:
			Summoner_Alive(std::string S, Unit P);
			Unit* Create() override;
	};
	class Summoner_Undead: public Undead, public Summoner{
		public:
			Summoner_Undead(std::string S, Unit P, std::string type);
			Unit* Create() override;
	};
	struct tab{
		std::string name;
		std::string parent;
		int mana;
		int charact;
	};
	struct coef{
		std::string name;
		int c;
	};
	class Myself: public Unit{
		private:
			int exp;
			int max_mana;
			int mana;
			//tab* T;
			std::vector <tab> V;
			std::vector <tab> :: iterator iter;
		public:
			Myself();
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
			std::vector <Undead> necromancy(Alive& enem, char c, std::vector <Undead> u, std::vector <coef> C);
			int curse(Alive& enem);
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
	class cell{
		private:
			int type;
			Unit* Obj;
			int who;
		public:
			int getwho(){ return who;}
			cell& setwho(int w){ who = w; return *this; }
			cell& settype(int t){ type = t; return *this; }
			int gettype(){ return type; }
			cell& setObj(Unit* o){ Obj = o; return *this;}
			Unit* getObj(){ return Obj; }
			cell& del();
	};
	class Game{
		private:
			//const int height=20;
			//const int width=20;
			int level;
			std::vector <Undead> u;
			std::vector <coef> C;
			std::vector <Summoner_Alive> SA;
			std::vector <Summoner_Undead> SU;
			Myself me;
			MyClass::en <Alive> e;
		//	cell Cell[20][20];
			bool gameOver;
		public:
			cell Cell[21][21];
			int x;
			int y;
			int P(int x);
			int D(int d);
			bool getgameOver()const{ return gameOver;}
			void setgameOver(bool g){ gameOver = g;}
			Game& setme(Myself& Me){ me = Me; return *this; }
			Myself& getme() { return me; }
			Myself Readme();
			std::vector <Undead> getu()const { return u;}
			MyClass::en <Alive> gete()const { return e;}
			int getlevel()const{ return level; }
			Game& setlevel(int l) { level = l; return *this;}
			Game& set_u(std::vector <Undead> U){ u = U; return *this; }
			Game& set_e(MyClass::en <Alive> E){ e = E; return *this;}
			std::vector <Undead> ReadUndead();
			std::vector <coef> ReadCoef();
			MyClass::en <Alive> ReadAlive();
			void Paste(Unit* a, int k, int i, int j);
			void ReadSummoner();
			Game();
			void SetUp();
			void MoveMe(int x1, int y1, int x2, int y2);
			void enemy_attack();
			void Summoner_attack();
			void Draining();
			void Attack();
			//cell*[20] getCell()const {return Cell;}
			void goleft();
			void goright();
			void goUp();
			void godown();
			void Die(int k, int l);
			void curse(int a);
	};
		
}
