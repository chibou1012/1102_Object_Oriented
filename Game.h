#ifndef Game_H
#define Game_H
#include<iostream>
#include<Windows.h> 
#include<conio.h>
#include<cstdio>
#include "GlobalVar.h"
using namespace std;
class Game
{
public:
	Game()
	{
		Init();
	}
	void Init();
	void play();
	int Put();
	int Judge(int x, int y);
	int g_x, g_y;
	int g_currentGamer;
};
#endif