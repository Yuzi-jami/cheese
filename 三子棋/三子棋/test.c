#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("******************************\n");
	printf("*******1  play ***0 exit******\n");
	printf("******************************\n");
}

void game()
{
	char board[ROW][COL] = {0};
	Initboard(board,ROW,COL);
	Displayboard(board,ROW,COL);
	char ret = 0;
	while (1)
	{

	

		
		Playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		
		Computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
		if (ret == '*')
			printf("玩家赢\n");
		else if (ret == '#')
			printf("电脑赢\n");
		else
			printf("平局\n");
	
	

	
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("choose");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			printf("退出");
			break;
		default:
			printf("输入错误!");
			break;


		}


	} while (input);




	return 0;
}