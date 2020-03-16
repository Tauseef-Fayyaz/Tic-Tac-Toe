#include<iostream>
#include"TicTacToeApplicationFunctions.h"
#include"TicTacToeApplicationLayoutFunctions.h"
#include<Windows.h>
#include<ctime>
using namespace std;

//This function contains the main coding of the game!
void startTicTacToe()
{
	system("CLS");
	showStartUpLogo();
	srand(time(0));
	bool winFlag = false;
	int gameMode=1;
	int i = 0;
	int choice = 0;
	int selection;
	int turn = 0;
	char player1[50],player2[50];
	char symbol;
	int symbol1, symbol2;
	char gameBoardArray[4][4] = { "123","456","789" };
	do
	{
		setGameMode(&gameMode);
		system("CLS");
		showStartUpLogo();
		getPlayerNames(player1, player2, gameMode);
		showTurnDeciderMenu(&gameMode);
		decideTurn(player1, player2, &turn, gameMode);
		showSymbolSelectionMenu();
		assignSymbols(turn,player1,player2, &symbol1, &symbol2, gameMode);
		while (i < 9 && winFlag == false)
		{
			if (i == 0)
				showGameBoardStatusAndInputBoard(gameBoardArray);
			if (turn == 1 && i < 9)
			{
				cout << " ---> " << player1 << "! its your turn!\n ";
				getValidInput(gameBoardArray, &selection, gameMode, turn);
				if (symbol1 == 1)
					symbol = 'O';
				else
					symbol = 'X';
				updateGameBoardArray(gameBoardArray, selection, symbol);
				showGameBoardStatusAndInputBoard(gameBoardArray);
				if (isWinningPoint(gameBoardArray, 3, 3, symbol))
				{
					showWinLogo(player1);
					winFlag = true;
					turn = 0;
				}
				i=i+1;
				if (turn == 1)
					turn = 2;
			}

			if (gameMode == 1 && turn == 2 && i < 9)
			{
				cout << '\n' << " ---> " << player2 << "! its your turn!\n ";
				getValidInput(gameBoardArray, &selection, gameMode, turn);
				if (symbol2 == 1)
					symbol = 'O';
				else
					symbol = 'X';
				updateGameBoardArray(gameBoardArray, selection, symbol);
				showGameBoardStatusAndInputBoard(gameBoardArray);
				if (isWinningPoint(gameBoardArray, 3, 3, symbol))
				{
					showWinLogo(player2);
					winFlag = true;
					turn = 0;
				}
				i=i+1;
				if (turn == 2)
					turn = 1;
			}
			if (gameMode == 2 && turn == 2 && i < 9)
			{
				
				getValidInput(gameBoardArray, &selection, gameMode, turn);
				if (symbol2 == 1)
					symbol = 'O';
				else
					symbol = 'X';
				updateGameBoardArray(gameBoardArray, selection, symbol);
				cout << " ---> Press enter to let the Computer to place its symbol on Game Board! ";
				cin.get();
				cin.get();
				cout << " ---> Computer placed his symbol at location " << selection << '\n';
				showGameBoardStatusAndInputBoard(gameBoardArray);
				if (isWinningPoint(gameBoardArray, 3, 3, symbol))
				{
					showComputerWon();
					winFlag = true;
				}
				i=i+1;
				if (turn == 2)
					turn = 1;
			}
		}
		if (winFlag == false)
			showTie();
		showGameEnded();
		char gameBoardArray[4][4] = { "123","456","789" };
		cout << " >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
		cout << " |*||*|| Do you want to Play Again? ||*||*|\n";
		cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
		cout << " 1 --:> Yes!\n 2 --:> No!\n";
		cout << " --:> Enter your choice here: ";
		cin >> choice;
		cout << " ----------------------------\n";
	} while (choice == 1);
	showGameExited();
}

//Start a Game or Exit!
void ticTacToe()
{

	
	int menuSelector;
	showGameStartup();
	cin >> menuSelector;
	if (menuSelector == 1)
		startTicTacToe();
	else if (menuSelector == 2)
	{
		
		showGameExited();
		exit(0);
	}
}
