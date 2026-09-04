#pragma once
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
                if(fs::is_directory(entry.path())) list.push_back("/"+entry.path().filename().string());
                else list.push_back(entry.path().filename().string());
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
            if(list.empty()) return;
            if(ud) {
                if(selected == 0) return;
                selected--;
            } else {
                if(selected == (int)(list.size()-1)) return;
                selected++;
            }
        }
        void changepath(bool tf) {
            if(tf){
                if(list.empty()) return;
                fs::path dir = list[selected];
                if(fs::is_directory(dir)) fs::current_path(dir);
                selected = 0;
            }else {
                fs::current_path("..");
                selected = 0;
            }
        }
};