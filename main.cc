#include <iostream>
#include <windows.h>
#include <time.h>

const char MINE = 9;
const short int RED = 12;
const short int WHITE = 7;
enum color {
	
};

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
			if (xx >= 0 && yy >= 0 && xx < WIDTH && yy < HEIGHT && world.mat[xx][yy] == MINE)
				adj++;
	return adj;
}

void init_world(){
	for (int y=0; y<HEIGHT; y++)
		for (int x=0; x<WIDTH; x++)
			world.mat[x][y] = 0;
	
	int done = 0;
	while (done < world.mine){
		int x = rand()%(WIDTH);
		int y = rand()%(HEIGHT);
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

void setColor(int value){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
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
				if (world.mat[x][y] == MINE){
					setColor(RED);
					cout << (char)1;
					setColor(WHITE);
				} else 
					cout << world.mat[x][y];
			}
}

// main
int main(){	
	srand(time(NULL));
	
	while (true){
		system("CLS");
		init_screen();
		init_world();
		draw_world();
		gotoxy(30, 5);
		cout << "Press enter to continue..." << endl;
		getchar();
	}
	
	return 0;

}
