#include <iostream>
#include <ncurses.h>
#include "handlers/print.hpp"
#include "handlers/mode.hpp"

int main() {
    PrintHandler printsys;
    TextModeHandler txtmodesys;
    initscr();
    noecho();
    cbreak(); 
    keypad(stdscr, TRUE);
    printsys.get();
    printsys.print();
    refresh();
    int mode = 1;
    while(true) {
        if(mode == 0) {
            int key = getch();
            erase();
            if(key == 'w' || key == KEY_UP) printsys.changeselected(true);
            if(key == 's' || key == KEY_DOWN) printsys.changeselected(false);
            if(key == '\n') printsys.changepath(true);
            if(key == KEY_BACKSPACE) printsys.changepath(false);
            printsys.get();
            printsys.print();
            refresh();
        }else if (mode == 1) {
            erase();
            txtmodesys.gax();
            refresh();
            break;
        }
    }
    endwin();
}