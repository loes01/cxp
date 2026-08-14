#include <string>
#include <vector>
#include <filesystem>
#include <ncurses.h>

namespace fs = std::filesystem;

class PrintHandler {
    public:
        int selected = 0;
        std::vector<std::string> list;
        void get() {
            list.clear();
            for (const auto& entry : fs::directory_iterator(fs::current_path())) {
                list.push_back(entry.path().filename().string());
            }
        }
        void print() {
            int i=0;
            while(list.size() > i) {
                if(i == selected) printw("> %s\n", list[i].c_str());
                else printw("%s\n", list[i].c_str());
                i++;
            }
        }
        void changeselected(bool ud) { //up = true | down = false
            if(ud) if(selected == 0) return; else selected--;
            else if(!ud) if(selected == (list.size()-1)) return; else selected++;
        }
};