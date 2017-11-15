#include "AIHard.h"



AIHard::AIHard()
{
}

AIHard::~AIHard()
{
}

std::deque<Move> AIHard::getPossibleMoves(Board game, char colour)
{
	std::deque<Move> moves;
	
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
			if (colour == 'r')
			{
				//movement for pieces
				if (colour == temp[i][j])
				{
					//normal AI piece move
					if (temp[i - 1][j - 1] == 'e' &&i>0&&j>0)
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i - 1;
						a.j2 = j - 1;
						moves.push_back(a);
					}
					else if ( temp[i - 1][j + 1] == 'e'&&i>0&&j<7)
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i - 1;
						a.j2 = j + 1;
						moves.push_back(a);
					}
					//take for AI
					else if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b' &&i>1 && j>1) )
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i - 2;
						a.j2 = j - 2;
						moves.push_back(a);
					}
					else if ((temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b' &&i>1 && j<6))
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i - 2;
						a.j2 = j + 2;
						moves.push_back(a);
					}
					//Taking enemy king with king forward
					else if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'B' &&i>1 && j>1) )
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i - 2;
						a.j2 = j - 2;
						moves.push_back(a);
					}
					else if ((temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'B'  &&i>1 && j<6))
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i - 2;
						a.j2 = j + 2;
						moves.push_back(a);
					}

				}

				//movement for kings
				else if (temp[i][j] == 'R')
				{
					//normal AI king move forward
					if (temp[i - 1][j - 1] == 'e'&&i>0 && j>0)
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i - 1;
						a.j2 = j - 1;
						moves.push_back(a);
					}
					if ( temp[i - 1][j + 1] == 'e'&&i>0 && j<7)
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i - 1;
						a.j2 = j + 1;
						moves.push_back(a);
					}
					
					//backward
					if (temp[i + 1][j - 1] == 'e'&&i<7 && j>0)
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i + 1;
						a.j2 = j - 1;
						moves.push_back(a);
					}
					if ( temp[i + 1][j + 1] == 'e' &&i<7 && j<7)
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i + 1;
						a.j2 = j + 1;
						moves.push_back(a);
					}
					//take for AI king foward
					else if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b' &&i>1 && j>1))
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i - 2;
						a.j2 = j - 2;
						moves.push_back(a);
					}
					else if ( temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b' &&i>1 && j<6)
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i - 2;
						a.j2 = j + 2;
						moves.push_back(a);
					}
					else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i<6 && j>1) )
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i + 2;
						a.j2 = j  - 2;
						moves.push_back(a);
					}
					//backward
					else if ((temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i<6 && j<6))
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i + 2;
						a.j2 = j + 2;
						moves.push_back(a);
					}
					//Taking enemy king with king forward with king
					else if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'B'&&i>1 && j>1))
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i - 2;
						a.j2 = j - 2;
						moves.push_back(a);
					}
					else if ( (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'B'&&i>1 && j<6))
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i - 2;
						a.j2 = j + 2;
						moves.push_back(a);
					}
					//backward
					else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'B'&&i<6 && j>1) )
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i + 2;
						a.j2 = j - 2;
						moves.push_back(a);
					}
					else if ( (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'B'&&i<6 && j<6))
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i + 2;
						a.j2 = j + 2;
						moves.push_back(a);
					}


				}

			}

			//BLACK AI
			else if (colour == 'b')
			{
				if (colour == temp[i][j])
				{

					//normal AI piece move
					if (temp[i + 1][j - 1] == 'e' &&i<7&&j>0)
					{

						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i +1;
						a.j2 = j -1;
						moves.push_back(a);
					}
					if (temp[i + 1][j + 1] == 'e'&&i<7 && j<7)
					{

						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i + 1;
						a.j2 = j + 1;
						moves.push_back(a);
					}
					//take for AI
					else if ( (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'r'&&i<6 && j<6))
					{

						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i + 2;
						a.j2 = j + 2;
						moves.push_back(a);
					}
					else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'r'&&i<6 && j>1))
					{

						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i + 2;
						a.j2 = j - 2;
						moves.push_back(a);
					}
					//Taking enemy king with king forward
					else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'R' &&i<6 && j>1))
					{

						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i + 2;
						a.j2 = j - 2;
						moves.push_back(a);
					}
					else if ( (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'R'&&i<6 && j<6))
					{

						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i + 2;
						a.j2 = j + 2;
						moves.push_back(a);
					}

				}

				//movement for kings
				else if (temp[i][j] == 'B')
				{
					//normal AI king move forward
					if (temp[i - 1][j - 1] == 'e'&&i>0&&j>0)
					{

						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i - 1;
						a.j2 = j  - 1;
						moves.push_back(a);
					}
					if ( temp[i - 1][j + 1] == 'e'&&i>0 && j<7)
					{

						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i - 1;
						a.j2 = j + 1;
						moves.push_back(a);
					}
					//backward
					if (temp[i + 1][j - 1] == 'e'&&i<7&&j>0)
					{


						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i + 1;
						a.j2 = j - 1;
						moves.push_back(a);
					}
					if ( temp[i + 1][j + 1] == 'e'&&i<7 && j<7)
					{

						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i + 1;
						a.j2 = j + 1;
						moves.push_back(a);
					}
					//take for AI king foward
					else if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'r' &&i>1&&j>1) )
					{

						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i - 2;
						a.j2 = j  - 2;
						moves.push_back(a);
					}
					else if ((temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'r'&&i>1 && j<6))
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i - 2;
						a.j2 = j + 2;
						moves.push_back(a);
					}
					//backward
					else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'r'&&i<6 && j>1) )
					{

						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i + 2;
						a.j2 = j - 2;
						moves.push_back(a);
					}
					else if ( (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'r'&&i<6 && j<6))
					{

						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i + 2;
						a.j2 = j + 2;
						moves.push_back(a);
					}
					//Taking enemy king with king forward with king
					else if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'R' &&i>1 && j>1) )
					{
						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i - 2;
						a.j2 = j - 2;
						moves.push_back(a);
					}
					else if ( (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'R'&&i>1 && j<6))
					{

						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i - 2;
						a.j2 = j + 2;
						moves.push_back(a);
					}
					//backward
					else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'R'&&i<6 && j>1))
					{

						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i + 2;
						a.j2 = j - 2;
						moves.push_back(a);
					}
					else if ( (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'R'&&i<6 && j<6))
					{

						Move a;
						a.i1 = i;
						a.j1 = j;
						a.i2 = i + 2;
						a.j2 = j + 2;
						moves.push_back(a);
					}


				}

			}


		}
	}

	return moves;

}

void AIHard::makeMove(Board &game, Move move)
{
	char temp[8][8];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			temp[i][j] = game.getBoard()[i][j];
		}
	}
		temp[move.i2][move.j2] = temp[move.i1][move.j1];
		temp[move.i1][move.j1] = 'e';

		if (move.i2 - move.i1 == 2)
		{
			temp[(move.i1 + move.i2) / 2][(move.j2 + move.j1) / 2] = 'e';
		}

		if (move.i1 - move.i2 == 2)
		{
			temp[(move.i1 + move.i2) / 2][(move.j2 + move.j1) / 2] = 'e';
		}

		game.setBoard(temp);


}

int AIHard::evaluateBoard(Board game,char colour)
{
	int score;
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
			if (colour = 'r')
			{
				if (temp[i][j] == 'r')
				{
					score += 1;
				
				}
				if (temp[i][j] == 'R')
					score +=2;
				if (temp[i][j] == 'b')
				{
					score -= 10;
				
				}
				if (temp[i][j] == 'B')
					score -= 20;

			}

			if (colour = 'b')
			{
				
					if (temp[i][j] == 'b')
					{
						score += 1;
					}
				if (temp[i][j] == 'B')
					score += 2;
				if (temp[i][j] == 'r')
				{
					score -= 10;
				}
				if (temp[i][j] == 'R')
					score -= 20;

			}
		}
	}

	return score;

}

Move AIHard::minmax(Board game,int flag)
{


	auto possibleMoves = getPossibleMoves(game, colour);

	if (possibleMoves.empty())
	{
		return Move{ 0,0,0,0 };
	}

	std::array<int, 32> scores;

	for (int i = 0; i < scores.size(); i++) scores[i] = 0;
	size_t count = 0;
	for (auto posMove : possibleMoves)
	{
		scores[count] = MIN(game, flag + 1, posMove);
		count++;
	}

	int maxVal = scores[0];
	size_t maxPos = 0;
	// go through scores and find POS of maxScore
	for (size_t i = 0; i < possibleMoves.size(); i++)
	{
		if (maxVal < scores[i])
		{
			maxVal = scores[i];
			maxPos = i;
		}
	}

	// get the best move based on the max score positon
	return possibleMoves[maxPos];


}

int AIHard::MIN(Board &game, int flag, Move move)
{
	
	makeMove(game, move);
	

	std::deque<Move> possibleMoves;
	if (colour == 'r')
	{
		//evaluateBoard(game, 'b');
		possibleMoves = getPossibleMoves(game, 'b');
		if (possibleMoves.empty())
		{
			return 100000;
		}
	}
	if (colour == 'b')
	{
		//evaluateBoard(game, 'r');
		possibleMoves = getPossibleMoves(game, 'r');
		if (possibleMoves.empty())
		{
			return 100000;
		}
	}

	

	std::array<int, 32> scores;
	for (int i = 0; i < scores.size(); i++) scores[i] = 0;
	size_t count = 0;
	for (auto posMove : possibleMoves)
	{
		scores[count] = MAX(game, flag + 1, posMove);
		count++;
	}
	std::stable_sort(scores.begin(), scores.end(), std::less<int>());
	return scores[0];

}

int AIHard::MAX(Board &game, int flag, Move move)
{
	
	makeMove(game, move);


	std::deque<Move> possibleMoves;

	if (flag >=8)
	{
		if (colour == 'r')
		{
			return evaluateBoard(game, 'r');
		}
		if (colour == 'b')
		{
			return evaluateBoard(game, 'b');
		}
	}

	if (colour == 'r')
	{
	
		possibleMoves = getPossibleMoves(game, 'r');
		if (possibleMoves.empty())
		{
			return -100000;
		}
		
	}
	if (colour == 'b')
	{
		
		possibleMoves = getPossibleMoves(game, 'b');
		if (possibleMoves.empty())
		{
			return -100000;
		}
		
	}


	std::array<int, 32> scores;
	for (int i = 0; i < scores.size(); i++) scores[i] = 0;
	size_t count = 0;
	for (auto posMove : possibleMoves)
	{
		scores[count] = MIN(game, flag + 1, posMove);
		count++;
	}

	std::stable_sort(scores.begin(), scores.end(), std::greater<int>());
	return scores[0];
}