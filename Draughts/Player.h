#pragma once
#include "Board.h"

class Player
{
public:
	//Player();
	Player();
	~Player();
	bool checkMove(int i1, int j1, int i2, int j2, Board & game);

	void secondTake( Board & game);


	void setPlayerColour(char m_playerColour) { playerColour = m_playerColour; }
	char getPlayerColour() { return playerColour; }


	void makeMove(int i1, int j1, int i2,int j2, Board &game,bool &moveMade);

	bool checkTake(int i1, int j1, int i2, int j2, Board & game);

	void takePiece(int i1, int j1, int i2, int j2, Board & game);

	void becomeKing(Board & game);

	bool moveKingCheck(int i1, int j1, int i2, int j2, Board & game);

	void moveKing(int i1, int j1, int i2, int j2, Board & game);

	bool takeCheckKing(int i1, int j1, int i2, int j2, Board & game);

	void takePieceKing(int i1, int j1, int i2, int j2, Board & game);

private:
	char playerColour;
};
