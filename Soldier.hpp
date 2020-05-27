#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;

class Soldier{
	pair<int,int> location;
	int initial_HP;
	int current_HP;
	int dpa;
	int player_number;
	public:
	Soldier(int i){
		player_number = i;
	}
	virtual ~Soldier(void){
		cout<<"Delete Soldier"<<endl;
	}


};
