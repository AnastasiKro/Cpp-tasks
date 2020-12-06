#include "Cave.h"
#include <sstream>
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
/*	Game::~Game(){
		u.clear();
		e.clear();
		C.clear();
		SA.clear();
		SU.clear();
		Myself* M = &me;
		delete[] Cell;
		delete M;
	}*/
	void Game::new_level(){
		u.clear();
		e.clear();
		SA.clear();
		SU.clear();
		Un.clear();
		setlevel(getlevel()+1);
		SetUp(getlevel());
		me.setlevel(1);
	}	

	void Game::SetUp(int l){
		std::stringstream ss;
		ss<<l;
		gameOver = 0;
		//Readme();
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
				Cell[i][j].n = 0;
	       		}
		}
		std::string str ="/home/avtobus/3sem/lab2/3sem/lab4/config/l"+ ss.str()+"/map";
		Readmap(str);
		Cell[y][x].settype(0);
		Cell[y][x].setwho(1);
     		Cell[y][x].setObj(&me);		
	}
	int Game::MoveMe(int x1, int y1, int x2, int y2){
		if (Cell[y2][x2].gettype()==-1){
			gameOver = 3;
			return 0;
		}
		if (Cell[y2][x2].gettype()==0){
		Cell[y2][x2].setwho(1);
		Cell[y2][x2].setObj(&me);
		Cell[y1][x1].setwho(0);
		Cell[y1][x1].setObj(nullptr);
		}
		return 0;
	}
			
	void Game::goleft(){
		if (x>1&& Cell[y][x-1].gettype()<1 &&Cell[y][x-1].getwho()==0){
			x--;
			MoveMe(x+1, y, x, y);
		}
	}
	void Game::goright(){
		if(x<width-1&& Cell[y][x+1].gettype()<1&& Cell[y][x+1].getwho()==0){
			x++;
			MoveMe(x-1, y, x, y);
		}
	}
	void Game::godown(){
		if (y<height&& Cell[y+1][x].gettype()<1 && Cell[y+1][x].getwho()==0){
					y++;
					MoveMe(x, y-1, x, y);
		}
	}
	void Game::goUp(){
		if (y>1 && Cell[y-1][x].gettype()<1&&Cell[y-1][x].getwho() ==0){
					y--;
					MoveMe(x, y+1, x, y);
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
void Game::Open_The_Door(){
	if (x+1<width){
		if (Cell[y][x+1].gettype()==2){
			if (me.getlevel()>4){
				Cell[y][x+1].settype(-1);
			}
		}
	}
	if (y+1<height){
		if (Cell[y+1][x].gettype()==2){
			if (me.getlevel()>4){
				Cell[y+1][x].settype(-1);
			}
		}
	}
	if (x-1>0){
		if (Cell[y][x-1].gettype()==2){
			if (me.getlevel()>4){
				Cell[y][x-1].settype(-1);
			}
		}
	}
	if (y-1>0){
		if (Cell[y-1][x].gettype()==2){
			if (me.getlevel()>4){
				Cell[y-1][x].settype(-1);
			}
		}
	}
	}
}

