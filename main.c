#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>  // 包含操作Windows系统所需的函数
#include<time.h>    // 包含时间相关的函数
#include<conio.h>   // 包含控制台输入输出的函数
#include "game.h"   // 包含游戏的函数
int maphigh = 28, mapwide = 84; // 定义地图的高和宽
unsigned short snakesize = 50, speed = 400, len = 4; // 定义蛇的最大长度、速度和初始长度
int key = 'w'; // 初始化蛇的移动方向为向上

/* 
void gotoxy(int x, int y); // 声明光标移动到(x, y)位置的函数
void drawmap();            // 声明绘制地图的函数
void keydown();            // 声明按键处理函数
void creatvirus();         // 声明创建病毒的函数
int snakestatus();         // 声明检查蛇状态的函数
void respect();            // 声明游戏胜利后尊重玩家的函数

void goodbye();            // 声明结束游戏的函数
void introduce();          // 声明游戏介绍的函数
void edition();            // 声明游戏版本的函数
int setup();               // 声明游戏设置的函数
void colors();             // 声明更改颜色的函数 
void startgame();          // 声明开始游戏的函数
int menuselect();          // 声明菜单选择的函数
int setup1();              // 声明设置菜单的函数
int modifydiffculty();     // 声明修改难度的函数
void diffculty();          // 声明难度设置的函数
int customize();           // 声明自定义设置的函数
void customize1();         // 声明自定义设置菜单的函数
*/
int main()
{
	for (;;)
	{ 
		system("cls");//清屏
		switch (menuselect())
		{
		case 1://开始游戏
			startgame();
			break;
		case 2://游戏介绍
			introduce();
			break;
		case 3://游戏版本
			edition();
			break;
		case 4://游戏设置
			setup1();
			break;
		case 5://退出游戏
			goodbye();
			return 0;
		default:
			break;
		}
	}
}

