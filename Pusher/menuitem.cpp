#include "library.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
char waylvl[9]="lvl/lvl_", filelvl[20];

void createwaylvl(char namelvl[10]) {
	for (short int i=0; i<20; i++)
		filelvl[i]=0;
	strcpy(filelvl, waylvl);
	strcat(filelvl, namelvl);
	strcat(filelvl, ".txt");
}

void startgame() {
	bool exit=0;
	short int lvl=0, lastlvl=5;
	char namelvl[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	while (exit==0) {
				_asm{
					push	ax
					mov		ax, lvl
					inc		ax
					mov		lvl, ax
					pop		ax
				}
				if (lvl>lastlvl) {
					system("cls");
					printf("\n КОНЕЦ!\n (нажмите любую клавишу, чтобы вернуться в главное меню)");
					getch();
					break;
				}
				system("cls");
				printf("\n Уровень №%d", lvl);
				itoa(lvl, namelvl, 10);
				createwaylvl(namelvl);
				Sleep(3000);
				exit=control(filelvl);
			}
			lvl=0;
			exit=0;
}

void choicelvl() {
	bool back=0;
	while (1) {
		system("cls");
		char namelvl[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		back=0;
		printf("\n Введите название или номер уровня (1-5, 0 - выход): ");
		gets(namelvl);
		if (namelvl[0]==48) {
			back=1;
			break;
		}
		createwaylvl(namelvl);
		if (!access(filelvl,0))
			break;
		else
			printf(" Такого уровня не существует.\n");
		Sleep(3000);
	}
	if (back!=1)
		control(filelvl);
}

void zastavka() {
	Sleep(1000);
	SetConsoleTextAttribute(hConsole, White << 4 | LightGray);
	printf("\n\n  ТОЛКАТЕЛЬ");
	Sleep(20);
	system("cls");
	SetConsoleTextAttribute(hConsole, White << 4 | DarkGray);
	printf("\n\n  ТОЛКАТЕЛЬ");
	Sleep(20);
	system("cls");
	SetConsoleTextAttribute(hConsole, White << 4 | Black);
	printf("\n\n  ТОЛКАТЕЛЬ");
	Sleep(2000);
	system("cls");
	SetConsoleTextAttribute(hConsole, White << 4 | DarkGray);
	printf("\n\n  ТОЛКАТЕЛЬ");
	Sleep(20);
	system("cls");
	SetConsoleTextAttribute(hConsole, White << 4 | LightGray);
	printf("\n\n  ТОЛКАТЕЛЬ");
	Sleep(20);
	system("cls");
	SetConsoleTextAttribute(hConsole, White << 4 | Black);
	Sleep(1000);
}

void spravka() {
	system("cls");
	printf("\n Игра: Толкатель.\n");
	printf("\n Цель в игре: найти выход.\n");
	printf("\n Правили:\n");
	printf(" 1) Персонаж может сдвинуть коробку перед собой, но только одну;\n");
	printf(" 2) Персонаж не может проходить сквозь стены;\n");
	printf(" 3) Чтобы пройти уровень, вам необходимо добраться до двери выхода.\n");
	printf("\n Обозначения:\n\n");
	printf(" %c - персонаж;\n\n", 2);
	SetConsoleTextAttribute(hConsole, White << 4 | Brown);
	printf(" %c", 219);
	SetConsoleTextAttribute(hConsole, White << 4 | Black);
	printf(" - коробка;\n\n ");
	SetConsoleTextAttribute(hConsole, DarkGray << 4 | Red);
	printf("%c", 4);
	SetConsoleTextAttribute(hConsole, White << 4 | Black);
	printf(" - выход.\n");
	printf("\n Управлени:\n\n WASD - клавиши управления персонажем;\n Esc - пауза;\n 1, 2, 3... - клавиши управления меню/паузы.\n");
	printf("\n Нажмите любую клавишу для возврата в меню.");
	getch();
}

void author() {
	system("cls");
	printf("\n Данная программа является курсовым проектом\n\n Автор:\n студент группы 15ВВ2\n Жданов Д.М.\n\n 2016");
	getch();
}