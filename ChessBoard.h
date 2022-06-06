#ifndef ChessBoard_H
#define ChessBoard_H
#include<iostream>
#include<Windows.h> 
#include<conio.h>
#include<cstdio>
#include "GlobalVar.h"
using namespace std;


class ChessBoard
{
public:
	ChessBoard();
	void InitWindow();//初始化視窗 
	void DrawChessBoard(int x, int y);//繪製棋盤  

};
#endif