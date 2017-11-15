#include "Player.h"


Player::Player( )
{
	
}

Player::~Player()
{

}



void Player::makeMove(int i1, int j1, int i2, int j2, Board &game,bool &moveMade)
{
	 moveMade = false;
	char temp[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) {
			temp[i][j] = game.getBoard()[i][j];
		}
	}
	moveMade = false;
	
		//RED player
		if (playerColour == 'r')
		{
			//movement for pieces
			if (playerColour == temp[i1][j1])
			{
				//normal player piece move
				if (temp[i2][j2] == 'e'&& i1 - 1 == i2 && (j1 + 1 == j2 || j1 - 1 == j2))
				{
					temp[i2][j2] = temp[i1][j1];
					temp[i1][j1] = 'e';
					game.setBoard(temp);
					moveMade = true;


				}
				//Player take move left
				else if (temp[i2][j2] == 'e' && (temp[i1 - 1][j1 - 1] == 'b' || temp[i1 - 1][j1 - 1] == 'B') && i2 + 2 == i1&&j2 + 2 == j1)
				{

					temp[i2][j2] = temp[i1][j1];
					temp[i1][j1] = 'e';
					temp[i1 - 1][j1 - 1] = 'e';
					game.setBoard(temp);
					system("CLS");
					game.printBoard();
					moveMade = true;

					while (((temp[i2 - 2][j2 - 2] == 'e' && (temp[i2 - 1][j2 - 1] == 'b' || temp[i2 - 1][j2 - 1] == 'B'))) || ((temp[i2 - 2][j2 + 2] == 'e' && (temp[i2 - 1][j2 + 1] == 'b' || temp[i2 - 1][j2 + 1] == 'B'))))
					{
						if ((temp[i2 - 2][j2 - 2] == 'e' && (temp[i2 - 1][j2 - 1] == 'b' || temp[i2 - 1][j2 - 1] == 'B')))
						{
							int i3;
							int j3;
							char charI3;
							
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							 i3 = int(charI3) - int('A');
								temp[i3][j3] = temp[i2][j2];
								temp[i2][j2] = 'e';
								temp[i2 - 1][j2 - 1] = 'e';
								game.setBoard(temp);
							
							j2 = j3;
							i2 = i3;
						}

						else if ((temp[i2 - 2][j2 + 2] == 'e' && (temp[i2 - 1][j2 + 1] == 'b' || temp[i2 - 1][j2 + 1] == 'B')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							 i3 = int(charI3) - int('A');
							 j3 -= 1;
						
								temp[i3][j3] = temp[i2][j2];
								temp[i2][j2] = 'e';
								temp[i2 - 1][j2 + 1] = 'e';
								game.setBoard(temp);
								j2 = j3;
								i2 = i3;
							
						}
					}

				}
				//Player take move right
				else if (temp[i2][j2] == 'e' && (temp[i1 - 1][j1 + 1] == 'b' || temp[i1 - 1][j1 + 1] == 'B') && i2 + 2 == i1&&j2 - 2 == j1)
				{

					temp[i2][j2] = temp[i1][j1];
					temp[i1][j1] = 'e';
					temp[i1 - 1][j1 + 1] = 'e';
					game.setBoard(temp);
					system("CLS");
					moveMade = true;
					game.printBoard();

					while (((temp[i2 - 2][j2 - 2] == 'e' && (temp[i2 - 1][j2 - 1] == 'b' || temp[i2 - 1][j2 - 1] == 'B'))) || ((temp[i2 - 2][j2 + 2] == 'e' && (temp[i2 - 1][j2 + 1] == 'b' || temp[i2 - 1][j2 + 1] == 'B'))))
					{
						if ((temp[i2 - 2][j2 - 2] == 'e' && (temp[i2 - 1][j2 - 1] == 'b' || temp[i2 - 1][j2 - 1] == 'B')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							 i3 = int(charI3) - int('A');
							 j3 -= 1;
						
								temp[i3][j3] = temp[i2][j2];
								temp[i2][j2] = 'e';
								temp[i2 - 1][j2 - 1] = 'e';
								game.setBoard(temp);
								j2 = j3;
								i2 = i3;
							
						}

						else if ((temp[i2 - 2][j2 + 2] == 'e' && (temp[i2 - 1][j2 + 1] == 'b' || temp[i2 - 1][j2 + 1] == 'B')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							 i3 = int(charI3) - int('A');
							 j3 -= 1;
							if (i3 == (i2 - 2) && (j3 == (j2 + 2)|| j3 == (j2 - 2)))
							{
								temp[i3][j3] = temp[i2][j2];
								temp[i2][j2] = 'e';
								temp[i2 - 1][j2 + 1] = 'e';
								game.setBoard(temp);
								j2 = j3;
								i2 = i3;
							}
						}
					}
					
				}
			}
			//king move and take
			if ('R' == temp[i1][j1])
			{
				//Forward
				//normal player piece move
				if (temp[i2][j2] == 'e'&& i1 + 1 == i2 && (j1 + 1 == j2 || j1 - 1 == j2))
				{
					temp[i2][j2] = temp[i1][j1];
					temp[i1][j1] = 'e';
					game.setBoard(temp);
					moveMade = true;

				}
				//Player take move left
				else if (temp[i2][j2] == 'e' && (temp[i1 - 1][j1 - 1] == 'b' || temp[i1 - 1][j1 - 1] == 'B') && i2 + 2 == i1&&j2 + 2 == j1)
				{

					temp[i2][j2] = temp[i1][j1];
					temp[i1][j1] = 'e';
					temp[i1 - 1][j1 - 1] = 'e';
					game.setBoard(temp);
					system("CLS");
					game.printBoard();
					moveMade = true;

					while (((temp[i2 - 2][j2 - 2] == 'e' && (temp[i2 - 1][j2 - 1] == 'b' || temp[i2 - 1][j2 - 1] == 'B'))) || ((temp[i2 - 2][j2 + 2] == 'e' && (temp[i2 - 1][j2 + 1] == 'b' || temp[i2 - 1][j2 + 1] == 'B'))))
					{
						if ((temp[i2 - 2][j2 - 2] == 'e' && (temp[i2 - 1][j2 - 1] == 'b' || temp[i2 - 1][j2 - 1] == 'B')))
						{
							int i3;
							int j3;
							char charI3;

							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							temp[i3][j3] = temp[i2][j2];
							temp[i2][j2] = 'e';
							temp[i2 - 1][j2 - 1] = 'e';
							game.setBoard(temp);

							j2 = j3;
							i2 = i3;
						}

						else if ((temp[i2 - 2][j2 + 2] == 'e' && (temp[i2 - 1][j2 + 1] == 'b' || temp[i2 - 1][j2 + 1] == 'B')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							j3 -= 1;

							temp[i3][j3] = temp[i2][j2];
							temp[i2][j2] = 'e';
							temp[i2 - 1][j2 + 1] = 'e';
							game.setBoard(temp);
							j2 = j3;
							i2 = i3;

						}
					}

				}
				//Player take move right
				else if (temp[i2][j2] == 'e' && (temp[i1 - 1][j1 + 1] == 'b' || temp[i1 - 1][j1 + 1] == 'B') && i2 + 2 == i1&&j2 - 2 == j1)
				{

					temp[i2][j2] = temp[i1][j1];
					temp[i1][j1] = 'e';
					temp[i1 - 1][j1 + 1] = 'e';
					game.setBoard(temp);
					system("CLS");
					moveMade = true;
					game.printBoard();

					while (((temp[i2 - 2][j2 - 2] == 'e' && (temp[i2 - 1][j2 - 1] == 'b' || temp[i2 - 1][j2 - 1] == 'B'))) || ((temp[i2 - 2][j2 + 2] == 'e' && (temp[i2 - 1][j2 + 1] == 'b' || temp[i2 - 1][j2 + 1] == 'B'))))
					{
						if ((temp[i2 - 2][j2 - 2] == 'e' && (temp[i2 - 1][j2 - 1] == 'b' || temp[i2 - 1][j2 - 1] == 'B')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							j3 -= 1;

							temp[i3][j3] = temp[i2][j2];
							temp[i2][j2] = 'e';
							temp[i2 - 1][j2 - 1] = 'e';
							game.setBoard(temp);
							j2 = j3;
							i2 = i3;

						}

						else if ((temp[i2 - 2][j2 + 2] == 'e' && (temp[i2 - 1][j2 + 1] == 'b' || temp[i2 - 1][j2 + 1] == 'B')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							j3 -= 1;
							if (i3 == (i2 - 2) && (j3 == (j2 + 2) || j3 == (j2 - 2)))
							{
								temp[i3][j3] = temp[i2][j2];
								temp[i2][j2] = 'e';
								temp[i2 - 1][j2 + 1] = 'e';
								game.setBoard(temp);
								j2 = j3;
								i2 = i3;
							}
						}
					}

				}

				//backward
				//normal player piece move
				if (temp[i2][j2] == 'e'&& i1 - 1 == i2 && (j1 + 1 == j2 || j1 - 1 == j2))
				{
					temp[i2][j2] = temp[i1][j1];
					temp[i1][j1] = 'e';
					game.setBoard(temp);
					moveMade = true;

				}
				//Player take move left
				else if (temp[i2][j2] == 'e' && (temp[i1 + 1][j1 - 1] == 'b' || temp[i1 + 1][j1 - 1] == 'B') && i2 - 2 == i1&&j2 + 2 == j1)
				{

					temp[i2][j2] = temp[i1][j1];
					temp[i1][j1] = 'e';
					temp[i1 + 1][j1 - 1] = 'e';
					game.setBoard(temp);
					system("CLS");
					moveMade = true;
					game.printBoard();
					while (((temp[i2 + 2][j2 - 2] == 'e' && (temp[i2 + 1][j2 - 1] == 'b' || temp[i2 + 1][j2 - 1] == 'B'))) || ((temp[i2 + 2][j2 + 2] == 'e' && (temp[i2 + 1][j2 + 1] == 'b' || temp[i2 + 1][j2 + 1] == 'B'))))
					{
						if ((temp[i2 + 2][j2 - 2] == 'e' && (temp[i2 + 1][j2 - 1] == 'B' || temp[i2 + 1][j2 - 1] == 'b')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							j3 -= 1;

							temp[i3][j3] = temp[i2][j2];
							temp[i2][j2] = 'e';
							temp[i2 + 1][j2 - 1] = 'e';
							game.setBoard(temp);
							j2 = j3;
							i2 = i3;

						}

						else if ((temp[i2 + 2][j2 + 2] == 'e' && (temp[i2 + 1][j2 + 1] == 'b' || temp[i2 + 1][j2 + 1] == 'B')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							j3 -= 1;


							temp[i3][j3] = temp[i2][j2];
							temp[i2][j2] = 'e';
							temp[i2 + 1][j2 + 1] = 'e';
							game.setBoard(temp);
							j2 = j3;
							i2 = i3;

						}
					}

				}
				//Player take move right
				else if (temp[i2][j2] == 'e' && (temp[i1 + 1][j1 + 1] == 'b' || temp[i1 + 1][j1 + 1] == 'B') && i2 - 2 == i1&&j2 - 2 == j1)
				{

					temp[i2][j2] = temp[i1][j1];
					temp[i1][j1] = 'e';
					temp[i1 + 1][j1 + 1] = 'e';
					game.setBoard(temp);
					system("CLS");
					moveMade = true;
					game.printBoard();

					while (((temp[i2 + 2][j2 - 2] == 'e' && (temp[i2 + 1][j2 - 1] == 'b' || temp[i2 + 1][j2 - 1] == 'B'))) || ((temp[i2 + 2][j2 + 2] == 'e' && (temp[i2 + 1][j2 + 1] == 'b' || temp[i2 + 1][j2 + 1] == 'B'))))
					{
						if ((temp[i2 + 2][j2 - 2] == 'e' && (temp[i2 + 1][j2 - 1] == 'b' || temp[i2 + 1][j2 - 1] == 'B')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							j3 -= 1;

							temp[i3][j3] = temp[i2][j2];
							temp[i2][j2] = 'e';
							temp[i2 + 1][j2 - 1] = 'e';
							game.setBoard(temp);
							j2 = j3;
							i2 = i3;

						}

						else if ((temp[i2 + 2][j2 + 2] == 'e' && (temp[i2 + 1][j2 + 1] == 'b' || temp[i2 + 1][j2 + 1] == 'B')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							j3 -= 1;

							temp[i3][j3] = temp[i2][j2];
							temp[i2][j2] = 'e';
							temp[i2 + 1][j2 + 1] = 'e';
							game.setBoard(temp);
							j2 = j3;
							i2 = i3;

						}
					}

				}


			}

		}
		//Black player
		if (playerColour == 'b')
		{
			//movement for pieces
			if (playerColour == temp[i1][j1])
			{
				//normal player piece move
				if (temp[i2][j2] == 'e'&& i1 + 1 == i2 && (j1 + 1 == j2 || j1 - 1 == j2))
				{
					temp[i2][j2] = temp[i1][j1];
					temp[i1][j1] = 'e';
					game.setBoard(temp);
					moveMade = true;

				}
				//Player take move left
				else if (temp[i2][j2] == 'e' && (temp[i1 + 1][j1 - 1] == 'r' || temp[i1 + 1][j1 - 1] == 'R') && i2 - 2 == i1&&j2 + 2 == j1)
				{

					temp[i2][j2] = temp[i1][j1];
					temp[i1][j1] = 'e';
					temp[i1 + 1][j1 - 1] = 'e';
					game.setBoard(temp);
					system("CLS");
					moveMade = true;
					game.printBoard();
					while (((temp[i2 + 2][j2 - 2] == 'e' && (temp[i2 + 1][j2 - 1] == 'r' || temp[i2 + 1][j2 - 1] == 'R'))) || ((temp[i2 + 2][j2 + 2] == 'e' && (temp[i2 + 1][j2 + 1] == 'r' || temp[i2 + 1][j2 + 1] == 'R'))))
					{
						if ((temp[i2 + 2][j2 - 2] == 'e' && (temp[i2 + 1][j2 - 1] == 'R' || temp[i2 + 1][j2 - 1] == 'r')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							j3 -= 1;

							temp[i3][j3] = temp[i2][j2];
							temp[i2][j2] = 'e';
							temp[i2 + 1][j2 - 1] = 'e';
							game.setBoard(temp);
							j2 = j3;
							i2 = i3;

						}

						else if ((temp[i2 + 2][j2 + 2] == 'e' && (temp[i2 + 1][j2 + 1] == 'r' || temp[i2 + 1][j2 + 1] == 'R')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							j3 -= 1;


							temp[i3][j3] = temp[i2][j2];
							temp[i2][j2] = 'e';
							temp[i2 + 1][j2 + 1] = 'e';
							game.setBoard(temp);
							j2 = j3;
							i2 = i3;

						}
					}

				}
				//Player take move right
				else if (temp[i2][j2] == 'e' && (temp[i1 + 1][j1 + 1] == 'r' || temp[i1 + 1][j1 + 1] == 'R') && i2 - 2 == i1&&j2 - 2 == j1)
				{

					temp[i2][j2] = temp[i1][j1];
					temp[i1][j1] = 'e';
					temp[i1 + 1][j1 + 1] = 'e';
					game.setBoard(temp);
					system("CLS");
					moveMade = true;
					game.printBoard();

					while (((temp[i2 + 2][j2 - 2] == 'e' && (temp[i2 + 1][j2 - 1] == 'b' || temp[i2 + 1][j2 - 1] == 'B'))) || ((temp[i2 + 2][j2 + 2] == 'e' && (temp[i2 + 1][j2 + 1] == 'b' || temp[i2 + 1][j2 + 1] == 'B'))))
					{
						if ((temp[i2 + 2][j2 - 2] == 'e' && (temp[i2 + 1][j2 - 1] == 'b' || temp[i2 + 1][j2 - 1] == 'B')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							j3 -= 1;

							temp[i3][j3] = temp[i2][j2];
							temp[i2][j2] = 'e';
							temp[i2 + 1][j2 - 1] = 'e';
							game.setBoard(temp);
							j2 = j3;
							i2 = i3;

						}

						else if ((temp[i2 + 2][j2 + 2] == 'e' && (temp[i2 + 1][j2 + 1] == 'b' || temp[i2 + 1][j2 + 1] == 'B')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							j3 -= 1;

							temp[i3][j3] = temp[i2][j2];
							temp[i2][j2] = 'e';
							temp[i2 + 1][j2 + 1] = 'e';
							game.setBoard(temp);
							j2 = j3;
							i2 = i3;

						}
					}

				}

				
			
			}
			//king move and take
			if ('B' == temp[i1][j1])
			{
				//Forward
				//normal player piece move
				if (temp[i2][j2] == 'e'&& i1 + 1 == i2 && (j1 + 1 == j2 || j1 - 1 == j2))
				{
					temp[i2][j2] = temp[i1][j1];
					temp[i1][j1] = 'e';
					game.setBoard(temp);
					moveMade = true;

				}
			
				//Player take move left
				else if (temp[i2][j2] == 'e' && (temp[i1 + 1][j1 - 1] == 'r' || temp[i1 + 1][j1 - 1] == 'R') && i2 - 2 == i1&&j2 + 2 == j1)
				{

					temp[i2][j2] = temp[i1][j1];
					temp[i1][j1] = 'e';
					temp[i1 + 1][j1 - 1] = 'e';
					game.setBoard(temp);
					system("CLS");
					moveMade = true;
					game.printBoard();
					while (((temp[i2 + 2][j2 - 2] == 'e' && (temp[i2 + 1][j2 - 1] == 'r' || temp[i2 + 1][j2 - 1] == 'R'))) || ((temp[i2 + 2][j2 + 2] == 'e' && (temp[i2 + 1][j2 + 1] == 'r' || temp[i2 + 1][j2 + 1] == 'R'))))
					{
						if ((temp[i2 + 2][j2 - 2] == 'e' && (temp[i2 + 1][j2 - 1] == 'R' || temp[i2 + 1][j2 - 1] == 'r')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							j3 -= 1;

							temp[i3][j3] = temp[i2][j2];
							temp[i2][j2] = 'e';
							temp[i2 + 1][j2 - 1] = 'e';
							game.setBoard(temp);
							j2 = j3;
							i2 = i3;

						}

						else if ((temp[i2 + 2][j2 + 2] == 'e' && (temp[i2 + 1][j2 + 1] == 'r' || temp[i2 + 1][j2 + 1] == 'R')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							j3 -= 1;


							temp[i3][j3] = temp[i2][j2];
							temp[i2][j2] = 'e';
							temp[i2 + 1][j2 + 1] = 'e';
							game.setBoard(temp);
							j2 = j3;
							i2 = i3;

						}
					}

				}
				//Player take move right
				else if (temp[i2][j2] == 'e' && (temp[i1 + 1][j1 + 1] == 'r' || temp[i1 + 1][j1 + 1] == 'R') && i2 - 2 == i1&&j2 - 2 == j1)
				{

					temp[i2][j2] = temp[i1][j1];
					temp[i1][j1] = 'e';
					temp[i1 + 1][j1 + 1] = 'e';
					game.setBoard(temp);
					system("CLS");
					moveMade = true;
					game.printBoard();

					while (((temp[i2 + 2][j2 - 2] == 'e' && (temp[i2 + 1][j2 - 1] == 'r' || temp[i2 + 1][j2 - 1] == 'R'))) || ((temp[i2 + 2][j2 + 2] == 'e' && (temp[i2 + 1][j2 + 1] == 'r' || temp[i2 + 1][j2 + 1] == 'R'))))
					{
						if ((temp[i2 + 2][j2 - 2] == 'e' && (temp[i2 + 1][j2 - 1] == 'r' || temp[i2 + 1][j2 - 1] == 'R')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							j3 -= 1;

							temp[i3][j3] = temp[i2][j2];
							temp[i2][j2] = 'e';
							temp[i2 + 1][j2 - 1] = 'e';
							game.setBoard(temp);
							j2 = j3;
							i2 = i3;

						}

						else if ((temp[i2 + 2][j2 + 2] == 'e' && (temp[i2 + 1][j2 + 1] == 'r' || temp[i2 + 1][j2 + 1] == 'R')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							j3 -= 1;

							temp[i3][j3] = temp[i2][j2];
							temp[i2][j2] = 'e';
							temp[i2 + 1][j2 + 1] = 'e';
							game.setBoard(temp);
							j2 = j3;
							i2 = i3;

						}
					}

				}

				//backward
				//normal player piece move
				if (temp[i2][j2] == 'e'&& i1 - 1 == i2 && (j1 + 1 == j2 || j1 - 1 == j2))
				{
					temp[i2][j2] = temp[i1][j1];
					temp[i1][j1] = 'e';
					game.setBoard(temp);
					moveMade = true;

				}
				//Player take move left
				else if (temp[i2][j2] == 'e' && (temp[i1 - 1][j1 - 1] == 'r' || temp[i1 - 1][j1 - 1] == 'R') && i2 + 2 == i1&&j2 + 2 == j1)
				{

					temp[i2][j2] = temp[i1][j1];
					temp[i1][j1] = 'e';
					temp[i1 - 1][j1 - 1] = 'e';
					game.setBoard(temp);
					system("CLS");
					game.printBoard();
					moveMade = true;

					while (((temp[i2 - 2][j2 - 2] == 'e' && (temp[i2 - 1][j2 - 1] == 'r' || temp[i2 - 1][j2 - 1] == 'R'))) || ((temp[i2 - 2][j2 + 2] == 'e' && (temp[i2 - 1][j2 + 1] == 'r' || temp[i2 - 1][j2 + 1] == 'R'))))
					{
						if ((temp[i2 - 2][j2 - 2] == 'e' && (temp[i2 - 1][j2 - 1] == 'r' || temp[i2 - 1][j2 - 1] == 'R')))
						{
							int i3;
							int j3;
							char charI3;

							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							temp[i3][j3] = temp[i2][j2];
							temp[i2][j2] = 'e';
							temp[i2 - 1][j2 - 1] = 'e';
							game.setBoard(temp);

							j2 = j3;
							i2 = i3;
						}

						else if ((temp[i2 - 2][j2 + 2] == 'e' && (temp[i2 - 1][j2 + 1] == 'r' || temp[i2 - 1][j2 + 1] == 'R')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							j3 -= 1;

							temp[i3][j3] = temp[i2][j2];
							temp[i2][j2] = 'e';
							temp[i2 - 1][j2 + 1] = 'e';
							game.setBoard(temp);
							j2 = j3;
							i2 = i3;

						}
					}

				}
				//Player take move right
				else if (temp[i2][j2] == 'e' && (temp[i1 - 1][j1 + 1] == 'r' || temp[i1 - 1][j1 + 1] == 'R') && i2 + 2 == i1&&j2 - 2 == j1)
				{

					temp[i2][j2] = temp[i1][j1];
					temp[i1][j1] = 'e';
					temp[i1 - 1][j1 + 1] = 'e';
					game.setBoard(temp);
					system("CLS");
					moveMade = true;
					game.printBoard();

					while (((temp[i2 - 2][j2 - 2] == 'e' && (temp[i2 - 1][j2 - 1] == 'r' || temp[i2 - 1][j2 - 1] == 'R'))) || ((temp[i2 - 2][j2 + 2] == 'e' && (temp[i2 - 1][j2 + 1] == 'r' || temp[i2 - 1][j2 + 1] == 'R'))))
					{
						if ((temp[i2 - 2][j2 - 2] == 'e' && (temp[i2 - 1][j2 - 1] == 'r' || temp[i2 - 1][j2 - 1] == 'R')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							j3 -= 1;

							temp[i3][j3] = temp[i2][j2];
							temp[i2][j2] = 'e';
							temp[i2 - 1][j2 - 1] = 'e';
							game.setBoard(temp);
							j2 = j3;
							i2 = i3;

						}

						else if ((temp[i2 - 2][j2 + 2] == 'e' && (temp[i2 - 1][j2 + 1] == 'r' || temp[i2 - 1][j2 + 1] == 'R')))
						{
							int i3;
							int j3;
							char charI3;
							std::cout << "Take another piece" << std::endl;
							std::cin >> charI3 >> j3;
							i3 = int(charI3) - int('A');
							j3 -= 1;
							if (i3 == (i2 - 2) && (j3 == (j2 + 2) || j3 == (j2 - 2)))
							{
								temp[i3][j3] = temp[i2][j2];
								temp[i2][j2] = 'e';
								temp[i2 - 1][j2 + 1] = 'e';
								game.setBoard(temp);
								j2 = j3;
								i2 = i3;
							}
						}
					}

				}
			}

		}



	
}


