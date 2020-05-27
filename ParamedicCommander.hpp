#pragma once
#include "Soldier.hpp"

class ParamedicCommander:public Soldier{
	public:
	ParamedicCommander(int i) : Soldier(i){
		Soldier* s = new Soldier(i);
	}

};
