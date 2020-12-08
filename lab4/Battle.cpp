#include "Cave.h"
const int height = 20;
const int width = 20;
namespace Necromancer{
	void Game::enemy_attack(){
		for (int i = 0; i<height; i++){
		for (int j = 0; j<width; j++){
			if (Cell[i][j].getwho()>1){
				Unit *q = Cell[i][j].getObj();
				for (int k = P(i); k<D(i); k++){
					for( int l = P(j); l<D(j); l++){
						if (Cell[k][l].getwho()>0&& (k!=i || l!=j)){
							Unit* r = Cell[k][l].getObj();
							int a = rand()%10000;
							if (a!=0)
								break;
							//std::cout<<Cell[i][j].getObj()->getname()<<i<<j<<" "<<k<<l<<std::endl;
							//std::cout<<Cell[k][l].getObj()->getname()<<std::endl;
							int m =q->hit_enem(r);
							if (m ==0){
									Die(k, l);
								}
							}
						}
					}
				}
			}
		}
	}
	void Game::Die(int k, int l){
		if ((Cell[k][l].getwho() == 2)|| (Cell[k][l].getwho()==4)){
			Cell[k][l].getObj()->setcond(0);
			Cell[k][l].setwho(-1);
		}
		if(Cell[k][l].getwho() == 1)
			gameOver = 1;
		if (Cell[k][l].getwho() == 3){
			Unit* U =Cell[k][l].getObj();
			U->setx(-10); U->sety(-10);
			
			Cell[k][l].del();
		}
		if (Cell[k][l].getwho()==5){
			Unit* U =Cell[k][l].getObj();
			//Summoner_Undead* a = SU[SU.size()-1];
			U->setx(-10); U->sety(-10);
			Cell[k][l].del();
		}
		if (Cell[k][l].getwho()==6){
				Cell[k][l].getObj()->setx(-10);
				Cell[k][l].getObj()->sety(-10);
				Cell[k][l].del();
		}
	}
	void Game::Summoner_attack(){
	for (int i = 0; i<height; i++){
		for (int j = 0; j< width; j++){
			if (Cell[i][j].getwho()==4|| Cell[i][j].getwho()==5){
			//	int a = rand()%20000;
				if ( Cell[i][j].getObj()->getq()>0){
					//std::cout<<"create"<<std::endl;
					Undead* U =Cell[i][j].getObj()->Create();
					Un.add(U);
					Cell[i][j].getObj()->setq(Cell[i][j].getObj()->getq()-1);
					Paste(U, 6, Cell[i][j].getObj()->getx(), Cell[i][j].getObj()->gety());
				}
			}
		}
	}
	}
	void Game::Draining(){
		for (int i = P(y); i<D(y); i++){
			for(int j = P(x); j<D(x); j++){
			       if(Cell[i][j].getwho()==-1){
				       Unit* a = Cell[i][j].getObj();
				       int p =me.draining(a);
				       if (p == 0){
					       Cell[i][j].setwho(0);
					       Cell[i][j].setObj(nullptr);
				       }
			       }
			}
		}
	}
	void Game::Attack(){
		for (int i = P(y); i<D(y); i++){
			for (int j = P(x); j<D(x); j++){
				if (Cell[i][j].getwho()>1){
					Unit* a = Cell[i][j].getObj();
					int p =me.hit_enem(a);
					if (p == 0)
						Die(i, j);
			       	}
			}
		}
	}
	int Game::necromancy(char a){
		std::string type;
		switch(a){
			case 's':
				type = "skeleton";
				break;
			case 'g':
				type = "gul";
				break;
			case 'h':
				type = "ghost";
				break;
			case 'z':
				type = "zombie";
				break;
			case 'p':
				type = "phantom";
				break;
		}
		tab t = me.find_in_table(type);
		if (t.charact == 0 || t.mana>me.getmana())
			return 0;
		me.setmana(me.getmana()-t.mana);
		me.setexp(me.getexp()+2);
		for (int i = P(y); i<D(y); i++){
			for (int j=P(x); j<D(x); j++){
				if ((Cell[i][j].getwho() ==2)|| (Cell[i][j].getwho()==4)){
					Unit* enem = Cell[i][j].getObj();
					enem->setcond(0);
					int k = findc(type);
					Undead* U = new Undead(enem, type, k);
					Un.add(U);
					Cell[i][j].setwho(3);
					Cell[i][j].setObj(U);
				}
			}
		}
		return 0;
	}
	void Game::curse(char a){
		Curse Cur;
		for (int i = P(y); i<D(y); i++){
			for (int j = P(x); j<D(x); j++){
				if(Cell[i][j].getwho()==2){
					Unit* enem = Cell[i][j].getObj();
					switch(a){
						case 's':
							Cur.spoilage(enem, me);
							break;
						case 'p':
							Cur.pain(enem, me);
							break;
						case 'a':
							Cur.agony(enem, me);
							break;
						case 'r':
							Cur.rot(enem, me);
							break;
						case 'e':
							Cur.exhastion(enem, me);
							break;
						case 'd':
							Cur.desecration(enem, me);
							break;
						case 'm':
							Cur.madness(enem, me);
							break;
					}
				}
			}
		}
	}
}
