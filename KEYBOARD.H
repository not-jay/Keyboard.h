#ifndef __KEYBOARD_H
#define __KEYBOARD_H

/** Keys not supported **/
/*
 * PRINTSCREEN, PAUSE/BREAK, CAPSLOCK, 
 * L & R SHIFT, L & R CTRL, L & R ALT,
 * L & R WINDOWS Key
 *
 * L/R CTRL and SHIFT still work as modifiers though
 * Although they aren't defined
 */

/** Keyboard Keys **/
#define	KB_ESC			27
#define	KB_F1			315
#define	KB_F2			316
#define	KB_F3			317
#define	KB_F4			318
#define	KB_F5			319
#define	KB_F6			320
#define	KB_F7			321
#define	KB_F8			322
#define	KB_F9			323
#define	KB_F10			324
#define	KB_F11			389
#define	KB_F12			390
#define	KB_INS			338

#define	KB_DEL			339
#define KB_GRAVE		96  /* ` */
#define KB_TILDE		126 /* ~ */
#define	KB_1			49
#define KB_EXCLAMATION	33
#define	KB_2			50
#define KB_AT			64
#define	KB_3			51
#define KB_NUMBER		35
#define	KB_4			52
#define KB_DOLLAR		36
#define	KB_5			53
#define KB_PERCENT		37
#define	KB_6			54
#define KB_CARET		94  /* ^ */
#define	KB_7			55
#define KB_AMPERSAND	38
#define	KB_8			56
#define KB_ASTERISK		42
#define	KB_9			57
#define KB_OPARENTHESIS	40  /* ( */
#define	KB_0			48
#define KB_CPARENTHESIS	41  /* ) */
#define	KB_MINUS		45
#define KB_UNDERSCORE	95  /* _ */
#define	KB_EQUALS		61
#define KB_PLUS			43
#define	KB_BACKSPACE	8
#define	KB_HOME			327

#define	KB_TAB			9   /* Tab -> */
#define	KB_BACKTAB		271 /* <- Tab */
#define	KB_q			113
#define	KB_Q			81
#define	KB_w			119
#define	KB_W			87
#define	KB_e			101
#define	KB_E			69
#define	KB_r			114
#define	KB_R			82
#define	KB_t			116
#define	KB_T			84
#define	KB_y			121
#define	KB_Y			89
#define	KB_u			117
#define	KB_U			85
#define	KB_i			105
#define	KB_I			73
#define	KB_o			111
#define	KB_O			79
#define	KB_p			112
#define	KB_P			80
#define	KB_OBRACKET		91  /* [ */
#define	KB_OBRACE		123
#define	KB_CBRACKET		93  /* ] */
#define	KB_CBRACE		125
#define	KB_BACKSLASH	92  /* \ */
#define	KB_PIPE			124 /* | */
#define	KB_PAGEUP		329

#define KB_a			97
#define	KB_A			65
#define	KB_s			115
#define	KB_S			83
#define	KB_d			100
#define	KB_D			68
#define	KB_f			102
#define	KB_F			70
#define	KB_g			103
#define	KB_G			71
#define	KB_h			104
#define	KB_H			72
#define	KB_j			106
#define	KB_J			74
#define	KB_k			107
#define	KB_K			75
#define	KB_l			108
#define	KB_L			76
#define	KB_SEMICOLON	59  /* ; */
#define	KB_COLON		58
#define	KB_APOSTROPHE	39  /* ' */
#define	KB_QUOTATION	34  /* " */
#define	KB_ENTER		13  /* Windows */
#define	KB_PAGEDOWN		337

#define	KB_z			122
#define	KB_Z			90
#define	KB_x			120
#define	KB_X			88
#define	KB_c			99
#define	KB_C			67
#define	KB_v			118
#define	KB_V			86
#define	KB_b			98
#define	KB_B			66
#define	KB_n			110
#define	KB_N			78
#define	KB_m			109
#define	KB_M			77
#define	KB_COMMA		44
#define	KB_LESSTHAN		60
#define	KB_PERIOD		46
#define	KB_GREATERTHAN	62
#define	KB_SLASH		47  /* / */
#define	KB_QUESTIONMARK	63
#define	KB_END			335

#define	KB_SPACE		32
#define	KB_UP			328
#define	KB_LEFT			331
#define	KB_DOWN			336
#define	KB_RIGHT		333

/** Replaces getch in programs that #includes this with our getch **/
#define getch kbgetch

/** getch() with special keys support
  * 
  * @author zhukov
  * http://zhukovc.blogspot.com/2013/07/detecting-arrow-function-keys-etc-in-c.html
  */
int kbgetch() {
	int c = cgetch();
	switch(c) {
	case 0  : c = getch()+256; break; /* It is a 2 value key */
	case 224: c = getch()+512; break; /* It is a 2 value key modified with the LCTRL? */
	}
	return c;
}

/** Should you really need to use conio.h's getch **/
int cgetch() {
	int c;
	#undef getch /* undefine so we can access the real getch */
	c = getch();
	#define getch kbgetch /* redefine */
	return c;
}

#endif