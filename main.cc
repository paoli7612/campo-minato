
#include "mineswheeper.hpp"

void draw_menu(){
	gotoxy(WIDTH+5, 5); cout << "1. Rigenera";
	
	gotoxy(WIDTH+5, 9); cout << "3. Salva";
	gotoxy(WIDTH+5, 11); cout << "4. Carica";
	gotoxy(WIDTH+5, 13); cout << "5. Esci";
}

// main
int main(int argc, char** argv){	
	srand(time(NULL));
	
	init_world();

	bool run = true;
	while (run){
		system("CLS");
		init_screen();
		draw_world(world.mat);
		draw_menu();
		gotoxy(0, HEIGHT+5);
		int scelta;
		cout << "SCELTA >>> ";
		cin >> scelta;
		
		switch(scelta){
			case 1: // Rigenera
				init_world();
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
