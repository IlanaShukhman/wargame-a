#pragma once
#include "Soldier.hpp"

class Sniper:public Soldier{
	public:
	Sniper(int i) : Soldier(i){
		Soldier* s = new Soldier(i);
	}

};
