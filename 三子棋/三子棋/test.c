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
			printf("���Ӯ\n");
		else if (ret == '#')
			printf("����Ӯ\n");
		else
			printf("ƽ��\n");
	
	

	
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
			printf("������\n");
			game();
			break;
		case 0:
			printf("�˳�");
			break;
		default:
			printf("�������!");
			break;


		}


	} while (input);




	return 0;
}