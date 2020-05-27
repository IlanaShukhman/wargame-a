#include <string>
#include <vector>
#include <stdexcept>
#include "Board.hpp"

using namespace std;
namespace WarGame {
	Soldier*& Board::operator[](pair<int,int> location){
		return board[location.first][location.second];

	}

	Soldier* Board::operator[](pair<int,int> location) const{

		Soldier* s = new Soldier(1);

		return s;
	}

	void Board::move(uint player_number, pair<int,int> source, MoveDIR direction){

		
	}


	bool Board::has_soldiers(uint player_number) const{
		
		return false;
	}
		    







}
