#include <fstream>
#include <iostream>
#include "lab4.h"
using namespace MyClass;
namespace Necromancer{
	void Game::WriteUndead(){
		std::ofstream of("/home/avtobus/3sem/lab2/3sem/lab4/mygame/Undead");
		for (int i = 0; i<u.size(); i++){
			of << u[i].getname()<<std::endl;
			of << u[i].gettype()<<std::endl;
			of << u[i].getmax_hp()<<std::endl;
			of << u[i].gethp()<<std::endl;
			of <<u[i].getdamage()<<std::endl;
			of<<u[i].getfr()<<std::endl;
		}
		of.close();
	}
	void Game::WriteAlive(){
		std::ofstream of("/home/avtobus/3sem/lab2/3sem/lab4/mygame/Alive");
		Iterator<Alive> It;
		for ( It = e.begin(); It<e.end(); It++){
			if (It.getit()->get_e()->getcond()!=0){
			of << It.getit()->get_e()->getname()<<std::endl;
			of << It.getit()->get_e()->getmax_hp()<<std::endl;
			of << It.getit()->get_e()->gethp()<<std::endl;
			of<< It.getit()->get_e()->getexp()<<std::endl;
			of<<It.getit()->get_e()->getfr()<<std::endl;
			of <<It.getit()->get_e()->getdamage()<<std::endl; }
		}
		of.close();
	}
	void Game::Writeme(){
		std::ofstream of("/home/avtobus/3sem/lab2/3sem/lab4/mygame/Myself");
		of<<me.getexp()<<std::endl;
		of<<me.getlevel()<<std::endl;
		of<<me.getfr()<<std::endl;
		std::vector <tab> t = me.getV();
		for (int i = 0; i<t.size(); i++){
			of<<t[i].name<<std::endl;
			of<<t[i].parent<<std::endl;
			of<<t[i].mana<<std::endl;
			of<<t[i].charact<<std::endl;
		}
		of.close();
	}
	void Game::WriteSummoners(){
		std::ofstream of("/home/avtobus/3sem/lab2/3sem/lab4/mygame/Summoners");
		for (int i = 0; i<SA.size(); i++){
			if (SA[i].getcond()!=0){
			of<<"Alive"<<std::endl;
			of<<SA[i].getname()<<std::endl;
			of<<SA[i].getslaves_type()<<std::endl;
			of<<SA[i].getmax_hp()<<std::endl;
			of<<SA[i].gethp()<<std::endl;
			of<<SA[i].getdamage()<<std::endl;
			of<<SA[i].getfr()<<std::endl;
			}
		}
		for (int i = 0; i<SU.size(); i++){
			of<<SU[i].gettype()<<std::endl;
			of<<SU[i].getname()<<std::endl;
			of<<SU[i].getslaves_type()<<std::endl;
			of<<SU[i].getmax_hp()<<std::endl;
			of<<SU[i].gethp()<<std::endl;
			of<<SU[i].getdamage()<<std::endl;
			of<<SU[i].getfr()<<std::endl;
		}
		of.close();
	}

}
