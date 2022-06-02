#include"ChessBoard.h"
using namespace std;

ChessBoard::ChessBoard()
{
	InitWindow();
	DrawChessBoard(N / 2, N / 2);
}
void ChessBoard::InitWindow() {
	SetConsoleTitleA("五子棋");// 設定視窗標題 
	system("color 70");//設定背景顏色 
	system("mode con cols=66 lines=35");//調整視窗大小 
}
void ChessBoard::DrawChessBoard(int x, int y) {
	system("cls");//清屏 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (ChessBoardInformation[i][j] == 1)
				cout << " ●  ";
			else if (ChessBoardInformation[i][j] == 2)
				cout << " ○  ";
			else if (i == x && j == y)
				cout << " ╬  ";
			else if (i == 0 && j == 0)
				cout << " ┏  ";
			else if (i == 0 && j == N - 1)
				cout << " ┓  ";
			else if (i == N - 1 && j == 0)
				cout << " ┗  ";
			else if (i == N - 1 && j == N - 1)
				cout << " ┛  " << endl;
			else if (i == 0)
				cout << " ┳  ";
			else if (i == N - 1)
				cout << " ┻  ";
			else if (j == 0)
				cout << " ┣  ";
			else if (j == N - 1)
				cout << " ┫  ";
			else
				cout << " ┼  ";
		}
		cout << "\n";
		cout << "\n";
	}
	cout << "Now at " << x << " " << y;
}