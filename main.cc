#include <iostream>
#include <windows.h>

using namespace std;

// settings
const int WIDTH = 20, HEIGHT = 15;

// draw
void gotoxy(int x, int y){
	COORD CursorPos = {x, y};
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, CursorPos);
}

void init_screen(){
	for (int y=0; y<HEIGHT; y++){
		gotoxy(0, y); cout << (char)186;
		gotoxy(WIDTH, y); cout << (char)186;
	}
	for (int x=0; x<WIDTH; x++){
		gotoxy(x, 0); cout << (char)205;
		gotoxy(x, HEIGHT); cout << (char)205;
	}
	gotoxy(0, 0); cout << (char)201;
	gotoxy(0, HEIGHT); cout << (char)200;
	gotoxy(WIDTH, 0); cout << (char)187;
	gotoxy(WIDTH, HEIGHT); cout << (char)188;
}

int main(){
	init_screen();

	return 0;

}
