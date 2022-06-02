#include<iostream>
#include<Windows.h> 
#include<conio.h>
#include<cstdio>
#ifndef CHESSBOARD_H
#define CHESSBOARD_H
using namespace std;
const int N = 15;//15*15的棋盤
int static ChessBoardInformation[N][N];
class ChessBoard
{
public:
	ChessBoard();
	void InitWindow();//初始化視窗 
	void DrawChessBoard(int x, int y);//繪製棋盤 
};
#endif