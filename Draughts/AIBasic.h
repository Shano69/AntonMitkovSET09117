#pragma once
#include "Board.h"

class AIBasic
{
public:
	//Player();
	AIBasic();
	~AIBasic();
	bool checkMove( Board & game);


	void setAIColour(char m_AIColour) { AIColour = m_AIColour; }
	char getAIolour() { return AIColour; }


	void makeMove( Board &game);

	

private:
	char AIColour;
};
