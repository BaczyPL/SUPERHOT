#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

struct record {
	char Char;		// letter
	int dir;		// direction in which it moves
};
// "right to left" - change move direction of the letter; while on the right edge, it bounces to left
void rtl(record tab[8][4], int i, int j) {
	tab[i][j - 1] = tab[i][j];
	tab[i][j].Char = ' ';
}
// "left to right" - change move direction of the letter; while on the left edge, it bounces to right
void ltr(record tab[8][4], int i, int j) {
	tab[i][j + 1] = tab[i][j];
	tab[i][j].Char = ' ';
}
// move letters on thier new positions
void move(record tab[8][4]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			if (tab[i][j].Char != ' ') {
				if (j == 3 || j == 0)
					tab[i][j].dir *= -1;
				tab[i][j].dir == 1 ? ltr(tab, i, j) : rtl(tab, i, j);
				break;
			}
		}
	}
}
// print whole map
void show(record tab[8][4]) {
	for (int i = 0; i < 8; i++) {
		cout << endl;
		for (int j = 0; j < 4; j++)
			cout << tab[i][j].Char;
	}
}


int main (){
	record tab[8][4];

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 4; j++)
			tab[i][j].Char = ' ';

	tab[0][0].Char = 'S', tab[0][0].dir = -1;
	tab[1][1].Char = 'U', tab[1][1].dir = 1;
	tab[2][2].Char = 'P', tab[2][2].dir = 1;
	tab[3][3].Char = 'E', tab[3][3].dir = 1;
	tab[4][2].Char = 'R', tab[4][2].dir = -1;
	tab[5][1].Char = 'H', tab[5][1].dir = -1;
	tab[6][0].Char = 'O', tab[6][0].dir = -1;
	tab[7][1].Char = 'T', tab[7][1].dir = 1;

	while (true) {		// infinite loop, which ends...
		system("cls");
		move(tab);
		show(tab);
		Sleep(120);
		if (_kbhit())	// ... if any key is being pressed
			break;
	}

	return 0;
}