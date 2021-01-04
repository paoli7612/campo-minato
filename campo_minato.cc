// Campo minato

#include <iostream>
#include <windows.h>

using namespace std;

const int WIDTH = 20, HEIGHT = 15;

void gotoxy(int x, int y){
	COORD CursorPos = {x, y};
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, CursorPos);
}

void init_screen(){
	for (int y=0; y<HEIGHT; y++){
		gotoxy(0, y); cout << "|";
		gotoxy(WIDTH, y); cout << "|";
	}
	for (int x=1; x<WIDTH; x++){
		gotoxy(x, 0); cout << "-";
		gotoxy(x, HEIGHT-1); cout << "-";
	}
}

int main(){
	init_screen();
	
	return 0;
	
}
