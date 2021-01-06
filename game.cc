//game.hpp

#include "mineswheeper.hpp"

using namespace std;

void loop(){
	int x = 2, y = 2;
	bool run = true;
	draw_world(world.hide);
	while (run){
		gotoxy(x+1, y+1);
		char key = getch();
		switch(key){
			case 72: if (y > 0) y--; break;
			case 75: if (x > 0) x--; break;
			case 80: if (y < HEIGHT-1) y++; break;
			case 77: if (x < WIDTH-1) x++; break;
			case 'q':
				hit(x, y);
				draw_world(world.hide);
				if (world.isLose){
					gotoxy(WIDTH+5, 5);
					cout << "Premi invio per continuare...";
					getchar();
					screen_lose();
				}
				break;
			//case 'w': flag(x, y); break;
		}
	}
}

int main(){
	
	load_world();
	//hit(3, 3);
	loop();
	
	gotoxy(0, HEIGHT+5);
	return 0;
}
