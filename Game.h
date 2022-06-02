#include<iostream>
#include<Windows.h> 
#include<conio.h>
#include<cstdio>
#ifndef GAME_H
#define GAME_H
class Game
{
public:
	Game();
	void Init();
	void play();
	int Put();
	int Judge(int x, int y);
private:
	int g_x, g_y;
	int g_currentGamer;
};
#endif