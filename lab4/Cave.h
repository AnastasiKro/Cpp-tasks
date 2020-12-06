#include "lab4.h"
//#include "Unit.h"
namespace Necromancer{
	class cell{
		private:
			int type;
			Unit* Obj;
			int who;
		public:
			int n;
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
			MyClass::en <Undead> Un;
		//	cell Cell[20][20];
			int gameOver;
		public:
			cell Cell[21][21];
			int x;
			int y;
			int P(int x);
			int D(int d);
			int getgameOver()const{ return gameOver;}
			void setgameOver(int g){ gameOver = g;}
			Game& setme(Myself& Me){ me = Me; return *this; }
			Myself& getme() { return me; }
			void Readme(std::string str);
			std::vector <Undead> getu()const { return u;}
			MyClass::en <Alive> gete()const { return e;}
			MyClass::en <Undead> getUn()const {return Un;}
			void setUn(MyClass::en <Undead> U){Un = U; }
			int getlevel()const{ return level; }
			Game& setlevel(int l) { level = l; return *this;}
			Game& set_u(std::vector <Undead> U){ u = U; return *this; }
			Game& set_e(MyClass::en <Alive> E){ e = E; return *this;}
			void ReadUndead(std::string str);
			void ReadCoef();
			int findc(std::string str);
			void ReadAlive(std::string str);
			void Paste(Unit* a, int k, int i, int j);
			void ReadSummoner(std::string str);
			Game();
		//	~Game();
			void SetUp(int l);
			int MoveMe(int x1, int y1, int x2, int y2);
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
			void curse(char a);
			int necromancy(char c);
			void WriteUndead();
			void WriteAlive();
			void Writeme();
			void WriteSummoners();
			void Writegame();
			void Readmap(std::string name);
			void Readlevel();
			void Alive_agression();
			void Alive_go();
			void clear();
			void Open_The_Door();
			void move_enemies(Unit* a, point p);
			std::stack<point> CNumbers(std::queue <point>& qu);
			void addq(std::stack<point> & st, int x1, int y1, int N);
			void new_level();

	};
}
