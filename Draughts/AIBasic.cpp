#include "AIBasic.h"
#include <random>

AIBasic::AIBasic()
{

}

AIBasic::~AIBasic()
{
}

bool AIBasic::checkMove( Board & game)
{
	int sumRed = 0;
	int sumBlack = 0;
	char temp[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			temp[i][j] = game.getBoard()[i][j];
		}
	}



	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//RED AI
			if (AIColour == 'r')
			{
				//movement for pieces
				if (AIColour == temp[i][j])
				{
					//normal AI piece move
					if (temp[i - 1][j - 1] == 'e' || temp[i - 1][j + 1] == 'e')
					{
						sumRed += 1;
					}
					//take for AI
					else if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b') || (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'))
					{
						sumRed += 1;
					}
					//Taking enemy king with king forward
					else if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'B') || (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'B'))
					{
						sumRed += 1;
					}

				}

				//movement for kings
				else	if (temp[i][j] == 'R')
				{
					//normal AI king move forward
					if (temp[i - 1][j - 1] == 'e' || temp[i - 1][j + 1] == 'e')
					{
						sumRed += 1;
					}
					//backward
					if (temp[i + 1][j - 1] == 'e' || temp[i + 1][j + 1] == 'e')
					{
						sumRed += 1;
					}
					//take for AI king foward
					else if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b') || (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'))
					{
						sumRed += 1;
					}
					//backward
					else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b') || (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'))
					{
						sumRed += 1;
					}
					//Taking enemy king with king forward with king
					else if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'B') || (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'B'))
					{
						sumRed += 1;
					}
					//backward
					else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'B') || (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'B'))
					{
						sumRed += 1;
					}


				}

			}

			//BLACK AI
			else if (AIColour == 'b')
			{
				if (AIColour == temp[i][j])
				{

					//normal AI piece move
					if (temp[i + 1][j - 1] == 'e' || temp[i + 1][j + 1] == 'e')
					{

						sumBlack += 1;
					}
					//take for AI
					else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'r') || (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'r'))
					{

						sumBlack += 1;
					}
					//Taking enemy king with king forward
					else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'R') || (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'R'))
					{

						sumBlack += 1;
					}

				}

				//movement for kings
				else if (temp[i][j] == 'B')
				{
					//normal AI king move forward
					if (temp[i - 1][j - 1] == 'e' || temp[i - 1][j + 1] == 'e')
					{

						sumBlack += 1;
					}
					//backward
					if (temp[i + 1][j - 1] == 'e' || temp[i + 1][j + 1] == 'e')
					{

						sumBlack += 1;
					}
					//take for AI king foward
					else if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'r') || (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'r'))
					{

						sumBlack += 1;
					}
					//backward
					else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'r') || (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'r'))
					{

						sumBlack += 1;
					}
					//Taking enemy king with king forward with king
					else if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'R') || (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'R'))
					{

						sumBlack += 1;
					}
					//backward
					else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'R') || (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'R'))
					{

						sumBlack += 1;
					}


				}

			}


		}
	}

	if (AIColour == 'b'&& sumBlack < 1)
	{
		return false;
	}
	else if (AIColour == 'r' && sumRed < 1)
	{
		return false;
	}
	else
	{
		return true;
	}

	
}

void AIBasic::makeMove(Board & game)
{
	bool AIMoveMade = false;
	char temp[8][8];
	for (int i1 = 0; i1 < 8; i1++)
	{
		for (int j1 = 0; j1 < 8; j1++)
		{
			temp[i1][j1] = game.getBoard()[i1][j1];
		}
	}

	while (!AIMoveMade)
	{
		std::random_device rd;
		std::mt19937 engine(rd());
		std::uniform_int_distribution<size_t> dist(0, 7);
		int i = dist(engine);
		std::random_device rd2;
		std::mt19937 engine2(rd2());
		std::uniform_int_distribution<size_t> dist2(0, 7);
		int j = dist2(engine2);


		


		//RED AI
		if (AIColour == 'r')
		{
			//movement for pieces
			if (AIColour == temp[i][j])
			{
				//take for AI
				if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i>1 && j>1))
				{
					temp[i - 2][j - 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i - 1][j - 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
					i = i - 2;
					j = j - 2;
					while ((temp[i - 2][j - 2] == 'e' && (temp[i - 1][j - 1] == 'b' || temp[i - 1][j - 1] == 'B') && i>1 && j>1))
					{
						if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1))
						{
							temp[i - 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j - 2;
						}
						else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i>1 && j<6)
						{
							temp[i - 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j + 2;
						}
					}
				}
				else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i>1 && j<6)
				{
					temp[i - 2][j + 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i - 1][j + 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
					i = i - 2;
					j = j + 2;
					while ((temp[i - 2][j - 2] == 'e' && (temp[i - 1][j - 1] == 'b' || temp[i - 1][j - 1] == 'B') && i>1 && j>1))
					{
						if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1))
						{
							temp[i - 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j - 2;
						}
						else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i>1 && j<6)
						{
							temp[i - 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j + 2;
						}
					}
				}
				//Taking enemy king with piece forward
				else if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'B'&&i>1 && j>1))
				{
					temp[i - 2][j - 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i - 1][j - 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
					i = i - 2;
					j = j - 2;
					while ((temp[i - 2][j - 2] == 'e' && (temp[i - 1][j - 1] == 'b' || temp[i - 1][j - 1] == 'B') && i>1 && j>1))
					{
						if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1))
						{
							temp[i - 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j - 2;
						}
						else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i>1 && j<6)
						{
							temp[i - 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j + 2;
						}
					}
				}
				else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'B'&&i>1 && j<6)
				{
					temp[i - 2][j + 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i - 1][j + 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
					i = i - 2;
					j = j + 2;
					while (((temp[i - 2][j - 2] == 'e' && (temp[i - 1][j - 1] == 'b') || (temp[i - 1][j - 1] == 'B') && i>1 && j>1)))
					{
						if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1))
						{
							temp[i - 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j - 2;
						}
						else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i>1 && j<6)
						{
							temp[i - 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j + 2;
						}
					}
				}

				//normal AI piece move
				else if (temp[i - 1][j - 1] == 'e'&&i>0 && j>0)
				{
					temp[i - 1][j - 1] = temp[i][j];
					temp[i][j] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;

				}
				else if (temp[i - 1][j + 1] == 'e'&&i>0 && j<7)
				{
					temp[i - 1][j + 1] = temp[i][j];
					temp[i][j] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}


				else {}
			}

			//movement for kings
			if (temp[i][j] == 'R')
			{

				//take for AI king foward
				if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i>1 && j>1))
				{
					temp[i - 2][j - 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i - 1][j - 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
					i = i - 2;
					j = j - 2;
					while ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1) || (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i > 1 && j < 6) || (temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i < 6 && j>1) || (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i < 6 && j < 6))
					{
						if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1))
						{
							temp[i - 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j - 2;
						}

						else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i>1 && j<6)
						{
							temp[i - 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j + 2;
						}

						else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i<6 && j>1))
						{
							temp[i + 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i + 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i + 2;
							j = j - 2;
						}

						else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i<6 && j<6)
						{
							temp[i + 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i + 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i + 2;
							j = j + 2;
						}
					}
				}
				else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i>1 && j<6)
				{
					temp[i - 2][j + 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i - 1][j + 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
					i = i - 2;
					j = j + 2;
					while ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1) || (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i > 1 && j < 6) || (temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i < 6 && j>1) || (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i < 6 && j < 6))
					{
						if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1))
						{
							temp[i - 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j - 2;
						}

						else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i>1 && j<6)
						{
							temp[i - 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j + 2;
						}

						else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i<6 && j>1))
						{
							temp[i + 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i + 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i + 2;
							j = j - 2;
						}

						else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i<6 && j<6)
						{
							temp[i + 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i + 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i + 2;
							j = j + 2;
						}
					}

				}
				//backward
				else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i<6 && j>1))
				{
					temp[i + 2][j - 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i + 1][j - 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
					i = i + 2;
					j = j - 2;
					while ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1) || (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i > 1 && j < 6) || (temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i < 6 && j>1) || (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i < 6 && j < 6))
					{
						if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1))
						{
							temp[i - 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j - 2;
						}

						else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i>1 && j<6)
						{
							temp[i - 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j + 2;
						}

						else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i<6 && j>1))
						{
							temp[i + 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i + 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i + 2;
							j = j - 2;
						}

						else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i<6 && j<6)
						{
							temp[i + 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i + 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i + 2;
							j = j + 2;
						}
					}

				}
				else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i<6 && j<6)
				{
					temp[i + 2][j + 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i + 1][j + 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
					i = i + 2;
					j = j + 2;
					while ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1) || (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i > 1 && j < 6) || (temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i < 6 && j>1) || (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i < 6 && j < 6))
					{
						if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1))
						{
							temp[i - 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j - 2;
						}

						else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i>1 && j<6)
						{
							temp[i - 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j + 2;
						}

						else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i<6 && j>1))
						{
							temp[i + 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i + 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i + 2;
							j = j - 2;
						}

						else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i<6 && j<6)
						{
							temp[i + 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i + 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i + 2;
							j = j + 2;
						}
					}

				}
				//Taking enemy king with king forward with king
				else if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'B'&&i>1 && j>1))
				{
					temp[i - 2][j - 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i - 1][j - 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
					while ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1) || (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i > 1 && j < 6) || (temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i < 6 && j>1) || (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i < 6 && j < 6))
					{
						if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1))
						{
							temp[i - 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j - 2;
						}

						else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i>1 && j<6)
						{
							temp[i - 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j + 2;
						}

						else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i<6 && j>1))
						{
							temp[i + 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i + 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i + 2;
							j = j - 2;
						}

						else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i<6 && j<6)
						{
							temp[i + 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i + 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i + 2;
							j = j + 2;
						}
					}

				}
				else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'B'&&i>1 && j<6)
				{
					temp[i - 2][j + 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i - 1][j + 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
					while ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1) || (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i > 1 && j < 6) || (temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i < 6 && j>1) || (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i < 6 && j < 6))
					{
						if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1))
						{
							temp[i - 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j - 2;
						}

						else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i>1 && j<6)
						{
							temp[i - 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j + 2;
						}

						else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i<6 && j>1))
						{
							temp[i + 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i + 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i + 2;
							j = j - 2;
						}

						else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i<6 && j<6)
						{
							temp[i + 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i + 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i + 2;
							j = j + 2;
						}
					}

				}
				//backward
				else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'B'&&i<6 && j>1))
				{
					temp[i + 2][j - 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i + 1][j - 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
					while ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1) || (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i > 1 && j < 6) || (temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i < 6 && j>1) || (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i < 6 && j < 6))
					{
						if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1))
						{
							temp[i - 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j - 2;
						}

						else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i>1 && j<6)
						{
							temp[i - 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j + 2;
						}

						else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i<6 && j>1))
						{
							temp[i + 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i + 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i + 2;
							j = j - 2;
						}

						else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i<6 && j<6)
						{
							temp[i + 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i + 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i + 2;
							j = j + 2;
						}
					}

				}
				else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'B'&&i<6 && j<6)
				{
					temp[i + 2][j + 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i + 1][j + 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
					while ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1) || (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i > 1 && j < 6) || (temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i < 6 && j>1) || (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i < 6 && j < 6))
					{
						if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1))
						{
							temp[i - 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j - 2;
						}

						else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i>1 && j<6)
						{
							temp[i - 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i - 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i - 2;
							j = j + 2;
						}

						else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i<6 && j>1))
						{
							temp[i + 2][j - 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i + 1][j - 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i + 2;
							j = j - 2;
						}

						else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i<6 && j<6)
						{
							temp[i + 2][j + 2] = temp[i][j];
							temp[i][j] = 'e';
							temp[i + 1][j + 1] = 'e';
							game.setBoard(temp);
							AIMoveMade = true;
							i = i + 2;
							j = j + 2;
						}
					}

				}
				//normal AI king move forward
				else	if (temp[i - 1][j - 1] == 'e'&&i>0 && j>0)
				{
					temp[i - 1][j - 1] = temp[i][j];
					temp[i][j] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}
				else if (temp[i - 1][j + 1] == 'e'&&i>0 && j<7)
				{
					temp[i - 1][j + 1] = temp[i][j];
					temp[i][j] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}
				//backward
				if (temp[i + 1][j - 1] == 'e'&&i<7 && j>0)
				{
					temp[i + 1][j - 1] = temp[i][j];
					temp[i][j] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}
				else if (temp[i + 1][j + 1] == 'e'&&i<7 && j<7)
				{
					temp[i + 1][j + 1] = temp[i][j];
					temp[i][j] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}

				else {}

			}

		}

		//BLACK AI
		else if (AIColour == 'b')
		{
			if (AIColour == temp[i][j])
			{
				//take for AI
				if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'r') && j>1 && i<6)
				{
					temp[i + 2][j - 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i + 1][j - 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}
				else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'r'&&j<6 && i<6)
				{
					temp[i + 2][j + 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i + 1][j + 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}

				//Taking enemy king with piece forward
				else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'R'&&i<6 && j>1))
				{
					temp[i + 2][j - 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i + 1][j - 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}
				else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'R'&&i<6 && j<6)
				{
					temp[i + 2][j + 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i + 1][j + 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}
				//normal AI piece move
				else if (temp[i + 1][j - 1] == 'e'&&j>0 && i<7)
				{
					temp[i + 1][j - 1] = temp[i][j];
					temp[i][j] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;

				}
				else if (temp[i + 1][j + 1] == 'e'&&j<7 && i<7)
				{
					temp[i + 1][j + 1] = temp[i][j];
					temp[i][j] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}





			}

			//movement for kings
			if (temp[i][j] == 'B')
			{

				//take for AI king foward
				if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'r'&&i>1 && j>1))
				{
					temp[i - 2][j - 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i - 1][j - 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}
				else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'r'&&i>1 && j<6)
				{
					temp[i - 2][j + 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i - 1][j + 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}
				//backward
				else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'r'&&i<6 && j>1))
				{
					temp[i + 2][j - 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i + 1][j - 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}
				else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'r'&&i<6 && j<6)
				{
					temp[i + 2][j + 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i + 1][j + 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}
				//Taking enemy king with king forward with king
				else if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'R'&&i>1 && j>1))
				{
					temp[i - 2][j - 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i - 1][j - 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}
				else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'R'&&i>1 && j<6)
				{
					temp[i - 2][j + 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i - 1][j + 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}
				//backward
				else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'R'&&i<6 && j>1))
				{
					temp[i + 2][j - 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i + 1][j - 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}
				else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'R'&&i<6 && j<6)
				{
					temp[i + 2][j + 2] = temp[i][j];
					temp[i][j] = 'e';
					temp[i + 1][j + 1] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}


				//normal AI king move forward
				else if (temp[i - 1][j - 1] == 'e'&&i>0 && j>0)
				{
					temp[i - 1][j - 1] = temp[i][j];
					temp[i][j] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}
				else if (temp[i - 1][j + 1] == 'e'&&i>0 && j<7)
				{
					temp[i - 1][j + 1] = temp[i][j];
					temp[i][j] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}
				//backward
				else	if (temp[i + 1][j - 1] == 'e'&&i<7 && j>0)
				{
					temp[i + 1][j - 1] = temp[i][j];
					temp[i][j] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}
				else if (temp[i + 1][j + 1] == 'e'&&i<7 && j<7)
				{
					temp[i + 1][j + 1] = temp[i][j];
					temp[i][j] = 'e';
					game.setBoard(temp);
					AIMoveMade = true;
				}


			}

		}
			

	}

}



//bool AIBasic::checkTake( Board & game)
//{
//	return false;
//}
//
//void AIBasic::takePiece(Board & game)
//{
//}
//
//void AIBasic::becomeKing(Board & game)
//{
//}
//
//bool AIBasic::moveKingCheck( Board & game)
//{
//	return false;
//}
//

//
//bool AIBasic::takeCheckKing( Board & game)
//{
//	return false;
//}
//
//void AIBasic::takePieceKing( Board & game)
//{
//}
