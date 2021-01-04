#include <iostream>
#include <windows.h>
#include <time.h>

const char MINE = 9;

using namespace std;

// settings
const int WIDTH = 20, HEIGHT = 15;

// minesweeper
struct world_t {
	short unsigned int mat[WIDTH][HEIGHT];
	int mine = 10;
} world;

int adjacent(int x, int y){
	int adj = 0;
	for (int xx=x-1; xx<x+2; xx++)
		for (int yy=y-1; yy<y+2; yy++)
			if (world.mat[xx][yy] == MINE)
				adj++;
	return adj;
}

void init_world(){
	for (int y=0; y<HEIGHT; y++)
		for (int x=0; x<WIDTH; x++)
			world.mat[x][y] = 0;
	
	int done = 0;
	while (done < world.mine){
		int x = rand()%WIDTH;
		int y = rand()%HEIGHT;
		if (world.mat[x][y] == 0){
			world.mat[x][y] = MINE;
			done++;
		}
	}
	
	for (int y=0; y<HEIGHT; y++)
		for (int x=0; x<WIDTH; x++)
			if (world.mat[x][y] == 0)
				world.mat[x][y] = adjacent(x, y);
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
		for (int x=0; x<WIDTH; x++)	
			if (world.mat[x][y] > 0){
				gotoxy(x+1, y+1);
				cout << world.mat[x][y];
			}
}

// main
int main(){
	srand(time(NULL));
	
	init_screen();
	init_world();
	draw_world();
	getchar();
	return 0;

}
