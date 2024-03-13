#include "game.h"
#include <stdio.h>
#include <time.h>
struct virus virus;
struct snake snake;
//void drawmap();//1.画地图
//void creatvirus();//2.产生病毒
void drawmap()//1.画地图
{
	//●: 食物   █：蛇身(占用两个字符）

srand((unsigned int)time(NULL));//随机病毒出现的位置
	int i, k;
	for (i = 0; i <= maphigh-1; i++)
	{
		gotoxy(0, i);
		printf("|");//打印左边框
		gotoxy(mapwide, i);
		printf("|");//打印右边框
	}
	for (i = 0; i < mapwide-1; i ++)//+=2因为 占两个字节
	{
		gotoxy(i, 0);
		printf("一");//打印下边框
		gotoxy(i, maphigh);
		printf("一");//打印上边框
	}
	//画蛇
	snake.len = len;
	snake.speed = speed;
	//初始化蛇的位置
	snake.x[0] = mapwide / 2;
	snake.y[0] = maphigh / 2;//[0]为蛇头的位置
	//画蛇头
	gotoxy(snake.x[0], snake.y[0]);
	printf("*");
	//画蛇身
	for (k = 1; k < snake.len; k++)
	{
		snake.x[k] = snake.x[k - 1] + 2;
		snake.y[k] = snake.y[k - 1];
		gotoxy(snake.x[k], snake.y[k]);
		printf("*");
	}
	while (1)
	{
		virus.x = rand() % (mapwide - 4) + 2;//+2,+1这个与█所占的字符有关，长占两个字符宽1个
		virus.y = rand() % (maphigh - 2) + 1;//画个图，显而易见
		if (virus.x % 2 == 0)
			break;
	}
	gotoxy(virus.x, virus.y);
	printf("●");
	gotoxy(mapwide + 4, maphigh);
 
}
void creatvirus()//2.产生病毒
{
	if (snake.x[0] == virus.x && snake.y[0] == virus.y)
	{
		//printf("\a");//声音
		snake.len++;
		srand((unsigned)time(NULL));
		while (1)
		{
			int flag = 1;
			virus.x = rand() % (mapwide - 4) + 2;//+2,+1这个与█所占的字符有关，长占两个字符宽1个
			virus.y = rand() % (maphigh - 2) + 1;//画个图，显而易见
		//产生的病毒不能在蛇的身上
			for (int k = 0; k < snake.len; k++)
			{
				if (snake.x[k] == virus.x && snake.y[k] == virus.y)
				{
					flag = 0;//virus不合适的标志
					break;
				}
			}
			if (flag == 1 && virus.x % 2 == 0)//病毒位置合法且x坐标为偶数
			{//x左右是以两个字节为单位运动的，若virus的x坐标为奇数，就不存在snake.x[k] == virus.x
				break;
			}
		}
	}
	gotoxy(virus.x, virus.y);
	printf("●");
	gotoxy(mapwide + 8, 0);//将光标移走
	printf("W");
	gotoxy(mapwide + 6, 1);
	printf("A S D \t进行控制");
	gotoxy(mapwide + 4, maphigh);
 
 
 
}