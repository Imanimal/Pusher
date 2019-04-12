#include "library.h"

short int button, level[20][20], strok, stolb, x, y;

void loadlvl(char filelvl[20]) {
	FILE *filelevel;
	filelevel=fopen(filelvl, "r");
	fscanf(filelevel, "%d", &strok);
	fscanf(filelevel, "%d", &stolb);
	fscanf(filelevel, "%d", &x);
	fscanf(filelevel, "%d", &y);
	for (int i=0; i < strok; i++) {
		for (int j=0; j < stolb; j++) {
			fscanf(filelevel, "%d", &level[i][j]);
		}
	}
}

void printlvl() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	printf("\n ");
	for (int i=0; i < strok; i++) {
		for (int j=0; j < stolb; j++) {
			switch(level[i][j]){
				case 1:// стена
					SetConsoleTextAttribute(hConsole, Black << 4 | Black);
					printf("%c", 219);
					break;
				case 0:// свободное пространство
					SetConsoleTextAttribute(hConsole, White << 4 | White);
					printf(" ");
					break;
				case 4:// коробка
					SetConsoleTextAttribute(hConsole, White << 4 | Brown);
					printf("%c", 219);
					break;
				case 5:// персонаж
					SetConsoleTextAttribute(hConsole, White << 4 | Black);
					printf("%c", 2);
					break;
				case 2:// выход
					SetConsoleTextAttribute(hConsole, DarkGray << 4 | Red);
					printf("%c", 4);
					break;
				default: 
					printf(" ");
			}
		}
		SetConsoleTextAttribute(hConsole, White << 4 | White);
		printf("\n ");
	}
	SetConsoleTextAttribute(hConsole, (WORD) ((White << 4) | Black));
}

bool pause(char filelvl[20]) {
	printf("\n Пауза\n 1. Продолжить\n 2. Начать заново\n 3. Выход");
	while(1) {
		button=getch();
		switch(button){
		case 27:
			return 0;
			break;
		case 49:
			return 0;
			break;
		case 50:
			loadlvl(filelvl);
			return 0;
			break;
		case 51:
			return 1;
			break;
		}
	}
}

short int position(short int coord, short int mode) {
	short int value;
	__asm{
		push	ax
		push	bx
		mov		ax, coord
		mov		bx, mode
		cmp		bx, 0
		je plus
		dec		ax
		jmp result
	plus:
		inc		ax
	result:
		mov		value, ax
		pop		bx
		pop		ax
	}
	return value;
}

bool control(char filelvl[20]) {
	bool exit=0, finish=0;
	loadlvl(filelvl);
	while(finish==0){
		printlvl();
		button=getch();
		switch(button){
		case 119:// вверх
			if(level[x-1][y]==1 || (level[x-1][y]==4 && (level[x-2][y]==1 || level[x-2][y]==2 || level[x-2][y]==4)))
				break;
			if(level[x-1][y]==4)
				level[x-2][y]=4;
			if(level[x-1][y]==2) {
				finish=1;
				break;
			}
			level[x][y]=0;
			x=position(x, 1);
			level[x][y]=5;
			break;
		case 97:// влево
			if(level[x][y-1]==1 || (level[x][y-1]==4 && (level[x][y-2]==1 || level[x][y-2]==2 || level[x][y-2]==4)))
				break;
			if(level[x][y-1]==4)
				level[x][y-2]=4;
			if(level[x][y-1]==2) {
				finish=1;
				break;
			}
			level[x][y]=0;
			y=position(y, 1);
			level[x][y]=5;
			break;
		case 115:// вниз
			if(level[x+1][y]==1 || (level[x+1][y]==4 && (level[x+2][y]==1 || level[x+2][y]==2 || level[x+2][y]==4)))
				break;
			if(level[x+1][y]==4)
				level[x+2][y]=4;
			if(level[x+1][y]==2) {
				finish=1;
				break;
			}
			level[x][y]=0;
			x=position(x, 0);
			level[x][y]=5;
			break;
		case 100:// вправо
			if(level[x][y+1]==1 || (level[x][y+1]==4 && (level[x][y+2]==1 || level[x][y+2]==2 || level[x][y+2]==4)))
				break;
			if(level[x][y+1]==4)
				level[x][y+2]=4;
			if(level[x][y+1]==2) {
				finish=1;
				break;
			}
			level[x][y]=0;
			y=position(y, 0);
			level[x][y]=5;
			break;
		case 27:
			exit=pause(filelvl);
			if (exit==1)
				return 1;
			break;
		}
		Sleep(50);
	}
	return 0;
}
