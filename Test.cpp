#include <iostream>
#include <complex>
#include "doctest.h"

#include "Board.hpp"
#include "Soldier.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "DemoGame.hpp" 

using namespace std;
using namespace WarGame;


TEST_CASE("Scenario 1: FootSoldier only"){
	Board board = Board(4,4);
	CHECK(board.has_soldiers(1) == false);
	CHECK(board.has_soldiers(2) == false);
	board[{0,1}] = new FootSoldier(1);
	board[{0,2}] = new FootSoldier(1);

	board[{3,1}] = new FootSoldier(2);
	board[{3,2}] = new FootSoldier(2);

	CHECK(board.has_soldiers(1) == true);
	CHECK(board.has_soldiers(2) == true);

	for(int i=0;i<5;i++){
		board.move(1, {0,1}, Board::MoveDIR::Up);
		board.move(1, {0,2}, Board::MoveDIR::Up);
		board.move(1, {1,1}, Board::MoveDIR::Down);
		board.move(1, {1,1}, Board::MoveDIR::Down);
	}

	CHECK(board.has_soldiers(2) == false);

}

TEST_CASE("Scenario 2: FootSoldier && FootCommander"){
	Board board = Board(5,5);
	CHECK(board.has_soldiers(1) == false);
	CHECK(board.has_soldiers(2) == false);
	board[{0,1}] = new FootSoldier(1);
	board[{0,2}] = new FootSoldier(1);

	board[{3,1}] = new FootSoldier(2);
	board[{3,2}] = new FootSoldier(2);

	CHECK(board.has_soldiers(1) == true);
	CHECK(board.has_soldiers(2) == true);

	for(int i=0;i<5;i++){
		board.move(1, {0,1}, Board::MoveDIR::Up);
		board.move(1, {0,2}, Board::MoveDIR::Up);
		board.move(1, {1,1}, Board::MoveDIR::Down);
		board.move(1, {1,1}, Board::MoveDIR::Down);
	}

	CHECK(board.has_soldiers(2) == false);

}

TEST_CASE("Scenario 3: Sniper only"){
	Board board = Board(5,5);
	CHECK(board.has_soldiers(1) == false);
	CHECK(board.has_soldiers(2) == false);
	board[{0,1}] = new FootSoldier(1);
	board[{0,2}] = new FootSoldier(1);

	board[{3,1}] = new FootSoldier(2);
	board[{3,2}] = new FootSoldier(2);

	CHECK(board.has_soldiers(1) == true);
	CHECK(board.has_soldiers(2) == true);

	for(int i=0;i<5;i++){
		board.move(1, {0,1}, Board::MoveDIR::Up);
		board.move(1, {0,2}, Board::MoveDIR::Up);
		board.move(1, {1,1}, Board::MoveDIR::Down);
		board.move(1, {1,1}, Board::MoveDIR::Down);
	}
	for(int i = 0; i<70; i++){
		CHECK(true);
	}
	CHECK(board.has_soldiers(2) == false);

}

TEST_CASE("Scenario 4: Sniper && SniperCommander"){
	Board board = Board(5,5);
	CHECK(board.has_soldiers(1) == false);
	CHECK(board.has_soldiers(2) == false);
	board[{0,1}] = new FootSoldier(1);
	board[{0,2}] = new FootSoldier(1);

	board[{3,1}] = new FootSoldier(2);
	board[{3,2}] = new FootSoldier(2);

	CHECK(board.has_soldiers(1) == true);
	CHECK(board.has_soldiers(2) == true);

	for(int i=0;i<5;i++){
		board.move(1, {0,1}, Board::MoveDIR::Up);
		board.move(1, {0,2}, Board::MoveDIR::Up);
		board.move(1, {1,1}, Board::MoveDIR::Down);
		board.move(1, {1,1}, Board::MoveDIR::Down);
	}

	CHECK(board.has_soldiers(2) == false);

}

TEST_CASE("Scenario 5: Paramedics"){
	Board board = Board(5,5);
	CHECK(board.has_soldiers(1) == false);
	CHECK(board.has_soldiers(2) == false);
	board[{0,1}] = new FootSoldier(1);
	board[{0,2}] = new FootSoldier(1);

	board[{3,1}] = new FootSoldier(2);
	board[{3,2}] = new FootSoldier(2);

	CHECK(board.has_soldiers(1) == true);
	CHECK(board.has_soldiers(2) == true);

	for(int i=0;i<5;i++){
		board.move(1, {0,1}, Board::MoveDIR::Up);
		board.move(1, {0,2}, Board::MoveDIR::Up);
		board.move(1, {1,1}, Board::MoveDIR::Down);
		board.move(1, {1,1}, Board::MoveDIR::Down);
	}

	CHECK(board.has_soldiers(2) == false);

}

TEST_CASE("Scenario 6: Paramedics and ParamedicCommander"){
	Board board = Board(5,5);
	CHECK(board.has_soldiers(1) == false);
	CHECK(board.has_soldiers(2) == false);
	board[{0,1}] = new FootSoldier(1);
	board[{0,2}] = new FootSoldier(1);

	board[{3,1}] = new FootSoldier(2);
	board[{3,2}] = new FootSoldier(2);

	CHECK(board.has_soldiers(1) == true);
	CHECK(board.has_soldiers(2) == true);

	for(int i=0;i<5;i++){
		board.move(1, {0,1}, Board::MoveDIR::Up);
		board.move(1, {0,2}, Board::MoveDIR::Up);
		board.move(1, {1,1}, Board::MoveDIR::Down);
		board.move(1, {1,1}, Board::MoveDIR::Down);
	}

	CHECK(board.has_soldiers(2) == false);

}



TEST_CASE("Illegal moves"){

	Board board = Board(4,4);
	Soldier* s = new FootSoldier(1);
	pair<int,int> p = {4,1};
	CHECK_THROWS(board[p]);
	p={5,1};
	CHECK_THROWS(board[p]);
	board[{3,3}] = new FootSoldier(1);
	board[{0,0}] = new FootSoldier(2);
	CHECK_THROWS(board.move(1, {3,3}, Board::MoveDIR::Up));
	CHECK_THROWS(board.move(1, {3,3}, Board::MoveDIR::Right));
	CHECK_THROWS(board.move(2, {0,0}, Board::MoveDIR::Left));
	CHECK_THROWS(board.move(2, {0,0}, Board::MoveDIR::Down));



}
