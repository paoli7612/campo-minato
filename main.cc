#include <iostream>
#include <windows.h>

using namespace std;

// settings
const int WIDTH = 20, HEIGHT = 15;

// minesweeper
struct world_t {
	short unsigned int mat[WIDTH][HEIGHT];
} world;

void init_world(){
	for (int y=0; y<HEIGHT; y++)
		for (int x=0; x<WIDTH; x++)
			world.mat[x][y] = 0;
}

// draw
void gotoxy(int x, int y){
	COORD CursorPos = {x, y};
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, CursorPos);
}

void init_screen(){
	for (int y=0; y<HEIGHT+1; y++){
		gotoxy(0, y); cout << (char)186;
		gotoxy(WIDTH+1, y); cout << (char)186;
	}
	for (int x=0; x<WIDTH+1; x++){
		gotoxy(x, 0); cout << (char)205;
		gotoxy(x, HEIGHT+1); cout << (char)205;
	}
	gotoxy(0, 0); cout << (char)201;
	gotoxy(0, HEIGHT+1); cout << (char)200;
	gotoxy(WIDTH+1, 0); cout << (char)187;
	gotoxy(WIDTH+1, HEIGHT+1); cout << (char)188;
}

void draw_world(){
	for (int y=0; y<HEIGHT; y++)
		for (int x=0; x<WIDTH; x++)	{
			gotoxy(x+1, y+1);
			cout << world.mat[x][y];
		}
}

// main
int main(){
	init_screen();
	init_world();
	draw_world();
	getchar();
	return 0;

}
