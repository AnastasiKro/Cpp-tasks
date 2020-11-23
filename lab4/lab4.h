#include <string>
#include <vector>
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
			virtual void create_slaves(){}
	};
	class Alive: virtual public Unit{
		int exp;
		int condition;
		public:
		//	friend class Myself;
		//	friend class Undead;
			Alive();
			Alive(std::string name, int m, int h, int f, int ex, int c);
			int getexp()const override{return exp;}
			void setexp(int a)override{ exp = a; }
			int getcond()const override {return condition;}
			void setcond(int c) override{ condition = c;}
			//void Die();
	};
	class Undead: virtual public Unit{
		std::string type;
		public:
			std:: string gettype()const override{ return type;}
			Undead& settype(std::string t){ type = t; return *this;}
			Undead(Alive& a, std::string str, int k);
			Undead();
			//void Die();
	};
	class Prizivatel: public Alive, public Undead{
		int t;
		std::string slaves_type;
		public:
			Prizivatel();
			std::string getslaves_type(){return slaves_type;};
			void setslaves_type(std::string str){ slaves_type = str; }
			void create_slaves() override;
	};
	//class Curse{
	class en{
		Alive e;
		en* next;
		//Iterator It;
		public:
			Alive get_e()const { return e;}
			en& set_e(Alive& a){e = a; return *this;}
			en* getnext()const {return next; }
			en& setnext(en* enemy){ next = enemy; return *this;}
			en(Alive enemy);
			en(){ next = nullptr;}
			en& add(Alive enemy);
			en* begin() { return this; }
			en* end(){return nullptr;}
			en& del(int k);
			Alive operator [](int k);
	};
	class Iterator{
		en* it;
		public:
			en* getit()const{ return it;}
			Iterator();
			Iterator & operator =(en* enemy);
			Iterator & operator ++(int a);
			std::string getname()const { return it->get_e().getname(); }
			int getmax_hp()const { return it->get_e().getmax_hp(); }
			int gethp()const{ return it->get_e().gethp();}
			int gethit()const {return it->get_e().gethit();}
			int getdamage()const{ return it->get_e().getdamage();}
			int getfr() const {return it->get_e().getfr();}
			int getx()const { return it->get_e().getx();}
			int gety()const { return it->get_e().gety(); }
			bool operator == (en* enemy);
			bool operator < (en* enemy);
			bool operator > (en* enemy);
			//Alive & operator --(int a);
	};

	/*class Iterator{
		en* it;
		public:
			Iterator();
			Iterator & operator =(en ememy);
			Iterator & operator ++(int a);
			iterator & operator --(int a);
	}*/

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
			void setexp(int a) override{exp=a;}
			Myself& increase_level();
			int draining(Unit* enem);
			std::vector <Undead> necromancy(Alive& enem, char c, std::vector <Undead> u, std::vector <coef> C);
			int curse(Alive& enem);
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
	//Undead Create_slaves(Alive& en, std::vector <Undead> u);
	//Undead create_slaves(Undead& en, std::vector <Undead> u);
	Myself Readme();
	en Readfile( int n, cell Cell[20][20]);
	std::vector <coef> ReadCoef();
	std::vector <Undead> ReadUndead(cell Cell[20][20]);
	void Paste(Unit* a, int k, int i, int j);
	std::vector <Prizivatel> ReadPrizivatel(cell Cell[20][20]);
		
}
