#include <ncurses.h>
#include <string>

class TextModeHandler {
    public:
        void gax() { //Get And Execute
            int key;
            std::string inp;
            key = getch();
            while (key != '\n') {
                if(inp.size() != 0 && key == KEY_BACKSPACE) {
                    inp.pop_back();
                }else {
                    inp.push_back(key);
                }
                erase();
                mvprintw(0, 0, "%s", inp.c_str());
                refresh();
                key = getch();
            }
            printw("\n");
            //getting part <up>

            //execution part <down>
            if(inp.starts_with("go ")) {
                inp.erase(0, 3);
                printw("%s", inp.c_str());
                refresh();
                getch();
            }
        }
};