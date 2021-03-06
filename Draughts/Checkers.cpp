// Checkers.cpp : Defines the entry point for the console application.
#pragma once

#include <iostream>
#include <stack>
#include<string>
#include<queue>

#include "Timer.h"
#include "Player.h"
#include "AIBasic.h"
#include "AIHard.h"

using namespace std;

void Menu(Player &p, Board &game, std::stack<char**> &stack, std::stack<char**> &stack2);

void startMenu(Player &p1,Player &p2, AIBasic &bot, AIBasic &bot2,bool &playingPvp,bool &playingAI,bool &playingBots, bool &playingHardBots,bool &playingAIHard,AIHard &hard,AIHard &hard2)
{
	std::cout << "Choose Colour: 'r' , 'b' or 'n' for bot play" << std::endl;
	char colour;
	std::cin >> colour;
	if (colour == 'r')
	{
		p1.setPlayerColour('r');
		std::cout << "Play PvP or Vs AI? ('1' for PVP and '2' for AI) ";
		char condition;
		std::cin >> condition;
		if (condition == '1')
		{

			p2.setPlayerColour('b');
			playingPvp = true;
			playingAI = false;

		}
		else if (condition == '2')
		{
			std::cout << "Play VS easy or VS HARD? ('1' for easy and '2' for HARD) ";
			char condition2;
			std::cin >> condition2;
			if (condition2 == '1')
			{
				bot.setAIColour('b');
				playingPvp = false;
				playingAI = true;
			}
			else if (condition2 == '2')
			{
				hard.setColour('b');
				playingPvp = false;
				playingAI = false;
				playingAIHard = true;
			}
		}
	}
	else if (colour == 'b')
	{
		p1.setPlayerColour('b');
		std::cout << "Play PvP or Vs AI? ('1' for PVP and '2' for AI) ";
		char condition;
		std::cin >> condition;
		if (condition == '1')
		{
			p2.setPlayerColour('r');
			playingPvp = true;
			playingAI = false;

		}
		else if (condition == '2')
		{
			std::cout << "Play VS easy or VS HARD? ('1' for easy and '2' for HARD) ";
			char condition2;
			std::cin >> condition2;
			if (condition2 == '1')
			{
				bot.setAIColour('r');
				playingPvp = false;
				playingAI = true;
			}
			else if (condition2 == '2')
			{
				hard.setColour('r');
				playingPvp = false;
				playingAI = false;
				playingAIHard = true;
			}
		}

	}

	else if (colour == 'n')
	{
		std::cout << "Play  easy or  HARD bots? ('1' for easy and '2' for HARD) ";
		char condition2;
		std::cin >> condition2;
		if (condition2 == '1')
		{
			bot.setAIColour('b');
			bot2.setAIColour('r');
			playingPvp = false;
			playingAI = false;
			playingBots = true;
			playingHardBots = false;
			playingAIHard = false;
		}
		else if (condition2 == '2')
		{
			hard.setColour('b');
			hard2.setColour('r');
			playingPvp = false;
			playingAI = false;
			playingBots = false;
			playingHardBots = false;
			playingAIHard = false;
			playingHardBots = true;
		}

	

	}
}

void becomeKing(Board &game)
{
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

			if (game.getBoard()[i][j] == 'b'&& i == 7)
			{
				temp[i][j] = 'B';
				game.setBoard(temp);
			}

			if (game.getBoard()[i][j] == 'r'&& i == 0)
			{
				temp[i][j] = 'R';
				game.setBoard(temp);
			}
		}
	}

}

void moveChoice(Player &p, Board &game, std::stack<char**> &stack, std::stack<char**> &stack2)
{
	char charI1;
	int j1;
	char charI2;
	int j2;
	bool pieceTaken = false;

	std::cout << "Choose piece to move:";
	std::cin >> charI1 >> j1;
	std::cout << std::endl;

	std::cout << "Choose where to make move:";
	std::cin >> charI2 >> j2;

	int i1 = int(charI1) - int('A');
	int i2 = int(charI2) - int('A');
	if (j1 > 0 && j2 > 0 && j1 < 9 && j2 < 9) {
		j1 -= 1;
		j2 -= 1;
	}
	bool moveMade = false;

	p.makeMove(i1, j1, i2, j2, game,moveMade);
	becomeKing(game);
	if (!moveMade) {
		system("CLS");
		game.printBoard();
		std::cout << "Invalid Move try again" << std::endl;
		Menu(p, game, stack, stack2);

	}



}

void undoChoice(Player &p, Board &game,std::stack<char**> &stack, std::stack<char**> &stack2)
{
	if (stack.size() > 2) {
		char temp[8][8];
		stack2.push(stack.top());
		stack.pop();
		stack.pop();
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				temp[i][j] = stack.top()[i][j];
			}
		}
		game.setBoard(temp);
		
		
	}
	
}

void redoChoice(Player &p, Board &game, std::stack<char**> &stack, std::stack<char**> &stack2)
{
	if (stack2.size() > 0)
	{
		char temp[8][8];

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				temp[i][j] = stack2.top()[i][j];
				
			}
		}
		stack.push(stack2.top());
		stack.push(stack2.top());
		game.setBoard(temp);
		stack2.pop();
	
		
	}
}

void Menu(Player &p, Board &game, std::stack<char**> &stack, std::stack<char**> &stack2)
{
	std::string choice;
	std::cout << "Press 1 to make move"<<std::endl;
	std::cout << "Press 2 to undo" << std::endl;
	std::cout << "Press 3 to redo" << std::endl;

	std::cin>>choice;


	if (choice == "1") {
		moveChoice(p, game, stack,stack2);
		stack.push(game.getBoard());
	}
	else if (choice == "2") {
		undoChoice(p,game,stack,stack2);
		system("CLS");
		game.printBoard();
		Menu(p, game, stack, stack2);
	}
	else if (choice == "3") {
		redoChoice(p,game,stack,stack2);
		system("CLS");
		game.printBoard();
		Menu(p, game, stack, stack2);
	}
	else {
		std::cout << "Choice unavailable!" << std::endl;
		Menu(p, game, stack, stack2); 
		}


}
void victoryCheck(bool &play, Board &game)
{
	int sumRed = 0;
	int sumBlack = 0;
	char temp[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j <8; j++)
		{
			temp[i][j] = game.getBoard()[i][j];
		}

	}


	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//RED AI
			if (temp[i][j] == 'r')
			{
				//movement for pieces

				//take for AI
				if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1))
				{
					sumRed += 1;
				}
				else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i > 1 && j < 6)
				{
					sumRed += 1;
				}
				//Taking enemy king with piece forward
				else if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'B'&&i > 1 && j > 1))
				{
					sumRed += 1;
				}
				else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'B'&&i > 1 && j < 6)
				{
					sumRed += 1;
				}

				//normal AI piece move
				else if (temp[i - 1][j - 1] == 'e'&&i > 0 && j > 0)
				{
					sumRed += 1;

				}
				else if (temp[i - 1][j + 1] == 'e'&&i > 0 && j < 7)
				{
					sumRed += 1;
				}


				else {}


				//movement for kings
				if (temp[i][j] == 'R')
				{

					//take for AI king foward
					if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'b'&&i > 1 && j > 1))
					{
						sumRed += 1;
					}
					else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'b'&&i > 1 && j < 6)
					{
						sumRed += 1;
					}
					//backward
					else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'b'&&i < 6 && j>1))
					{
						sumRed += 1;
					}
					else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'b'&&i < 6 && j < 6)
					{
						sumRed += 1;
					}
					//Taking enemy king with king forward with king
					else if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'B'&&i > 1 && j > 1))
					{
						sumRed += 1;
					}
					else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'B'&&i > 1 && j < 6)
					{
						sumRed += 1;
					}
					//backward
					else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'B'&&i < 6 && j>1))
					{
						sumRed += 1;
					}
					else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'B'&&i < 6 && j < 6)
					{
						sumRed += 1;
					}
					//normal AI king move forward
					else	if (temp[i - 1][j - 1] == 'e'&&i > 0 && j > 0)
					{
						sumRed += 1;
					}
					else if (temp[i - 1][j + 1] == 'e'&&i > 0 && j < 7)
					{
						sumRed += 1;
					}
					//backward
					if (temp[i + 1][j - 1] == 'e'&&i < 7 && j>0)
					{
						sumRed += 1;
					}
					else if (temp[i + 1][j + 1] == 'e'&&i < 7 && j < 7)
					{
						sumRed += 1;
					}

					else {}

				}

			}

			//BLACK AI
			else if (temp[i][j] == 'b')
			{

				//take for AI
				if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'r') && j > 1 && i < 6)
				{
					sumBlack += 1;
				}
				else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'r'&&j < 6 && i < 6)
				{
					sumBlack += 1;

				}

				//Taking enemy king with piece forward
				else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'R'&&i < 6 && j>1))
				{
					sumBlack += 1;

				}
				else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'R'&&i < 6 && j < 6)
				{
					sumBlack += 1;

				}
				//normal AI piece move
				else if (temp[i + 1][j - 1] == 'e'&&j > 0 && i < 7)
				{
					sumBlack += 1;


				}
				else if (temp[i + 1][j + 1] == 'e'&&j < 7 && i < 7)
				{
					sumBlack += 1;

				}



			}
			//movement for kings
			if (temp[i][j] == 'B')
			{

				//take for AI king foward
				if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'r'&&i > 1 && j > 1))
				{
					sumBlack += 1;


				}
				else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'r'&&i > 1 && j < 6)
				{
					sumBlack += 1;

				}
				//backward
				else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'r'&&i < 6 && j>1))
				{
					sumBlack += 1;

				}
				else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'r'&&i < 6 && j < 6)
				{
					sumBlack += 1;

				}
				//Taking enemy king with king forward with king
				else if ((temp[i - 2][j - 2] == 'e'&&temp[i - 1][j - 1] == 'R'&&i > 1 && j > 1))
				{
					sumBlack += 1;

				}
				else if (temp[i - 2][j + 2] == 'e'&&temp[i - 1][j + 1] == 'R'&&i > 1 && j < 6)
				{
					sumBlack += 1;

				}
				//backward
				else if ((temp[i + 2][j - 2] == 'e'&&temp[i + 1][j - 1] == 'R'&&i < 6 && j>1))
				{
					sumBlack += 1;

				}
				else if (temp[i + 2][j + 2] == 'e'&&temp[i + 1][j + 1] == 'R'&&i < 6 && j < 6)
				{
					sumBlack += 1;

				}


				//normal AI king move forward
				else if (temp[i - 1][j - 1] == 'e'&&i > 0 && j > 0)
				{
					sumBlack += 1;

				}
				else if (temp[i - 1][j + 1] == 'e'&&i > 0 && j < 7)
				{
					sumBlack += 1;

				}
				//backward
				else	if (temp[i + 1][j - 1] == 'e'&&i < 7 && j>0)
				{
					sumBlack += 1;

				}
				else if (temp[i + 1][j + 1] == 'e'&&i < 7 && j < 7)
				{
					sumBlack += 1;

				}


			}
		}
	}

	if (sumRed<1)
	{
		play = false;
		std::cout << "GAME OVER Winner is Black";
	}

	if (sumBlack<1)
	{
		play = false;
		std::cout << "GAME OVER Winner is Red";
	}
}

void victoryCheckBots2(bool &play, Board &game, AIHard &bot, AIHard &bot2, std::queue<char**> &replay)
{
	int sumRed = 0;
	int sumBlack = 0;
	char re;
	char temp[8][8];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			temp[i][j] = game.getBoard()[i][j];
		}

	}

	replay.push(game.getBoard());


	if (bot2.getPossibleMoves(game,bot2.getColour()).size()<1)
	{
		play = false;
		system("CLS");
		game.printBoard();
		std::cout << "GAME OVER Winner is Black" << std::endl << "Press 'r' for replay or 'z' to close";
		std::cin >> re;
		if (re == 'r')
		{
			while (replay.size() > 0) {
				char retemp[8][8];

				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						retemp[i][j] = replay.front()[i][j];
					}

				}
				system("CLS");
				game.setBoard(retemp);
				game.printBoard();
				Timer::applyTimeDelayInSeconds(2.0);
				replay.pop();
			}
		}

	}

	if (bot.getPossibleMoves(game, bot.getColour()).size()<1)
	{
		play = false;
		system("CLS");
		game.printBoard();
		std::cout << "GAME OVER Winner is Red" << std::endl << "Press 'r' for replay or 'z' to close";
		std::cin >> re;
		if (re == 'r')
		{
			while (replay.size() > 0) {
				char retemp[8][8];

				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j <8; j++)
					{
						retemp[i][j] = replay.front()[i][j];
					}

				}
				system("CLS");
				game.setBoard(retemp);
				game.printBoard();
				Timer::applyTimeDelayInSeconds(2.0);
				replay.pop();
			}
		}
	}
}

void victoryCheckBots(bool &play, Board &game, AIBasic &bot, AIBasic &bot2, std::queue<char**> &replay)
{
	int sumRed = 0;
	int sumBlack = 0;
	char re;
	char temp[8][8];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			temp[i][j] = game.getBoard()[i][j];
		}

	}

	replay.push(game.getBoard());


	if (!bot2.checkMove(game))
	{
		play = false;
		system("CLS");
		game.printBoard();
		std::cout << "GAME OVER Winner is Black" << std::endl << "Press 'r' for replay or 'z' to close";
		std::cin >> re;
		if (re == 'r')
		{
			while (replay.size() > 0) {
				char retemp[8][8];

				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						retemp[i][j] = replay.front()[i][j];
					}

				}
				system("CLS");
				game.setBoard(retemp);
				game.printBoard();
				Timer::applyTimeDelayInSeconds(2.0);
				replay.pop();
			}
		}

	}

	if (!bot.checkMove(game))
	{
		play = false;
		system("CLS");
		game.printBoard();
		std::cout << "GAME OVER Winner is Red" << std::endl << "Press 'r' for replay or 'z' to close";
		std::cin >> re;
		if (re == 'r')
		{
			while (replay.size() > 0) {
				char retemp[8][8];

				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j <8; j++)
					{
						retemp[i][j] = replay.front()[i][j];
					}

				}
				system("CLS");
				game.setBoard(retemp);
				game.printBoard();
				Timer::applyTimeDelayInSeconds(2.0);
				replay.pop();
			}
		}
	}
}

void playPvP(bool &playingPvp, Board &game, bool &p1Turn, bool &p2Turn, std::stack<char**> &turns, std::stack<char**> &turns2, Player &p1, Player &p2)
{
	while (playingPvp)
	{

		victoryCheck(playingPvp, game);
		if (p1Turn&&playingPvp)
		{
			std::cout << "Player 1 Turn" << std::endl;
			game.printBoard();
			Menu(p1, game, turns, turns2);
			system("CLS");

		}
		else if (p2Turn&&playingPvp)
		{
			std::cout << "Player 2 Turn" << std::endl;
			game.printBoard();
			Menu(p2, game, turns, turns2);
			system("CLS");

		}
		p1Turn = !p1Turn;
		p2Turn = !p2Turn;
	}
}

void playAI(bool &playingAI, Board &game, bool &p1Turn, bool &AITurn, std::stack<char**> &turns, std::stack<char**> &turns2, Player &p1, AIBasic &bot)
{
	while (playingAI)
	{
		victoryCheck(playingAI, game);
		if (p1Turn&&playingAI)
		{
			std::cout << "Player 1 Turn" << std::endl;
			game.printBoard();
			Menu(p1, game, turns, turns2);
			system("CLS");
		}
		else if (AITurn&&playingAI)
		{

			bot.makeMove(game);
			turns.push(game.getBoard());
			becomeKing(game);

			std::cout << "AI Making move";
		}
		p1Turn = !p1Turn;
		AITurn = !AITurn;
	}

}

void botPlay(bool &playingBots, Board &game, bool &p1Turn, bool &p2Turn, std::stack<char**> &turns, std::stack<char**> &turns2, AIBasic &bot, AIBasic &bot2,std::queue<char**> replay)
{
	while (playingBots)
	{
		victoryCheckBots(playingBots, game,bot,bot2,replay);
		if (p1Turn&&playingBots)
		{
			system("CLS");
			game.printBoard();
			bot.makeMove(game);
			turns.push(game.getBoard());
			becomeKing(game);

			std::cout << "AI Making move";
		}
		else if (p2Turn&&playingBots)
		{
			system("CLS");
			game.printBoard();
			bot2.makeMove(game);
			turns.push(game.getBoard());
			becomeKing(game);

			std::cout << "AI Making move";
		}
		
		//Timer::applyTimeDelayInSeconds(1.0);

		p1Turn = !p1Turn;
		p2Turn = !p2Turn;
	}
}

void playAIHard(bool &playingAIHard, Board &game, bool &p1Turn, bool &p2Turn, std::stack<char**> &turns, std::stack<char**> &turns2, Player &p1, AIHard &hard)
{
	while (playingAIHard)
	{
		victoryCheck(playingAIHard, game);
		if (p1Turn&&playingAIHard)
		{
			std::cout << "Player 1 Turn" << std::endl;
			game.printBoard();
			Menu(p1, game, turns, turns2);
			system("CLS");
		}
		else if (p2Turn&&playingAIHard)
		{

			hard.makeMove(game, hard.minmax(game, 0));
			turns.push(game.getBoard());
			becomeKing(game);

			std::cout << "AI Making move";
		}
		p1Turn = !p1Turn;
		p2Turn = !p2Turn;
	}
}

void botHardPlay(bool &playingHardBots, Board &game, bool &p1Turn, bool &p2Turn, std::stack<char**> &turns, std::stack<char**> &turns2, AIHard &hard, AIHard &hard2, std::queue<char**> replay)
{
	while (playingHardBots)
	{
		victoryCheckBots2(playingHardBots, game, hard, hard2, replay);
		if (p1Turn&&playingHardBots)
		{
			system("CLS");
			game.printBoard();
			hard.makeMove(game, hard.minmax(game, 0));
			turns.push(game.getBoard());
			becomeKing(game);

			std::cout << "AI Making move";
		}
		else if (p2Turn&&playingHardBots)
		{
			system("CLS");
			game.printBoard();
			hard2.makeMove(game, hard2.minmax(game, 0));
			turns.push(game.getBoard());
			becomeKing(game);

			std::cout << "AI Making move";
		}

		//Timer::applyTimeDelayInSeconds(1.0);

		p1Turn = !p1Turn;
		p2Turn = !p2Turn;
	}
}


int main()
{	
	Board game;
	Player p1;
	Player p2;
	AIBasic bot;
	AIBasic bot2;
	AIHard hard;
	AIHard hard2;
	

	std::stack <char**> turns;
	std::stack <char**> turns2;
	std::queue<char**> replay;
	game.startBoard();
	turns.push(game.getBoard());
	bool playingPvp = false;
	bool playingAI = false;
	bool playingBots = false;
	bool playingHardBots = false;
	bool playingAIHard = false;
	bool p1Turn = true;
	bool p2Turn = false;
	bool AIturn = false;
	bool temp = false;

	startMenu(p1, p2, bot,bot2,playingPvp,playingAI,playingBots,playingHardBots,playingAIHard,hard,hard2);
		

	//game.printBoard();
	playPvP(playingPvp,game,p1Turn,p2Turn,turns,turns2,p1,p2);
	playAI(playingAI, game, p1Turn, AIturn, turns, turns2, p1, bot);
	botPlay(playingBots, game, p1Turn, p2Turn, turns, turns2, bot, bot2,replay);
	playAIHard(playingAIHard, game, p1Turn, p2Turn, turns, turns2, p1, hard);
	botHardPlay(playingHardBots,game,p1Turn,p2Turn,turns,turns2,hard,hard2,replay);

    return 0;
}

