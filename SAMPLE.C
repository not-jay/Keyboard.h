#include <stdio.h>
#include <conio.h> /* You still need to #include conio */
#include "keyboard.h"

void main() {
	/* the new getch() would return values above 255, so it won't fit if your using char */
	int ch;
	
	clrscr();
	
	printf("Press F1 for Help.\n");
	printf("Press any key to quit.\n");
	
	ch = getch(); /* This should use keyboard.h's getch() */
				  /* Should you need to use the conio's getch(), use cgetch(); */
	
	/* Use the defined keys for easy comparisons */
	if(ch == KB_F1)
		printf("That wasn't so hard was it? :)\n");
		
	cgetch(); /* or getch(), either works */
}
