#ifndef TicTacToe_Application_Layout_h
#define TicTacToe_Application_Layout_h
void showStartUpLogo();
void showGameEnded();
void showGameBoard(char gameBoardArray[4][4]);
void showUpdatedGameBoard(char gameBoardArray[4][4]);
void showInputBoard();
void showGameStartup();
void showGameBoardStatusAndInputBoard(char gameBoardArray[4][4]);
void showGameMenu();
void showWinLogo(char playerName[50]);
void showTie();
void showTurnDeciderMenu(int * gameMode);
void showSymbolSelectionMenu();
void showComputerWon();
void showGameExited();
#endif