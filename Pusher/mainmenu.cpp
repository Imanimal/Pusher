#include "library.h"

void main() {
	system("mode con cols=70 lines=30");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hConsole,&structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &structCursorInfo);
	short int button;
	bool esc=0;
	zastavka();
	while(esc==0) {
		system("cls");
		printf("\n ТОЛКАТЕЛЬ\n\n 1. Начать игру\n 2. Выбор уровня\n 3. Справка\n 4. Автор\n 5. Выход");
		button=getch();
		switch(button){
		case 49:
			startgame();
			break;
		case 50:
			choicelvl();
			break;
		case 51:
			spravka();
			break;
		case 52:
			author();
			break;
		case 53:
			esc=1;
			break;
		}
	}
}