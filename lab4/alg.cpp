#include "Cave.h"

using namespace MyClass;
const int height = 20;
const int width = 20;

namespace Necromancer{
	void Game::addq(std::stack<point> &st, int x1, int y1, int N){
		while(N>1){
		if (x1-1>1&&Cell[y1][x1-1].n ==N-1){
			x1--;
		}
		else if (y1-1>1&&Cell[y1-1][x1].n ==N-1){
			y1--;
		}
		else {if (x1+1<width&&Cell[y1][x1+1].n ==N-1){
			x1++;
		}
		else if (y1+1<height&&Cell[y1+1][x1].n ==N-1){
			y1++;
		}}
		//std::cout<<"add"<<x1<<" "<<y1<<std::endl;
		point p(x1, y1);
		st.push(p);
		N--;
		}
	}
	std::stack<point> Game::CNumbers(std::queue<point> &qu){
		std::stack <point> st;
		//std::cout<<"CN"<<std::endl;
		/*point c = qu.front();
		int x1 = c.x2;
		int y1 = c.y2;*/
		while (!qu.empty()){
			point c = qu.front();
		int x1 = c.x2;
		int y1 = c.y2;
		if((x1-1>0)&&(x1-1>x-10)&& (Cell[y1][x1-1].gettype()==0)&&(Cell[y1][x1-1].n==0)){
			Cell[y1][x1-1].n = Cell[y1][x1].n+1;
			point p( x1-1, y1);
			qu.push(p);
		}
		if ((x1+1<width)&& (x1+1<x+10) && (Cell[y1][x1+1].gettype()==0)&&(Cell[y1][x1+1].n ==0)){
			Cell[y1][x1+1].n = Cell[y1][x1].n+1;
			point p(x1+1, y1);
			qu.push(p);
		}
		if ((y1+1<height)&& (y1+1<y+10)&&(Cell[y1+1][x1].gettype()==0)&&(Cell[y1+1][x1].n ==0)){
			Cell[y1+1][x1].n = Cell[y1][x1].n+1;
			point p(x1, y1+1);
			qu.push(p);
		}
		if ((y1-1>0)&& (y1-1>y-10)&& (Cell[y1-1][x1].gettype()==0)&&(Cell[y1-1][x1].n==0)){
			Cell[y1-1][x1].n = Cell[y1][x1].n+1;
			point p(x1, y1-1);
			qu.push(p);
		}
		if (Cell[y][x].n!=0){
			//std::cout<<"here"<<std::endl;
			//int N = n;
			//std::stack <point> st;
			addq(st, x, y, Cell[y][x].n);
			return st;
			
		}
		qu.pop();
		}
		return st;
	}
	void Game::Alive_agression(){
		Iterator<Alive> Iter;
		for (Iter =e.begin(); Iter<e.end(); Iter++){
		       int x1=Iter.item()->getx();
		       int y1=Iter.item()->gety();
		       if (x>x1-10 && x<x1+10 && y>y1-10 && y<y1+10&& Iter.item()->getcond()!=0){
			       //std::cout<<Iter.item()->getname()<<std::endl;
			       Iter.it->get_e()->setcond(3);
			       std::queue <point> qu;
			       point p(x1, y1);
			       qu.push(p);
			       
			       Iter.item()->setstack(CNumbers(qu));
			       clear();
			       //std::
		       }
		}
	}
	void Game::Alive_go(){
		Iterator<Alive> Iter;
		for (Iter =e.begin(); Iter<e.end(); Iter++){
			if (Iter.item()->getcond()==3){
				//std::cout<<Iter.item()->getname()<<std::endl;
				point p =Iter.item()->St.top();
				Iter.item()->St.pop();
				//go(Iter.item(), p);
				//Iter.item()->sety(p.y2);
				move_enemies(Iter.item(), p);
				clear();
				int x1 =Iter.item()->getx();
				int y1=Iter.item()->gety();
				if (x1>x-3 &&x1<x+3 &&y1<y+3 &&y1>y-3)
					Iter.item()->setcond(1);
				
			}
		}
	}
	void Game::move_enemies(Unit* a, point p2){
		int x1 = a->getx(); int y1 = a->gety();
		if (Cell[p2.y2][p2.x2].gettype()==0){
		if (Cell[p2.y2][p2.x2].getwho()==0){
				Cell[p2.y2][p2.x2].setObj(a);
				Cell[p2.y2][p2.x2].setwho(2);
				Cell[y1][x1].setObj(nullptr);
				Cell[y1][x1].setwho(0);
				a->setx(p2.x2);
				a->sety(p2.y2);
		}
		else{
			int k =Cell[p2.y2][p2.x2].getwho();
			Unit* s =Cell[p2.y2][p2.x2].getObj();
			Cell[p2.y2][p2.x2].setObj(a);
			Cell[p2.y2][p2.x2].setwho(2);
			Cell[y1][x1].setObj(s);
			Cell[y1][x1].setwho(k);
			a->setx(p2.x2);
			a->sety(p2.y2);
			s->setx(x1);
			s->sety(y1);
		}
		}
	}

	void Game::clear(){
		for (int i = 0; i<height+1; i++)
			for (int j = 0; j<width+1; j++)
				Cell[i][j].n = 0;
	}

		
}




