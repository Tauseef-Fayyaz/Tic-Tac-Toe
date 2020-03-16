#include<iostream>
#include<Windows.h>
using namespace std;

//Required here so defined here also;
void showStartupLogo()
{
	HANDLE c;
	c = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(c, 1);//blue-4/red
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


void getValidSelection(int *variable)
{
	bool validSelection = false;
	while (validSelection == false)
	{
		cout << " Enter your choice here: ";
		cin >> *variable;
		cout << " -----------------------\n";
		if (*variable == 1 || *variable == 2)
			validSelection = true;
		else
			cout << " <!!!> Invalid Selection <!!!>\n\n";
	}
}

//This function assigns symbols to players!
void assignSymbols(int turn, char player1[50], char player2[50], int*symbol1, int*symbol2, int gameMode)
{

	int symbol;
	if (turn == 1)
	{

		cout << "\n <***> " << player1 << " <***> \n\n";
		getValidSelection(&symbol);
		*symbol1 = symbol;
		if (*symbol1 == 1)
			*symbol2 = 2;
		else
			*symbol2 = 1;
	}
	else if (turn == 2 && gameMode == 1)
	{
		cout << "\n <***> " << player2 << " <***> \n\n";
		getValidSelection(&symbol);
		*symbol2 = symbol;
		if (*symbol2 == 1)
			*symbol1 = 2;
		else
			*symbol1 = 1;
	}

	else if (turn == 2)
	{
		*symbol2 = 1 + rand() % 2;
		if (*symbol2 == 1)
			*symbol1 = 2;
		else
			*symbol1 = 1;
		cout << " -> Its Computer's turn!\n";
		cout << " -> Computer seleted " << *symbol2 << "\n";
		cout << " -> " << player1 << " your symbol is " << *symbol1 << '\n';
	}

}

//This function decides who will get his turn first either mentioned by user or computer!
void decideTurn(char player1[50], char player2[50], int *turn, int gameMode)
{
	int turnDecider, selectTurn = 0;
	getValidSelection(&turnDecider);
	switch (turnDecider)
	{
	case 1:
		if (gameMode == 1)
		{
			cout << " >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
			cout << " ||*||*|| Select the Player ||*||*|\n";
			cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
			cout << " 1 ---> " << player1 << '\n';
			cout << " 2 ---> " << player2 << "\n\n";
		}
		else
		{
			cout << " >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
			cout << " ||*||*|| Select the Player ||*||*|\n";
			cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";
			cout << " 1 ---> " << player1 << "\n 2 ---> Computer\n";
		}
		getValidSelection(&selectTurn);
		*turn = selectTurn;
		break;

	case 2:
		*turn = 1 + rand() % 2;
		break;
	}
	if (*turn == 1)
		cout << "\n <<*-*>> " << player1 << "! your turn is at first! <<*-*>>\n\n";
	else if (*turn == 2 && gameMode == 1)
		cout << "\n <<*-*>> " << player2 << "! your turn is at first! <<*-*>>\n\n";

}

//Here updation means that it fills the Game Board Array with corresponding symbol of ongoing player! 
void updateGameBoardArray(char gameBoardArray[4][4],int selection,char symbol)
{
	switch (selection)
	{
	case 1:
		gameBoardArray[0][0] = symbol;
		break;
	case 2:
		gameBoardArray[0][1] = symbol;
		break;
	case 3:
		gameBoardArray[0][2] = symbol;
		break;
	case 4:
		gameBoardArray[1][0] = symbol;
		break;
	case 5:
		gameBoardArray[1][1] = symbol;
		break;
	case 6:
		gameBoardArray[1][2] = symbol;
		break;
	case 7:
		gameBoardArray[2][0] = symbol;
		break;
	case 8:
		gameBoardArray[2][1] = symbol;
		break;
	case 9:
		gameBoardArray[2][2] = symbol;
		break;
	}
}

//Check rows if symbols placed in it are all same!
bool rowCheck(char gameBoardArray[4][4], int rowsize, int columnsize, char symbol)
{
	int i = 0;int j = 0;
	int counter = 0;
	while (i < rowsize)
	{
		while (j < columnsize)
		{
			if (gameBoardArray[i][j] == symbol)
				counter++;
			j++;
		}
		if (counter == columnsize)
			return true;
		j = 0;
		counter = 0;
		i++;
	}
	return false;
}

//Check columns if symbols placed in it are all same!
bool columnCheck(char gameBoardArray[4][4], int rowsize, int columnsize, char symbol)
{
	int i = 0;int j = 0;
	int counter = 0;
	while (j < columnsize)
	{
		while (i < rowsize)
		{
			if (gameBoardArray[i][j] == symbol)
				counter++;
			i++;
		}
		if (counter == rowsize)
			return true;
		i = 0;
		counter = 0;
		j++;
	}
	return false;
}

//As the name suggusts!
void getPlayerNames(char player1[50], char player2[50], int gameMode)
{
	cin.get();
		cout << " >>>>>>>>>>>>>>>>>>>>>>>>>>\n";
		cout << " |*||*|| Player One ||*||*|\n";
		cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<\n";
		cout << " Enter name: ";
		cin.getline(player1, 50);
	if (gameMode == 1)
	{
		system("CLS");
		showStartupLogo();
		cout << " >>>>>>>>>>>>>>>>>>>>>>>>>>\n";
		cout << " |*||*|| Player Two ||*||*|\n";
		cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<\n";
		cout << " Enter name: ";
		cin.getline(player2, 50);
	}
	cout << "\n";
}

//Check diagonals if symbols placed in it are all same!
bool diagonalCheck(char gameBoardArray[4][4], int rowsize, int columnsize, char symbol)
{
	int i = 0; int j = 0;
	int counter = 0;
	//main diagonal check
	while (i < rowsize && j < columnsize)
	{
		if (gameBoardArray[i][j] == symbol)
			counter++;
		i = i + 1;
		j = j + 1;
	}
	if (counter == rowsize)
		return true;
	//secondary diagonal check
	counter = 0; i = rowsize-1;j = 0;
	while (i >= 0 && j < columnsize)
	{
		if (gameBoardArray[i][j] == symbol)
			counter++;
		i = i - 1;
		j = j + 1;
	}
	if (counter == rowsize)
		return true;
	return false;
}

//Checks if there is a win!
bool isWinningPoint(char gameBoardArray[4][4],int rowsize,int columnsize, char symbol)
{
	bool winPoint = rowCheck(gameBoardArray,rowsize,columnsize,symbol);
	if (winPoint)
		return true;
	winPoint = columnCheck(gameBoardArray, rowsize, columnsize, symbol);
	if (winPoint)
		return true;
	winPoint=diagonalCheck(gameBoardArray, rowsize, columnsize, symbol);
	if (winPoint)
		return true;
	return false;
}

//This function infact get input to placae the symbol on game Board!
//Also confirms if that place is not filled or out of the Board!
void getValidInput(char gameBoardArray[4][4], int *selection,int gameMode,int turn)
{
	bool validInput = false;
	while(validInput==false)
	{
		if (gameMode==2 && turn ==2 )
			*selection = 1 + rand() % 9;
		else 
		{

			cout << "---> Select the number to place your symbol at corresponding position on Game Board: ";
			cin >> *selection;
		}
		switch (*selection)
		{
		case 1:
			if (gameBoardArray[0][0] == '1')
			{
				validInput = true;
				break;
			}

		else 
			{
			if (!(gameMode==2 && turn ==2))
				cout << " <!!!> This place is already filled <!!!>\r\n ";
			validInput = false;
			break;
			}
		case 2:
			if (gameBoardArray[0][1] == '2')
			{
				validInput = true;
				break;
			}
			else
			{
				if (!(gameMode == 2 && turn == 2))
					cout << " <!!!> This place is already filled <!!!>\n ";
				validInput = false;
				break;
			}
		case 3:
			if (gameBoardArray[0][2] == '3')
			{
				validInput = true;
				break;
			}
			else
			{
				if (!(gameMode == 2 && turn == 2))
					cout << " <!!!> This place is already filled <!!!>\n ";
				validInput = false;
				break;
			}
		case 4:
			if (gameBoardArray[1][0] == '4')
			{
				validInput = true;
				break;
			}
			else
			{
				if (!(gameMode == 2 && turn == 2))
					cout << " <!!!> This place is already filled <!!!>\n ";
				validInput = false;
				break;
			}
		case 5:
			if (gameBoardArray[1][1] == '5')
			{
				validInput = true;
				break;
			}
			else
			{
				if (!(gameMode == 2 && turn == 2))
					cout << " <!!!> This place is already filled <!!!>\n ";
				validInput = false;
				break;
			}
		case 6:
			if (gameBoardArray[1][2] == '6')
			{
				validInput = true;
				break;
			}
			else
			{
				if (!(gameMode == 2 && turn == 2))
					cout << " <!!!> This place is already filled <!!!>\n ";
				validInput = false;
				break;
			}
		case 7:
			if (gameBoardArray[2][0] == '7')
			{
				validInput = true;
				break;
			}
			else
			{
				if (!(gameMode == 2 && turn == 2))
					cout << " <!!!> This place is already filled <!!!>\n ";
				validInput = false;
				break;
			}
		case 8:
			if (gameBoardArray[2][1] == '8')
			{
				validInput = true;
				break;
			}
			else
			{
				if (!(gameMode == 2 && turn == 2))
					cout << " <!!!> This place is already filled <!!!>\n ";
				validInput = false;
				break;
			}
		case 9:
			if (gameBoardArray[2][2] == '9')
			{
				validInput = true;
				break;
			}
			else
			{
				if (!(gameMode == 2 && turn == 2))
					cout << " <!!!> This place is already filled <!!!>\n ";
				validInput = false;
				break;
			}
		default:
			if (!(gameMode == 2 && turn == 2))
				cout << " <!!!> This selection out of the board <!!!>\n ";
			validInput =false;
			cout << " ";
			break;
		}
	}
}

//Set Game Mode (User vs User) or (User vs Computer)
void setGameMode(int *gameModeSelector)
{
	bool validInput = false;
	while (validInput == false)
	{
		cout << " >>>>>>>>>>>>>>>>>>>>>>>>>\n";
		cout << " |*||*|| Game Mode ||*||*|\n";
		cout << " <<<<<<<<<<<<<<<<<<<<<<<<<\n";
		cout << " 1 ---> User vs User\n 2 ---> User vs Computer\n";
		cout << " Enter your choice here: ";
		cin >> *gameModeSelector;
		cout << " -----------------------\n\n";
		if (*gameModeSelector == 1 || *gameModeSelector == 2)
			validInput = true;
		else 
			cout << " <!!!> Invalid Selection <!!!>\n\n";
	}
}
