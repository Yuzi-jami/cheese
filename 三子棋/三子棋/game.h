#pragma one 
#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
void Initboard(char board[ROW][COL], int row, int col);
void Displayboard(char board[ROW][COL], int row, int col);
void Playmove(char board[ROW][COL], int row, int col);
void Computermove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);