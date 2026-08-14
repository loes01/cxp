#include <iostream>
#include <ncurses.h>
#include "handlers/print.hpp"

int main() {
    PrintHandler printsys;
    initscr();
    noecho();
    cbreak(); 
    keypad(stdscr, TRUE);
    printsys.get();
    printsys.print();
    refresh();
    while(true) {
        int key = getch();
        erase();
        if(key == 'w' || key == KEY_UP) printsys.changeselected(true);
        if(key == 's' || key == KEY_DOWN) printsys.changeselected(false);
        if(key == '\n') printsys.changepath(true);
        if(key == KEY_BACKSPACE) printsys.changepath(false);
        printsys.get();
        printsys.print();
        refresh();
    }
    endwin();
}