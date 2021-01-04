#include <iostream>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <conio.h>

const char MINE = 10;
const char FLAG = 11;

const short int RED = 12;
const short int WHITE = 7;
const short int BLUE = 13;

const char FILENAME[] = "data.dat";

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

void save_world(){
	ofstream file(FILENAME);
	file.write((char*)&world, sizeof(world_t));
	file.close();	
}

void load_world(){
	ifstream file(FILENAME);
	file.read((char*)&world, sizeof(world_t));
	file.close();
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
				} else if (world.mat[x][y] == FLAG){
					setColor(BLUE);
					cout << (char)157;
					setColor(WHITE);
				} else 
					cout << world.mat[x][y];
			}
}

void draw_menu(){
	gotoxy(WIDTH+5, 5); cout << "1. Rigenera";
	gotoxy(WIDTH+5, 7); cout << "2. Gioca";
	gotoxy(WIDTH+5, 9); cout << "3. Salva";
	gotoxy(WIDTH+5, 11); cout << "4. Carica";
	gotoxy(WIDTH+5, 13); cout << "5. Esci";
}

void gioca(){
	system("cls");
	init_screen();
	draw_world();
	
	gotoxy(WIDTH+5, 5); cout << "Q. Seleziona casella";
	gotoxy(WIDTH+5, 7); cout << "W. Segna bandierina";
	gotoxy(WIDTH+5, 9); cout << (char)24 << " " << (char)25 << " " << (char)26 << " " << (char)26;
	
	int px = 3, py = 3;
	while (true){
		gotoxy(px+1, py+1);
		int key = getch();
		switch (key){
			case 72: // su
				if (py > 0)
					py--;
				break;
			case 75: // sinistra
				if (px > 0)
					px--;
				break;
			case 80: // giu
				if (py < HEIGHT-1)
					py++;
				break;
			case 77: // destra
				if (px < WIDTH-1)
					px++;
				break;
			case 119: // W
				if (world.mat[px][py] == 0){
					world.mat[px][py] = FLAG;
					setColor(BLUE);
					cout << (char)157;
					setColor(WHITE);
				} else if (world.mat[px][py] == FLAG){
					world.mat[px][py] = 0;
					cout << " ";
				}
					
		}

	}
	
	getchar();
	getchar();
}

// main
int main(){	
	srand(time(NULL));
	

	init_world();

	bool run = true;
	while (run){
		system("CLS");
		init_screen();
		draw_world();
		draw_menu();
		gotoxy(0, HEIGHT+5);
		int scelta;
		cout << "SCELTA >>> ";
		cin >> scelta;
		
		switch(scelta){
			case 1: // Rigenera
				init_world();
				break;
			case 2: // Gioca
				gioca();
				break;
			case 3: // Salva mondo
				save_world();
				break;
			case 4: // Carica
				load_world();
				break;
			case 5: // Esci
				run = false;
				break;
			default:
				cout << "Scelta non valida" << endl;

		}
	}

	

	return 0;
}
