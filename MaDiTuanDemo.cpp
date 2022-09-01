#include <iostream>
#include <conio.h>
#include "windows.h"

using namespace std;

const int MAX = 5;

int Board[MAX + 1][MAX + 1] = {0};

int x[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isDone = false;

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void move(int _x, int _y, int n) {
	int x_next, y_next;
	for(int i = 0; i <= 7; i++) {
		x_next = _x + x[i];
		y_next = _y + y[i];
		if(0 < x_next && x_next <= MAX && 0 < y_next && y_next <= MAX && Board[x_next][y_next] == 0) {
			Board[x_next][y_next] = n;

			gotoxy(5 + x_next * 4, 3 + y_next *2);
//			Sleep(200);
			cout << n;
			gotoxy(6 + n * 3, 10 + MAX *2);
			cout << n;
			if(n == MAX * MAX) {
				isDone = true;
			}
			if(isDone == false)
				move(x_next, y_next, n + 1);
			if(isDone == true)
				return ;

			Board[x_next][y_next] = 0;
			gotoxy(5 + x_next * 4, 3 + y_next *2);
//			Sleep(100);
			cout << "   ";
			gotoxy(6 + n * 3, 10 + MAX *2);
			cout << "   ";
		}
	}
}

int main() {
	int _x, _y;
	cout << "\n" << "\tKnight's tour backtracking algorithm \n";
	cout << "\n Start x, y = ";
	cin >> _x >> _y;

	gotoxy(4, 4);
	cout << "\t+---+---+---+---+---+ \n";
	cout << "\t|   |   |   |   |   | \n";
	cout << "\t+---+---+---+---+---+ \n";
	cout << "\t|   |   |   |   |   | \n";
	cout << "\t+---+---+---+---+---+ \n";
	cout << "\t|   |   |   |   |   | \n";
	cout << "\t+---+---+---+---+---+ \n";
	cout << "\t|   |   |   |   |   | \n";
	cout << "\t+---+---+---+---+---+ \n";
	cout << "\t|   |   |   |   |   | \n";
	cout << "\t+---+---+---+---+---+ \n";

	gotoxy(0, 10 + MAX * 2);
	cout << "Steps: ";
	move(_x - 2, _y - 1, 1);
	gotoxy(0, 5 + MAX * 2);
	if(isDone == true)
		cout << "Done!";
	else
		cout << ".";
	return 0;
}
