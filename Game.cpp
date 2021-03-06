#include"Game.h"
#include"ChessBoard.h"
#include<iostream>
#include<Windows.h> 
#include<conio.h>
#include<cstdio>
#include "GlobalVar.h"
using namespace std;
//初始化對局
void Game::Init()
{
	memset(GlobalVar::ChessBoardInformation, 0, sizeof(GlobalVar::ChessBoardInformation));//棋盤資料 
	g_x = GlobalVar::N / 2;//游標居中 
	g_y = GlobalVar::N / 2;
	g_currentGamer = 1;//當前玩家：黑子; 
}

//落子 
int Game::Put()
{
	if (GlobalVar::ChessBoardInformation[g_x][g_y] == 0)//判斷是否可以落子 
	{
		GlobalVar::ChessBoardInformation[g_x][g_y] = g_currentGamer;//記錄當前玩家所下的棋子 
		return 1;
	}
	else
		return 0;
}

//判斷行是否勝利 
int Game::Judge(int x, int y)
{
	//1.判斷行是否滿足條件
	int t = 0;
	for (int i = 1; i < 5; i++)
	{
		if (x - i > -1)
		{
			if (GlobalVar::ChessBoardInformation[x - i][y] == GlobalVar::ChessBoardInformation[x][y])
				t++;
			else
				break;
		}
		else
			break;
	}
	for (int i = 1; i < 5; i++)
	{
		if (x + i < GlobalVar::N)
		{
			if (GlobalVar::ChessBoardInformation[x + i][y] == GlobalVar::ChessBoardInformation[x][y])
				t++;
			else
				break;
		}
		else
			break;
	}
	if (t > 3)return GlobalVar::ChessBoardInformation[x][y];

	//2.判斷列是否滿足條件
	t = 0;
	for (int i = 1; i < 5; i++)
	{
		if (y - i > -1)
		{
			if (GlobalVar::ChessBoardInformation[x][y - i] == GlobalVar::ChessBoardInformation[x][y])
				t++;
			else
				break;
		}
		else
			break;
	}
	for (int i = 1; i < 5; i++)
	{
		if (y + i < GlobalVar::N)
		{
			if (GlobalVar::ChessBoardInformation[x][y + i] == GlobalVar::ChessBoardInformation[x][y])
				t++;
			else
				break;
		}
		else
			break;
	}
	if (t > 3)return GlobalVar::ChessBoardInformation[x][y];

	//3.判斷主對角線是否滿足條件
	t = 0;
	for (int i = 1; i < 5; i++)
	{
		if (y - i > -1 && x - i > -1)
		{
			if (GlobalVar::ChessBoardInformation[x - i][y - i] == GlobalVar::ChessBoardInformation[x][y])
				t++;
			else
				break;
		}
		else
			break;
	}
	for (int i = 1; i < 5; i++)
	{
		if (x + i < GlobalVar::N && y + i < GlobalVar::N)
		{
			if (GlobalVar::ChessBoardInformation[x + i][y + i] == GlobalVar::ChessBoardInformation[x][y])
				t++;
			else
				break;
		}
		else
			break;
	}
	if (t > 3)return GlobalVar::ChessBoardInformation[x][y];

	//4.判斷副對角線是否滿足條件
	t = 0;
	for (int i = 1; i < 5; i++)
	{
		if (y - i > -1 && x + i < GlobalVar::N)
		{
			if (GlobalVar::ChessBoardInformation[x + i][y - i] == GlobalVar::ChessBoardInformation[x][y])
				t++;
			else
				break;
		}
		else
			break;
	}
	for (int i = 1; i < 5; i++)
	{
		if (x - i > -1 && y + i < GlobalVar::N)
		{
			if (GlobalVar::ChessBoardInformation[x - i][y + i] == GlobalVar::ChessBoardInformation[x][y])
				t++;
			else
				break;
		}
		else
			break;
	}
	if (t > 3)
		return GlobalVar::ChessBoardInformation[x][y];
	else
		return 0;
}

void Game::play()
{
	int p = 0;
	while (1)
	{
		ChessBoard().DrawChessBoard(g_x, g_y);
		if (p > 0)
		{
			if (p == 1)
				MessageBoxA(GetForegroundWindow(), "black win", "Gobang", 1);
			else
				MessageBoxA(GetForegroundWindow(), "white win", "Gobang", 1);
			break;
		}

		int ch;
		ch = _getch();
		switch (ch)
		{
		case 32://空格
			if (1 == Put())
			{
				if (Judge(g_x, g_y) == 0)
					g_currentGamer = 3 - g_currentGamer;//交換玩家 
				else
					p = Judge(g_x, g_y);
			}
			break;
		case 72://上鍵
			g_x--; if (g_x < 0) g_x = GlobalVar::N - 1;
			break;
		case 80://下鍵
			g_x++; if (g_x > GlobalVar::N - 1) g_x = 0;
			break;
		case 75://左鍵 
			g_y--; if (g_y < 0) g_y = GlobalVar::N - 1;
			break;
		case 77://右鍵
			g_y++; if (g_y > GlobalVar::N - 1) g_y = 0;
			break;
		}
	}
}
