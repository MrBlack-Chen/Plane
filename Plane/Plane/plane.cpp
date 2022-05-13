#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

void HideCursor(int x)
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, x};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void GotoXY(int x, int y)
{
	COORD pos;
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void DrawPlane(int x, int y)
{
	GotoXY(x, y);
	printf("      ▲");
	GotoXY(x, y + 1);
	printf("      ■");
	GotoXY(x, y + 2);
	printf("      ■");
	GotoXY(x, y + 3);
	printf("    ◢■◣ ");
	GotoXY(x, y + 4);
	printf("  ◢■■■◣ ");
	GotoXY(x, y + 5);
	printf("◢■■■■■◣ ");
	GotoXY(x, y + 6);
	printf("    ◢■◣");
	GotoXY(x, y + 7);
	printf("  ◢■■■◣");
}

void Shoot(int x, int y)
{
	while (y - 1 > 1)
	{
		GotoXY(x, y - 1);
		printf("      ★");
		GotoXY(x, y - 1);
		printf("        ");
		y--;
	}
}

void ClearBoard(int x, int y)
{
	GotoXY(x, y);
	printf("                                                        ");
	GotoXY(x, y + 1);
	printf("                                                        ");
	GotoXY(x, y + 2);
	printf("                                                        ");
	GotoXY(x, y + 3);
	printf("                                                         ");
	GotoXY(x, y + 4);
	printf("                                                         ");
	GotoXY(x, y + 5);
	printf("                                                         ");
	GotoXY(x, y + 6); 
	printf("                                                         ");
	GotoXY(x, y + 7);
	printf("                                                         ");
}

int main()
{
	system("color F0");
	system("mode con cols=70 lines=50");
	printf("请按【W】、【A】、【S】、【D】键控制飞机移动方向，按【q】键退出游戏\n");
	int x = 5, y = 10;
	int ch=0;
	HideCursor(0);
	do
	{
		GotoXY(x, y);
		DrawPlane(x,y);
		Shoot(x,y);
		Sleep(100);
		GotoXY(x, y);
		Shoot(x, y);
		ClearBoard(x,y);
		 if (_kbhit())
			ch=_getch();
		switch (ch)
			{
			case 'w':
				if (y > 2)
					y -= 1;
				break;
			case 'a':
				if (x> 1)
					x -= 1;
				break;
			case 's':
				if (y < 35)
					y += 1;
				break;
			case 'd':
				if (x < 57)
					x += 1;
				break;
			}
	} while(ch !='q');
	GotoXY(1, y);
	HideCursor(1);
	printf("退出游戏\n");
	return 0;
}