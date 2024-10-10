//#define _CRT_SECURE_NO_WARNINGS
//
//#include "game.h"	
//void Initboard(char board[ROW][COL], int row, int col)
//{
//	int i = 0, j = 0;
//	for (i=0; i < row;i++)
//	{
//		for (j=0; j < col; j++)
//		{
//			board[i][j] = ' ';
//		}
//	}
//}
//void Displayboard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i; i < row;i++)
//	{
//		//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//
//		for (int j = 0; j < col; j++)
//		{
//			printf(" %c ",board[i][j]);
//			if (j<col-1)
//			{
//				printf("|");
//			}
//
//		}
//		printf("\n");
//		if (i < row - 1)
//		{	/*printf("___|___|___\n");*/
//			{
//				for (int j = 0; j < col; j++)
//				{
//					printf("___");
//					if (j < col - 1)
//					{
//						printf("|");
//					}
//
//				}
//				printf("\n");
//			}
//		
//		}
//	}
//	
//
//}
//
//void Playmove(char board[ROW][COL], int row, int col)
//{
//	int x = 0, y = 0;
//	printf("玩家下棋:>\n");
//	while (1)
//	{
//		
//		printf("请输入坐标\n");
//		scanf("%d %d", &x, &y);
//
//		if (x >= 1 && x <= row && y >= 1 && y <= col)
//		{
//			if (board[x - 1][y - 1] ==' ')
//			{
//				board[x - 1][y - 1] = '*';
//				break;
//			}
//			else
//			{
//				printf("坐标已被占用");
//			}
//		}
//		else
//		{
//			printf("输入错误，请合理输入");
//		}
//
//	}
//}
#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"


void Initboard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}


void Displayboard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1) {
			for (int j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}

	}
}


void Playermove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("玩家下棋-->\n");
	while (1)
	{
		printf("请输入下棋的坐标，用空格分开>>>");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("坐标被占，重新输入坐标\n");
			}
		}
		else {
			printf("非法坐标，请重新输入坐标\n");
		}
	}
}

void Computermove(char board[ROW][COL], int row, int col)
{
	srand((unsigned int)time(NULL));
	int x = 0, y = 0;
	printf("电脑下棋-->\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}
}
int IsFull(char board[ROW][COL], int row, int col) 
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
	
	for (int i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
			return board[i][0];
		}
	}
	
	for (int j = 0; j < row; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
			return board[0][j];
		}
	}
	
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	
	if (IsFull(board, row, col)) 
	{
		return 'Q';
	}
	
	return 'C';
}