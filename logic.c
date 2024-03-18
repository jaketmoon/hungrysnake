#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>  // 包含操作Windows系统所需的函数
#include<time.h>    // 包含时间相关的函数
#include<conio.h>   // 包含控制台输入输出的函数
#include "game.h"   // 包含游戏的函数
//void gotoxy(int x, int y); // 声明光标移动到(x, y)位置的函数
//void keydown();            // 声明按键处理函数
//int snakestatus();         // 声明检查蛇状态的函数
//void respect();            // 声明游戏胜利后尊重玩家的函数
//void cutsnake();           // 声明蛇被切断后的函数
//int ifbarrier();          // 声明检查蛇是否撞到障碍物的函数
//void ReadGrade();         //从文件读取最高分
//void WriteGrade()        //更新最高分到文件
int max;//最高分
void keydown()//3.按键
{
	int i, temp;
	if (_kbhit()) //kbhit函数检查当前是否有键盘输入，若有则返回一个非0值，否则返回0
	{
		fflush(stdin);// 清空输入缓冲区，通常是为了确保不影响后面的数据读取
		temp = _getch();//getch:从控制台读取一个字符，但不显示在屏幕上
		if ((temp == 'a' || temp == 'A') && (key != 'D' && key != 'd'))//解决了按反方向键蛇自杀的问题
		{
			key = temp;
		}
		if ((temp == 'w' || temp == 'W') && (key != 's' && key != 'S'))
		{
			key = temp;
		}
		if ((temp == 's' || temp == 'S') && (key != 'W' && key != 'w'))
		{
			key = temp;
		}
		if ((temp == 'D' || temp == 'd') && (key != 'a' && key != 'A'))
		{
			key = temp;
		}
	}
	//擦除最后一节
	gotoxy(snake.x[snake.len - 1], snake.y[snake.len - 1]);
	printf("  ");
	for (i = snake.len - 1; i > 0; i--)
	{
		snake.x[i] = snake.x[i - 1];//以前1的位置现在变成了2，0变成了1
		snake.y[i] = snake.y[i - 1];
	}
	switch (key)//最后一节已经擦出，前移后0,1位置重合,左上角坐标为0，0
	{
	case'w':
	case'W':
		snake.y[0]--;
		break;
	case's':
	case'S':
		snake.y[0]++;
		break;
	case'a':
	case'A':
		snake.x[0] -= 2;
		break;
	case'd':
	case'D':
		snake.x[0] += 2;
		break;
	}
	gotoxy(snake.x[0], snake.y[0]);
	printf("*");
	gotoxy(mapwide + 2, 0);//将光标移走
} 
int snakestatus()//4.蛇的状态
{
	if ((snake.x[0] == 0 || snake.x[0] == mapwide) || (snake.y[0] == 0 || snake.y[0] == maphigh))
		return 0;
	if (ifbarrier() == 0)
		return 0;
	for (int k = 1; k < snake.len; k++)
	{
		if (snake.x[0] == snake.x[k] && snake.y[0] == snake.y[k])
			cutsnake(k);
	}
	return 1;
}
void gotoxy(int x, int y)
{//1.找到控制台这个窗口
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	/*HANDLE为句柄  ↑得到（输出窗口的）句柄。
	Windows是一个以虚拟内存为基础的操作系统，很多时候，
	进程的代码和数据并不全部装入内存，进程的某一段装入内存后，
	还可能被换出到外存，当再次需要时，再装入内存。两次装入的地址绝大多数情况下是不一样的。
	也就是说，同一对象在内存中的地址会变化。那么，程序怎么才能准确地访问到对象呢？为了解决这个问题，Windows引入了句柄。
	数值上，是一个32位无符号整型值（32位系统下）；逻辑上，相当于指针的指针；形象理解上，是Windows中各个对象的一个唯一的、固定不变的ID；
	作用上，Windows使用句柄来标识诸如窗口、位图、画笔等对象，并通过句柄找到这些对象。*/
	//2.设置光标
	COORD coord;
	/*COORD 为Windows.h中自带函数原型大体为struct _coord{short x;short y;}coord;*/
	coord.X = x;
	coord.Y = y;
	//4.同步到控制台SetConsoleCursorPosition
	SetConsoleCursorPosition(handle, coord);//定位到handle这个窗口，把光标打在coord坐标
}



void respect()
{
	system("cls");
	gotoxy(0, 4);
	printf("\t\t*恭喜你获得游戏的胜利*\n\n");
	Sleep(1000);
	printf("\t\t*终于完成的程序实践作业*\n\n");
	Sleep(1000);
	printf("\t\t*希望老师能给我高一点的分数*\n\n");
	Sleep(1000);
	printf("\t\t*希望自己的技术能越来越好*\n\n");
	Sleep(2000);
  printf("\t\t*     再来一局吧！       *\n\n");
  Sleep(2000);
	startgame();
}

void cutsnake(int k){
	for(int i=snake.len-1;i>=k;i--){
		gotoxy(snake.x[i],snake.y[i]);
		printf("  ");
		snake.len--;
	}
}
int ifbarrier()
{
	for (int i = 0; i < 10; i++)
	{
		if (snake.x[0] == barrier.x[i] && snake.y[0] == barrier.y[i])
			return 0;
	}
	return 1;
}
void ReadGrade()
{
	FILE* pf;
	pf= fopen("C:\\Users\\19858\\Desktop\test\\新建文件夹\\hungrysnake-1\\max.txt", "r"); //以只读的方式打开文件
	if (pf == NULL) //打开文件失败
	{
		pf = fopen("C:\\Users\\19858\\Desktop\\test\\新建文件夹\\hungrysnake-1\\max.txt", "w"); //以只写的方式打开文件
		fwrite(&max, sizeof(int), 1, pf); //将max写入文件（此时max为0），即将最高得分初始化为0
	}
	fseek(pf, 0, SEEK_SET); //使文件指针pf指向文件开头
	fread(&max, sizeof(int), 1, pf); //读取文件当中的最高得分到max当中
	fclose(pf); //关闭文件
	pf = NULL; //文件指针及时置空
}
void WriteGrade()
{
	FILE* pf = fopen("C:\\Users\\19858\\Desktop\\test\\新建文件夹\\hungrysnake-1\\max.txt", "w"); //以只写的方式打开文件
	if (pf == NULL) //打开文件失败
	{
		printf("保存最高得分记录失败\n");
		exit(0);
	}
	fwrite(&snake.len, sizeof(int), 1, pf); //将本局游戏得分写入文件当中
	fclose(pf); //关闭文件
	pf = NULL; //文件指针及时置空
}