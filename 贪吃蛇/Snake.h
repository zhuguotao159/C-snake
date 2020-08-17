#pragma once
#define WIDE 60
#define HIGH 20
struct  BODY
{
	int X;
	int Y;
};

struct MyStruct
{
	int size;
	struct  BODY body[WIDE*HIGH];
}snake;


int food[2];
//Æ«ÒÆ×ø±ê
int dx = 0;
int dy = 0;
int lx = 0;
int ly = 0;
int score = 0;
void InitFood();
void InitSnake();
void SHowUI();
void PlayGame();