#include "functions.h"

int main(void) {
	
init:

	signal(SIGINT, inthandler);
	signal(SIGSEGV, segvhandler);

	color = !(has_colors());

	initscr();
	erase();

	if (color == TRUE) {

		start_color();
		init_color(COLOR_BLACK, 0, 0, 0);
		init_pair(1, 6, COLOR_BLACK);

	}

	keypad(stdscr, TRUE);
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);

start:

	erase();
	int row,col;
	getmaxyx(stdscr,row,col);
	wborder(stdscr, 0, 0, 0, 0, 0, 0, 0, 0);

	if (color == TRUE)
		attron(COLOR_PAIR(1));

	mvprintw(0, (col-strlen("Stopwatch"))/2, "Stopwatch");

	if (color == TRUE)
		attroff(COLOR_PAIR(1));

	mvprintw(1, (col-strlen("Press 'F1' For Help"))/2, "Press 'F1' For Help");
	mvprintw(2, (col-strlen("Press 'S' To Start Timer"))/2, "Press 'S' To Start Timer");
	mvprintw(3, (col-strlen("Press 'R' To Reset Timer"))/2, "Press 'R' To Reset Timer");
	mvprintw(4, (col-strlen("Press 'E' To Exit"))/2, "Press 'E' To Exit");
	mvprintw(row/2, (col-strlen("00:00:00.00"))/2, "%.2d:%.2d:%.2d.%.2d", hours, minutes, seconds, miliseconds);
	
	if (color == TRUE) 
		attron(COLOR_PAIR(1));

	mvprintw(row-1, (col-strlen("Made By CallMeMarnie"))/2, "Made By CallMeMarnie");

	if (color == TRUE)
		attroff(COLOR_PAIR(1));
	
	refresh();
	int ch = wgetch(stdscr);

	if (ch == KEY_F(1) || ch == 'h') {

		erase();
		int ret = help();

		if (ret == 0)
			goto start;
		else
			exitprop(0);

	} else if (ch == 'e') {

		exitprop(0);

	} else if (ch == 's') {
		
		stopwatch();
		char str[255];
		sprintf(str, "%.2d:%.2d:%.2d.%.2d", hours, minutes, seconds, miliseconds);
		temp(str);
		goto start;

	} else if (ch == 'r') {

		resettime();
		goto start;

	} else {

		goto start;

	}

}
