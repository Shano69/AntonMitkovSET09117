#pragma once
#include <iostream>
class Board
{
public:
	Board();
	~Board();
	
	//start the board
	void startBoard()
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++) {
				if (i<3 && (j + i) % 2 ==1&&j<8)
				{
					m_board[i][j] = 'b';
				}
				else if (i > 4 && (i + j) % 2 == 1 && j<8) {
					m_board[i][j] = 'r';
				}
				else {
					m_board[i][j] = 'e';
				}


			}
		}
		std::cout << "Game Started" << std::endl;
	}

	//get and set board
	void setBoard(char board[8][8])
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++) {
				m_board[i][j] = board[i][j];
			}
		}
	}

	char **getBoard()
	{
		char** tempBoard = nullptr;
		tempBoard = new char*[8];
		for(int i=0;i<8;i++)
		{
			tempBoard[i] = new char[8];
			for (int j = 0; j < 8; j++)
			{
				tempBoard[i][j] = m_board[i][j];
			}
		
		}
		return tempBoard;
		 
	}
	

	void printBoard();

private:
	char m_board[8][8];

};


