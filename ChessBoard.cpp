#include<iostream>
#include<Windows.h> 
#include<conio.h>
#include<cstdio>
#include"ChessBoard.h"
#include "GlobalVar.h"

using namespace std;

ChessBoard::ChessBoard()
{
	InitWindow();
	DrawChessBoard(GlobalVar::N / 2, GlobalVar::N / 2);
}
void ChessBoard::InitWindow()
{
	SetConsoleTitleA("五子棋");// 設定視窗標題 
	system("color 70");//設定背景顏色 
	system("mode con cols=66 lines=35");//調整視窗大小 
}

void ChessBoard::DrawChessBoard(int x, int y)
{
	system("cls");//清屏 
	for (int i = 0; i < GlobalVar::N; i++)
	{
		for (int j = 0; j < GlobalVar::N; j++)
		{
			if (GlobalVar::ChessBoardInformation[i][j] == 1)
				cout << " ●  ";
			else if (GlobalVar::ChessBoardInformation[i][j] == 2)
				cout << " ○  ";
			else if (i == x && j == y)
				cout << " ╬  ";
			else if (i == 0 && j == 0)
				cout << " ┏  ";
			else if (i == 0 && j == GlobalVar::N - 1)
				cout << " ┓  ";
			else if (i == GlobalVar::N - 1 && j == 0)
				cout << " ┗  ";
			else if (i == GlobalVar::N - 1 && j == GlobalVar::N - 1)
				cout << " ┛  " << endl;
			else if (i == 0)
				cout << " ┳  ";
			else if (i == GlobalVar::N - 1)
				cout << " ┻  ";
			else if (j == 0)
				cout << " ┣  ";
			else if (j == GlobalVar::N - 1)
				cout << " ┫  ";
			else
				cout << " ┼  ";
		}
		cout << "\n";
		cout << "\n";
	}
	cout << "Now at " << x << " " << y;
}