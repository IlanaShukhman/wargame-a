#pragma once
#include "Soldier.hpp"

class Paramedic:public Soldier{
	public:
	Paramedic(int i) : Soldier(i){
		Soldier* s = new Soldier(i);
	}

};
