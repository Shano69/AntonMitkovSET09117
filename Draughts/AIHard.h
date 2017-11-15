#pragma once
#include "Board.h"
#include <deque>
#include <array>
#include <algorithm>
#include <functional>


struct Move
{
	int i1;
	int j1;
	int i2;
	int j2;

};

class AIHard
{
public:
	AIHard();
	~AIHard();

	std::deque<Move> getPossibleMoves(Board game, char colour);
	void makeMove(Board &game, Move move);
	int evaluateBoard(Board game, char colour);
	Move minmax(Board game, int flag);
	int MIN(Board &game, int flag, Move move);
	int MAX(Board &game, int flag, Move move);
	void setColour(char Colour) { colour = Colour; }
	char getColour() { return colour; }


private:
	char colour;

};