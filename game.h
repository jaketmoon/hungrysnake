// game.h
#ifndef GAME_H
#define GAME_H

#include <Windows.h>

// 全局变量声明
extern int maphigh, mapwide;
extern struct virus virus;
extern struct snake snake;
extern unsigned short snakesize, speed, len;
extern int key;
extern struct barrier barrier;
extern int max;
extern int flag;
// 数据结构声明
struct virus {
	int x;
	int y;
};
struct barrier {
	int x[10];
	int y[10];
};
struct snake {
	int x[50];
	int y[50];
	int len;
	int speed;
};

// 函数声明
void gotoxy(int x, int y);
void drawmap();
void keydown();
void creatvirus();
int snakestatus();
void startgame();
int menuselect();
void goodbye();
void introduce();
void edition();
int setup();
void respect();
int setup1();
int modifydiffculty();
void diffculty();
int customize();
void customize1();
void colors();
void cutsnake(int k);
void ReadGrade();
void WriteGrade();
#endif // GAME_H