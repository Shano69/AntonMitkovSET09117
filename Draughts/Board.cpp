#include "Board.h"

Board::Board()
{

}

Board::~Board()
{

}

//PRINT BOARD
void Board::printBoard()
{
	char coordI[8] = { 'A','B','C','D','E','F','G','H' };
	int coordJ[8] = { 1,2,3,4,5,6,7,8 };
	std::cout << "   ";

	for (int j = 0; j < 8; j++) 
	{
		std::cout << "  " << coordJ[j];
	}

	std::cout << std::endl;
	std::cout << "   ";

	for (int j = 0; j < 9; j++) 
	{
		std::cout << "___"  ;
	}
	std::cout << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std::cout << coordI[i]<<"|   ";

		for (int j = 0; j < 8; j++) {
			if (m_board[i][j] == 'e')
			{
				std::cout << "." << "  ";
			}
			else
				std::cout << char(m_board[i][j]) << "  ";
		}
		std::cout << std::endl;
	}
}