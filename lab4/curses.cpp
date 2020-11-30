#include "lab4.h"

namespace Necromancer{
	int Curse::spoilage(Unit* enem, Myself& me){
		tab t = me.find_in_table("spoilage");
		if (t.charact == 0 || t.mana > me.getmana())
			return 0;
		enem->setdamage(enem->getdamage()-1);
		if (enem->getdamage()<0)
			enem->setdamage(0);
		me.setmana(me.getmana()-t.mana);
		me.setexp(me.getexp()+1);
		return 0;
	}
	int Curse::pain(Unit* enem, Myself& me){
		tab t = me.find_in_table("pain");
		if (t.charact == 0 || t.mana > me.getmana())
			return 0;
		enem->setdamage(enem->getdamage()-2);
		if (enem->getdamage()<0)
			enem->setdamage(0);
		me.setmana(me.getmana()-t.mana);
		me.setexp(me.getexp()+2);
		return 0;
	}
	int Curse::agony(Unit* enem, Myself& me){
		tab t = me.find_in_table("agony");
		if (t.charact == 0 || t.mana > me.getmana())
			return 0;
		enem->setdamage(enem->getdamage()-4);
		if (enem->getdamage()<0)
			enem->setdamage(0);
		me.setmana(me.getmana()-t.mana);
		me.setexp(me.getexp()+3);
		return 0;
	}
	int Curse::exhastion(Unit* enem, Myself& me){
		tab t = me.find_in_table("exhastion");
		if (t.charact == 0 || t.mana > me.getmana())
			return 0;
		enem->sethp(enem->gethp()-1);
		enem->setdamage(enem->getdamage()-1);
		me.setmana(me.getmana()-t.mana);
		me.setexp(me.getexp()+1);
		return 0;
	}
	int Curse::rot(Unit* enem, Myself& me){
		tab t = me.find_in_table("rot");
		if (t.charact == 0 || t.mana > me.getmana())
			return 0;
		enem->sethp(enem->gethp()-2);
		enem->setdamage(enem->getdamage()-1);
		me.setmana(me.getmana()-t.mana);
		me.setexp(me.getexp()+2);
		return 0;
	}
	int Curse::desecration(Unit* enem, Myself& me){
		tab t = me.find_in_table("desecration");
		if (t.charact == 0 || t.mana > me.getmana())
			return 0;
		enem->setcond(2);
		me.setmana(me.getmana()-t.mana);
		me.setexp(me.getexp()+1);
		return 0;
	}
	int Curse::madness(Unit* enem, Myself& me){
		tab t = me.find_in_table("madness");
		if (t.charact == 0 || t.mana > me.getmana())
			return 0;
		enem->setcond(2);
		enem->setdamage(enem->getdamage()+3);
		me.setmana(me.getmana()-t.mana);
		me.setexp(me.getexp()+3);
		return 0;
	}
}
