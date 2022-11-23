#ifndef __FUNCTIONS_H

    #define __FUNCTIONS_H

    #ifndef __NCURSES_H

        #include <ncurses.h>

    #endif

    #ifndef _STDLIB_H

        #include <stdlib.h>

    #endif

    #ifndef _UNISTD_H

        #include <unistd.h>

    #endif

    #ifndef _STRING_H

        #include <string.h>

    #endif

    #ifndef _SIGNAL_H

        #include <signal.h>

    #endif

    #ifndef _TIME_H

        #include <time.h>

    #endif

    #ifndef __STDBOOL_H
    
        #include <stdbool.h>

    #endif

    void inthandler(int);
    void exitprop(int);
    void resettime(void);
    int help(void);
    int stopwatch(void);
    void temp(char*);
    void segvhandler(int);

    extern int miliseconds;
    extern int seconds;
    extern int minutes;
    extern int hours;
    extern bool color;

#endif