#include <stdio.h>
#include <conio.h>
#include "Keyboard.h"

void main() {
	int ch;

	clrscr();

	while(1) {
		/*ch = getche();*/
		ch = getch();
		/*printf("String: ");*/
		/*ch = getchar();*/
		printf("%c - %d\n", ch, ch);
		if(ch == '.') break;
	}

	printf("\nPress Any Key...");
	getch();
}