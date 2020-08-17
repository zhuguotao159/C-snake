#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include  "Snake.h"





void InitFood() {
	food[0] = rand() % WIDE;
	food[1] = rand() % HIGH;
}

void InitSnake() {
	snake.size = 2;
	snake.body[0].X = WIDE / 2;
	snake.body[0].Y = HIGH / 2;
	
	snake.body[1].X = WIDE / 2- 1;
	snake.body[1].Y = HIGH / 2 ;
}
void SHowUI() {
	//��ʾ�ߵ�λ��

	COORD coord;

	//coord.X = lx;
	//coord.Y = ly;
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	//putchar(' ');


	for (int i = 0; i < snake.size; i++) {
		coord.X = snake.body[i]. X;
		coord.Y = snake.body[i]. Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		if (i==0) {
			//putchar("@");
			printf("@");

		}
		else
		{
			//putchar("*");
			printf("*");
		} 

	}
	coord.X = food[0];
	coord.Y = food[1];
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	////putchar("#"); 
	printf("#");

}
void PlayGame() {
	//
	char key = 'D';
	while (snake.body[0].X >= 0 && snake.body[0].X < WIDE &&snake.body[0].Y >= 0 && snake.body[0].Y < HIGH) {
		SHowUI();
		while (_kbhit()) {
			key = _getch();
		}
		switch (key)
		{
			if (key=='A'&&key=='W'&&key=='S') {
		case 'D': case 'd': dx = 1; dy = 0; break;

		}
			if (key == 'D'&&key == 'W'&&key == 'S') {

		case 'A': case 'a': dx = -1; dy = 0; break;
			}
			if (key == 'A'&&key == 'D'&&key == 'S') {
		case 'W': case 'w': dx = 0; dy = -1; break;
			}
			if (key == 'A'&&key == 'W'&&key == 'D') {

		case 'S': case 's': dx = 0; dy = 1; break;
			}

		}

		//�������  
		//�Ƿ��������ײ
		for (int i = 1; i < snake.size; i++) {
			if (snake.body[0].X == snake.body[i].X && snake.body[0].Y == snake.body[i].Y) {
				char c = '1';
				printf("�Ƿ�ʼ��Ϸ����ʼ����1���˳���������");
				getchar(c);
				if (c == '1') {
					ss();
				}
				else
				{
					return 0;
				}
				//return;
			}
		}
		//��ʳ����ײ
		if (snake.body[0].X == food[0] && snake.body[0].Y == food[1]) {
			//�������ʳ��
			InitFood();
			snake.size++;
			//����
			score += 10;
		}
		//�߸�����������
		lx = snake.body[snake.size - 1].X;
		ly = snake.body[snake.size - 1].Y;

		for (int i = snake.size - 1; i > 0; i--) {
			snake.body[i].X = snake.body[i - 1].X;
			snake.body[i].Y = snake.body[i - 1].Y;

		}
		snake.body[0].X += dx;
		snake.body[0].Y += dy;

		Sleep(50);
		system("cls");

		for (int i = 0; i < HIGH; i++) {

			printf("%60s\n", "/");
		}
		
		for (int i = 0; i < WIDE; i++) {
			
			printf("-");
		}
		printf("Ŀǰ�����ǣ�%d", score);
		
		
	}	


}






int ss() {

	srand((size_t)time(NULL));
	//���ع��
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cci);
	InitFood();

	InitSnake();
	PlayGame();
	getchar();
	return EXIT_SUCCESS;
}

int main() {
	char c='1';
	printf("�Ƿ�ʼ��Ϸ����ʼ����1���˳���������");
	getchar(c);
	if (c == '1') {
		ss();
	}
	else
	{
		return 0;
	}
}