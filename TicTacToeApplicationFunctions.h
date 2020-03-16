#ifndef TicTacToe_Application_Functions_h
#define TicTacToe_Application_Functions_h
void getValidSelection(int *variable);
void decideTurn(char player1[50], char player2[50],int *turn,int gameMode);
void assignSymbols(int turn, char player1[50], char player2[50], int*symbol1, int*symbol2, int gameMode);
void updateGameBoardArray(char gameBoardArray[4][4],int selection,char symbol);
bool isWinningPoint(char gameBoardArray[4][4],int rowsize,int columnsize, char symbol);
bool rowCheck(char gameBoardArray[4][4], int rowsize, int columnsize, char symbol);
bool columnCheck(char gameBoardArray[4][4], int rowsize, int columnsize, char symbol);
bool diagonalCheck(char gameBoardArray[4][4], int rowsize, int columnsize, char symbol);
void getValidInput(char gameBoardArray[4][4], int *selection,int gameMode,int turn);
void setGameMode(int *gameModeSelector);
void getPlayerNames(char player1[50], char player2[50], int gameMode);

#endif
