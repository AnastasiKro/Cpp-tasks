#include "lab4.h"
//#include "ContClass.h"
const int height = 20;
const int width = 20;
namespace Necromancer{
	Game::Game(){
		level = 1;
		//height = 20;
		//width = 20;
		Myself me;
		//Cell = new cell[width][height];
	}
	void Game::SetUp(){
		gameOver = false;
		x = width/2;
		y = 1;
		for (int i = 0; i<height+1; i++){
	       		for (int j = 0; j<width+1; j++){
		       		if ((i==0) ||(j == 0) || (j == width)||(i == width)){
			       		Cell[i][j].settype(1);
			      		Cell[i][j].setwho(0);
			       		Cell[i][j].setObj(nullptr);
		      		 }
		       		else{
		   			Cell[j][i].settype(0);
		   			Cell[j][i].setObj(nullptr);
		   			Cell[j][i].setwho(0); }
	       		}
		}
		Cell[y][x].settype(0);
		Cell[y][x].setwho(1);
     		Cell[y][x].setObj(&me);		
	}
	void Game::MoveMe(int x1, int y1, int x2, int y2){
		Cell[y2][x2].setwho(1);
		Cell[y2][x2].setObj(&me);
		Cell[y1][x1].setwho(0);
		Cell[y1][x1].setObj(nullptr);
	}
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
			gameOver = true;
		if ((Cell[k][l].getwho() == 3) || (Cell[k][l].getwho()==5)){
			Unit* U =Cell[k][l].getObj();
			*U = u[u.size()-1];
			u.pop_back();
			Cell[k][l].del();
		}
	}
	void Game::Summoner_attack(){
	for (int i = 0; i<height; i++){
		for (int j = 0; j< width; j++){
			if (Cell[i][j].getwho()==4){
				int a = rand()%20000;
				if (a == 5){
					Unit* U =Cell[i][j].getObj()->Create();
				//	u.push_back(U);
					Paste(U, 3, Cell[i][j].getObj()->getx(), Cell[i][j].getObj()->gety());
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
	void Game::goleft(){
		if (x>1&& Cell[y][x-1].gettype()==0 &&Cell[y][x-1].getwho()==0){
			x--;
			MoveMe(x+1, y, x, y);
		}
	}
	void Game::goright(){
		if(x<width-1&& Cell[y][x+1].gettype()==0&& Cell[y][x+1].getwho()==0){
			x++;
			MoveMe(x-1, y, x, y);
		}
	}
	void Game::godown(){
		if (y<height&& Cell[y+1][x].gettype()==0 && Cell[y+1][x].getwho()==0){
					y++;
					MoveMe(x, y-1, x, y);
		}
	}
	void Game::goUp(){
		if (y>1 && Cell[y-1][x].gettype()==0&&Cell[y-1][x].getwho() ==0){
					y--;
					MoveMe(x, y+1, x, y);
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
					Undead U(enem, type, k);
					u.push_back(U);
					Cell[i][j].setwho(3);
					Cell[i][j].setObj(&(u[u.size()-1]));
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


int Game::P(int r){
	if (r==0 || r ==1)
		return 0;
	else
		return r-2;
}
int Game::D(int r){
	if (r == 19)
		return r+1;
	if (r == 18)
		return r+2;
	if (r<18)
		return r +3;
}
int Game::findc( std::string type){
		std::vector <coef> :: iterator it;
		int k=0;
		for (it = C.begin(); it<C.end(); it++){
			if (type == it->name)
				k = it->c;
		}
		return k;
	}
}
