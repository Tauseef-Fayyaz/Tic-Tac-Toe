#include<iostream>
#include<iomanip>
#include<Windows.h>
using namespace std;

//This Function displays the "Tic-Tac-Toe" logo!
void showStartUpLogo()
{
	HANDLE c;
	c = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(c, 1);//1-blue2-green-4/red
	cout << " -----------------------------------------------------------------------------------------------------\n";
	SetConsoleTextAttribute(c, 2);
	cout << " |\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/ Welcome to \\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/|\n";
	SetConsoleTextAttribute(c, 1);
	cout << " -----------------------------------------------------------------------------------------------------\n";
	SetConsoleTextAttribute(c, 4);
	cout << "  -------    ---    -------     -------    ----------     -------     -------    ---------   ---------\n";
	cout << " |$$$$$$$|   |$|   |$$$$$$$| * |$$$$$$$|   |$|     |$|   |$$$$$$$| * |$$$$$$$|   |$||$||$|   |$||$||$|\n";
	cout << "  -------    |$|    -------  *  -------    |$|     |$|    -------  *  -------    |$|   |$|   |$|\n";
	cout << "    |$|      |$|   |$|       *    |$|      |$||$||$|$|   |$|       *    |$|      |$|   |$|   |$||$||$|\n";
	cout << "    |$|      |$|   |$|       *    |$|      |$|     |$|   |$|       *    |$|      |$|   |$|   |$||$||$|\n";
	cout << "    |$|      |$|    -------  *    |$|      |$|     |$|    -------  *    |$|      |$|   |$|   |$|\n";
	cout << "    |$|      |$|   |$$$$$$$| *    |$|      |$|     |$|   |$$$$$$$| *    |$|      |$||$||$|   |$||$||$|\n";
	cout << "    ---      ---    -------       ---      ---     ---    -------       ---      ---------   ---------\n";
	SetConsoleTextAttribute(c, 1);
	cout << " -----------------------------------------------------------------------------------------------------\n";
	SetConsoleTextAttribute(c, 2);
	cout << " |\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/ Made By Tauseef Fayyaz \\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/\\*/|\n";
	SetConsoleTextAttribute(c, 1);
	cout << " -----------------------------------------------------------------------------------------------------\n";
	SetConsoleTextAttribute(c, 15);

}
//This function shows updated Game Board Array
void showUpdatedGameBoard(char gameBoardArray[4][4])
{
	cout << " Game Board Status\n";
	cout << " --- --- ---\n";
	cout << "| " << gameBoardArray[0][0] << " | " << gameBoardArray[0][1] << " | " << gameBoardArray[0][2] << " |\n";
	cout << "| " << gameBoardArray[1][0] << " | " << gameBoardArray[1][1] << " | " << gameBoardArray[1][2] << " |\n";
	cout << "| " << gameBoardArray[2][0] << " | " << gameBoardArray[2][1] << " | " << gameBoardArray[2][2] << " |\n";
	cout << " --- --- ---\n";
	cout << "\n";
}

//This function shows Game Board Array!
void showGameBoard(char gameBoardArray[4][4])
{
	cout << "  Game Board\n";
	cout << " --- --- ---\n";
	cout <<"| "<< gameBoardArray[0][0] << " | " << gameBoardArray[0][1] << " | " << gameBoardArray[0][2] <<" |\n" ;
	cout << "| "<<gameBoardArray[1][0] << " | " << gameBoardArray[1][1] << " | " << gameBoardArray[1][2] << " |\n";
	cout <<"| "<< gameBoardArray[2][0] << " | " << gameBoardArray[2][1] << " | " << gameBoardArray[2][2] << " |\n";
	cout << " --- --- ---\n";
	cout << "(*) represents positions to be filled!\n";
	cout << "\n";
}

void showSymbolSelectionMenu()
{
	system("CLS");
	showStartUpLogo();
	cout << " >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
	cout << " |*||*|| Symbol Selection ||*||*|\n";
	cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
	cout << " ---> There are two symbols available! \n";
	cout << " 1 -> O\n 2 -> X\n";
}

//This function shows Input Board!
void showInputBoard()
{
	cout << " Input Board!\n";
	cout << " --- --- ---\n";
	cout << "| " <<1<< " | " <<2<< " | " <<3 << " |\n";
	cout << "| " <<4<< " | " <<5<< " | " <<6<< " |\n";
	cout << "| " <<7<< " | " <<8<< " | " <<9<< " |\n";
	cout << " --- --- ---\n";
	cout << " Place your symbol accoding to this board!\n\n";
}


//As the name suggusts!
void showGameBoardStatusAndInputBoard(char gameBoardArray[4][4])
{
	system("CLS");
	showStartUpLogo();

	cout << "  Game Board\n";
	cout << " --- --- ---\n";
	cout << "| " << gameBoardArray[0][0] << " | " << gameBoardArray[0][1] << " | " << gameBoardArray[0][2] << " |\n";

	cout << "| " << gameBoardArray[1][0] << " | " << gameBoardArray[1][1] << " | " << gameBoardArray[1][2] << " |\n";
	cout << "| " << gameBoardArray[2][0] << " | " << gameBoardArray[2][1] << " | " << gameBoardArray[2][2] << " |\n";
	cout << " --- --- ---\n";
	cout << " Numbers reprsents positions to be filled!\n";
	cout << "\n";
}

//As the name suggusts!
void showGameEnded()
{
	cout << " --------------------------\n";
	cout << " >>>>>>>>>>>>>>>>>>>>>>>>>>\n";
	cout << " |*||*|| Game Ended ||*||*|\n";
	cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	cout << " --------------------------\n";
}
//As the name suggusts!
void showGameMenu()
{

	HANDLE c;
	c = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(c, 1);//1-blue2-green-4/red
	cout << " >>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
	SetConsoleTextAttribute(c, 2);
	cout << " ||*||*|| Game Menu ||*||*||\n";
	SetConsoleTextAttribute(c, 1);
	cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
	SetConsoleTextAttribute(c, 15);
	cout << " ----->>>\n";
	cout << " 1. To start the game!\n";
	cout << " ----->>>\n";
	cout << " 2. To exit the game!\n";
	cout << " ----->>>\n";
	cout << " Enter your choice here: ";
}
// This function shows Game Logo and Game Menu1
void showGameStartup()
{
	showStartUpLogo();
	showGameMenu();
}

//This shows result! wait! results mean "You won!"
void showWinLogo(char playerName[50])
{
	system("CLS");
	showStartUpLogo();
	cout << " ------------------------------------------------------------------\n\n";
	cout << " /*/*/* " << playerName << " *\\*\\*\\\n\n";
	cout << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
	cout << " |*||*| | You Won ||*||*|\n";
	cout << " <<<<<<<<<<<<<<<<<<<<<<<<\n";
	cout << " -----------------------\n";
	cout << " -----------------------\n";

}

//Shows that there is a Tie!
void showTie()
{
	system("CLS");
	showStartUpLogo();
	cout << " ------------------------------------------------------------------\n\n";
	cout << " >>>>>>>>>>>>>>>>>>>>>>>>>\n";
	cout << " |*||*|| Its a Tie ||*||*|\n";
	cout << " <<<<<<<<<<<<<<<<<<<<<<<<<\n";
	cout << " -=-=-=-=-=-=-=-=-=-=-=-=-\n";
	cout << " =-=-=-=-=-=-=-=-=-=-=-=-=\n";

}

//This function shows Goo when the user exit the game!
void showGameExited()
{
	system("CLS");
	showStartUpLogo();
	HANDLE c;
	c = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(c, 1);//1-blue2-green-4/red
	cout << " >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
	SetConsoleTextAttribute(c, 2);
	cout << " |*||*|||*||*|||*||*|||*||*|| Game  Exited ||*||*|||*||*|||*||*|||*||*|\n";
	SetConsoleTextAttribute(c, 1);
	cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	SetConsoleTextAttribute(c, 15);
}

void showComputerWon()
{
	system("CLS");
	showStartUpLogo();
	
	cout << " >>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
	cout << " |*||*|| Computer Won ||*||*|\n";
	cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	cout << " -----------------------------\n";
	cout << " -----------------------------\n";
}

void showTurnDeciderMenu(int * gameMode)
{
	system("CLS");
	showStartUpLogo();
	HANDLE c;
	c = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(c, 1);//1-blue2-green-4/red
	cout << " >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
	SetConsoleTextAttribute(c, 2);
	cout << " ||*||*|| Who will make the first turn? ||*||*|\n";
	SetConsoleTextAttribute(c, 1);
	cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
	SetConsoleTextAttribute(c, 15);
	if (*gameMode == 1)
	{
		cout << " ----->>>\n";
		cout << " 1. Let the players to decide!\n";
		cout << " ----->>>\n";
		cout << " 2. Let the computer to decide!\n";
		cout << " ----->>>\n";
	}
	if (*gameMode == 2)
	{
		cout << " ----->>>\n";
		cout << " 1. Let the user to decide!\n";
		cout << " ----->>>\n";
		cout << " 2. Let the computer to decide!\n";
		cout << " ----->>>\n";
	}

}

