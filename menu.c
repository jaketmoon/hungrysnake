#include "game.h"
#include <stdio.h>

/* void goodbye();            // 声明结束游戏的函数
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
void customize1();         // 声明自定义设置菜单的函数 */

void goodbye()
{
	system("cls");
	system("color 0f");//恢复原来颜色
	gotoxy(0, 12);
	printf("\t\t\t\t\t\t谢谢使用！\n");
	getchar();
	getchar();
}
void introduce()
{
	system("cls");
	gotoxy(0, 4);
  printf("\t\t\t\t*********************************************\n\n");
	printf("\t\t\t\t*                   游戏规则                *\n\n");
	printf("\t\t\t\t*            通过上下左右控制蛇的方向       *\n\n");
	printf("\t\t\t\t*            玩家将控制蛇吞下随机出现的豆子 *\n\n");
  printf("\t\t\t\t*            避免撞上障碍物和越来越长的身体 *\n\n");
	printf("\t\t\t\t*            吃掉所有豆子即可获得胜利。     *\n\n");
	printf("\t\t\t\t*********************************************\n\n");
	printf("\t\t\t\t\tEnter返回主菜单");
	getchar();
	getchar();
}
void edition()
{
	system("cls");
	gotoxy(0, 4);
	printf("\t\t\t\t*********************************************\n\n");
	printf("\t\t\t\t*                版本号： 1.2              *\n\n");
	printf("\t\t\t\t*                                           *\n\n");
	printf("\t\t\t\t*        更新：1.修复了不能清屏的问题     *\n\n");
	printf("\t\t\t\t*              2.修复了重复游戏时突然暴毙的问题         *\n\n");
	printf("\t\t\t\t*              3.新增了蛇撞到自己会截掉自己的功能       *\n\n");
	printf("\t\t\t\t*                                           *\n\n");
	printf("\t\t\t\t*********************************************\n\n");
	printf("\t\t\t\t\tEnter返回主菜单");
	getchar();
	
	getchar();
}
 void startgame()
{
	system("cls");
	drawmap();
	while (1)
	{
		creatvirus();
		keydown();
		Sleep(snake.speed);//void sleep(int seconds)自带函数参数 seconds 为要暂停的毫秒数。
		if (!snakestatus())//判断死亡时snakestaus为0,
		{
			gotoxy(mapwide / 2, maphigh / 2);
			printf("Game Over");
			key = 'w';
			getchar();
			getchar();
			break;
		}
		if (snake.len == snakesize)
		{
			gotoxy(mapwide / 3, maphigh / 2);
			printf("恭喜您消灭了全部病毒，胜利(＾－＾)V");
			getchar();
			respect();
			break;
		}
	}
}
int setup()
{
 
	char s;
	int a;
	system("cls");
	printf("\n\t\t\t\t\t\t1.修改难度\n");
	printf("\n\t\t\t\t\t\t2.自义定设置\n");
	printf("\n\t\t\t\t\t\t3.颜色设置\n");
	printf("\n\t\t\t\t\t\t4.返回主菜单\n");
	printf("\n\t\t\t\t\t\t请输入所选数字:");
	while (1)
	{
		s = getchar();
		a = (int)s - 48;
		if (s <= '5' && s >= '1')
			return a;
		printf("\n\t\t\t\t\t\t\t      ");
	}
}
int setup1()
{
	switch (setup())
	{
	case 1:
		diffculty();
		break;
	case 2:
		customize1();
		break;
  case 3:
        colors();
    break;
  case 4:
  
    break;
	default:
		break;
	}
	return 0;
}
int modifydiffculty()
{
	char s;
	int a;
	system("cls");
	printf("\n\n\t\t\t\t\t1.简单\n");
	printf("\n\t\t\t\t\t\t2.普通\n");
	printf("\n\t\t\t\t\t\t3.困难\n");
	printf("\n\t\t\t\t\t\t4.修罗地狱\n");
	printf("\n\t\t\t\t\t\t请输入所选数字:");
	while (1)
	{
		s = getchar();
		a = (int)s - 48;
		if (s <= '4' && s >= '1')
			return a;
		printf("\n\t\t\t\t\t\t\t      ");
	}
}
void diffculty()
{
	switch (modifydiffculty())
	{
	case 1:
		len = 4;
		speed = 500;
		snakesize = 10;
		system("cls");
		gotoxy(8, 8);
		printf("\t\t\t\t\t\t 修改成功！\n");
		printf("\t\t\t\t\t\t \n");
		system("pause");
		break;
	case 2:
		len = 4;
		speed = 300;
		snakesize = 25;
		system("cls");
		gotoxy(8, 8);
		printf("\t\t\t\t\t\t 修改成功！\n");
		printf("\t\t\t\t\t\t \n");
		system("pause");
		break;
	case 3:
		len = 4;
		speed = 70;
		snakesize = 50;
		system("cls");
		gotoxy(8, 8);
		printf("\t\t\t\t\t\t 修改成功！\n");
		printf("\t\t\t\t\t\t \n");
		system("pause");
		break;
	case 4:
		len = 4;
		speed = 25;
		snakesize = 70;
		system("cls");
		gotoxy(8, 8);
		printf("\t\t\t\t\t\t 修改成功！\n");
		printf("\t\t\t\t\t\t \n");
		system("pause");
		break;
	default:
		break;
	}
}
int customize()
{
	char s;
	int a;
	system("cls");
	printf("\n\n\t\t\t\t\t\t1.自定义速度\n");
	printf("\n\t\t\t\t\t\t2.自定义初始长度\n");
	printf("\n\t\t\t\t\t\t请输入所选数字:");
	while (1)
	{
		s = getchar();
		a = (int)s - 48;
		if (s <= '2' && s >= '1')
			return a;
		printf("\n\t\t\t\t\t\t\t      ");
	}
}
void customize1()
{
	int s;
	switch (customize())
	{
	case 1://自定义速度
		system("cls");
		gotoxy(8, 8);
		printf("\t\t\t\t请输入速度(1-999)");
		scanf_s("%d", &s);
		speed = (1000 - s);
		break;
	case 2://自定义初始长度
		system("cls");
		gotoxy(8, 8);
		printf("\t\t\t\t请输入初始长度(1-20)：");
		scanf_s("%d", &s);
		len = s;
		break;
	default:
		break;
	}
}
	//system("color 6f"); //第一个为背景色，第二个为字体颜色
   /*0 = 黑色       8 = 灰色
	1 = 蓝色       9 = 淡蓝色
	2 = 绿色       A = 淡绿色
	3 = 湖蓝色     B = 淡浅绿色
	4 = 红色       C = 淡红色
	5 = 紫色       D = 淡紫色
	6 = 黄色       E = 淡黄色
	7 = 白色       F = 亮白色*/
  int color()
{
	char s;
	int a;
	system("cls");
  printf("\t\t\t\t\t第一个为背景色，第二个为字体颜色\n");
  printf("\t\t\t\t\t\t0 = 黑色       8 = 灰色\n");
  printf("\t\t\t\t\t\t1 = 蓝色       9 = 淡蓝色\n");
  printf("\t\t\t\t\t\t2 = 绿色       A = 淡绿色\n");
  printf("\t\t\t\t\t\t3 = 湖蓝色     B = 淡浅绿色\n");
  printf("\t\t\t\t\t\t4 = 红色       C = 淡红色\n");
  printf("\t\t\t\t\t\t5 = 紫色       D = 淡紫色\n");
  printf("\t\t\t\t\t\t6 = 黄色       E = 淡黄色\n");
  printf("\t\t\t\t\t\t7 = 白色       F = 亮白色\n");
	printf("\n\n\t\t\t\t\t1.背景 黑色 字体 亮白色\n");
	printf("\n\t\t\t\t\t\t2.背景 蓝色 字体 白色\n");
	printf("\n\t\t\t\t\t\t3.背景 灰色 字体 淡黄色\n");
	printf("\n\t\t\t\t\t\t4.背景 紫色 字体 黄色\n");
	printf("\n\t\t\t\t\t\t请输入所选数字:");
	while (1)
	{
		s = getchar();
		a = (int)s - 48;
		if (s <= '4' && s >= '1')
			return a;
		printf("\n\t\t\t\t\t\t\t      ");
	}
}
void colors()
{
	switch (color())
	{
	case 1:
		system("color 0f");
		system("cls");
		gotoxy(8, 8);
		printf("\t\t\t\t\t\t 修改成功！\n");
		printf("\t\t\t\t\t\t \n");
		system("pause");
		break;
	case 2:
		
    system("color 17");
		system("cls");
		gotoxy(8, 8);
		printf("\t\t\t\t\t\t 修改成功！\n");
		printf("\t\t\t\t\t\t \n");
		system("pause");
		break;
	case 3:
		
    system("color 8e");
		system("cls");
		gotoxy(8, 8);
		printf("\t\t\t\t\t\t 修改成功！\n");
		printf("\t\t\t\t\t\t \n");
		system("pause");
		break;
	case 4:
		
    system("color 56");
		system("cls");
		gotoxy(8, 8);
		printf("\t\t\t\t\t\t 修改成功！\n");
		printf("\t\t\t\t\t\t \n");
		system("pause");
		break;
	default:
		break;
	}
}
int menuselect()
{
	char number;
	int a;
	printf("\n\t\t\t\t\t\t1.开始游戏\n");
	printf("\n\t\t\t\t\t\t2.游戏介绍\n");
	printf("\n\t\t\t\t\t\t3.游戏版本\n");
	printf("\n\t\t\t\t\t\t4.游戏设置\n");
	printf("\n\t\t\t\t\t\t5.退出游戏\n");
	printf("\n\t\t\t\t\t\t请输入所选数字:");
	while (1)
	{
		number = getchar();
		a = (int)number - 48;
		if (number <= '5' && number >= '1')
			return a;
		printf("\n\t\t\t\t\t\t\t      ");
	}
}