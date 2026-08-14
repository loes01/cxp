#include <ncurses.h>
#include <string>

class TextModeHandler {
    public:
        void gax() { //Get And Execute
            int key;
            std::string inp;
            key = getch();
            while (key != '\n') {
                inp.push_back(key);
                key = getch();
            }
            //getting part <up>

            //execution part <down>
        }
};