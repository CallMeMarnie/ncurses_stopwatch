#include "functions.h"

int miliseconds = 0;
int seconds = 0;
int minutes = 0;
int hours = 0;
bool color = true;

int help(void) {

cont:
	erase();
	int row, col;
	getmaxyx(stdscr,row,col);
	wborder(stdscr, 0, 0, 0, 0, 0, 0, 0, 0);
	
	if (color == TRUE) 
		attron(COLOR_PAIR(1));

	mvprintw(0, (col-strlen("Stopwatch Help"))/2, "Stopwatch Help");

	if (color == TRUE) 
		attroff(COLOR_PAIR(1));
		
	mvprintw(1, (col-strlen("Press 'S' To Pause Or Unpause. Press 'E' to Exit."))/2, "Press 'S' To Pause Or Unpause. Press 'E' to Exit.");
	mvprintw(2, (col-strlen("Press 'R' To Reset The Timer"))/2, "Press 'R' To Reset The Timer");
	mvprintw(3, (col-strlen("Press 'F1' To Go Back."))/2, "Press 'F1' To Go Back.");
	mvprintw(4, (col-strlen("Logs Are Saved in ./.stopwatch.log"))/2, "Logs Are Saved in ./.stopwatch.log");
	mvprintw(row/2, (col-strlen("00:00:00.00"))/2, "%.2d:%.2d:%.2d.%.2d", hours, minutes, seconds, miliseconds);
	
	if (color == TRUE) 
		attron(COLOR_PAIR(1));

	mvprintw(row-1, (col-strlen("Made By CallMeMarnie"))/2, "Made By CallMeMarnie");

	if (color == TRUE)
		attroff(COLOR_PAIR(1));

	refresh();
	int ch = wgetch(stdscr);

	if (ch == KEY_F(1) || ch == 'h') 
		return 0;
	else if (ch == 'e')
		return 1;
	else
		goto cont;

}

int stopwatch(void) {

	while (1 == 1) {

		int ch = wgetch(stdscr);

		if (ch == 's')
			break;
		else if (ch == 'e')
			exitprop(0);

		int row, col;
		getmaxyx(stdscr,row,col);
		erase();

		if (miliseconds >= 100) {

			miliseconds = 0;
			seconds++;

		}
		
		if (seconds >= 60) {

			seconds = 0;
			minutes++;

		}

		if (minutes >= 60) {
	
			minutes = 0;
			hours++;

		}
		
		int y, x;
		getyx(stdscr, y, x);

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
		usleep(10000);
		miliseconds++;

	}

	return 0;

}

void resettime(void) {

	miliseconds = 0;
	seconds = 0;
	minutes = 0;
	hours = 0;

}

void exitprop(int code) {

	endwin();
	exit(code);

}

void inthandler(int dummy) {
	
	endwin();
	exit(130);

}

void temp(char *str) {
    
	char *tmp = "./.stopwatch.log";
	FILE *ptr = fopen(tmp, "a");
	time_t t = time(NULL);
    char *curr = strtok(ctime(&t), "\n");
	fprintf(ptr, "%s: %s\n", curr, str);
	fclose(ptr);

}

void segvhandler(int dummy) {

	temp("SEGV Occurred");
	endwin();
	exit(139);

}
