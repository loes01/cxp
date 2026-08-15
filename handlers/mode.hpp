#include <ncurses.h>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

class TextModeHandler {
    public:
        void gax() { //Get And Execute
            int key;
            std::string inp;
            while (true) {
                key = getch();
                if(key == '\n') break;
                if(inp.size() != 0 && key == KEY_BACKSPACE) {
                    inp.pop_back();
                }

                if (key < KEY_MIN) {
                    inp.push_back(key);
                }
                erase();
                mvprintw(0, 0, "%s", inp.c_str());
            }
            //getting part <up>

            //execution part <down>
            if(inp.starts_with("go ")) {
                inp.erase(0, 3);
                fs::current_path(inp);
                erase();
            }
        }
};