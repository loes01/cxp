#include <string>
#include <vector>
#include <filesystem>
#include <ncurses.h>

namespace fs = std::filesystem;

class printing {
    public:
        int selected;
        std::vector<std::string> list;
        void get() {
            for (const auto& entry : fs::directory_iterator(fs::current_path())) {
                list.push_back(entry.path().filename().string() + entry.path().extension().string());
            }
        }
        void print() {
            int i;
            while(list.size() > i, i++) {
                if(i == selected) printw("> %s\n", list[i].c_str());
                else printw("%s\n", list[i].c_str());
            }
        }
};