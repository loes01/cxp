#pragma once
extern "C" {
    #include <lua5.4/lua.h>
    #include <lua5.4/lualib.h>
    #include <lua5.4/lauxlib.h>
}
#include <cstdlib>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

void executePlugin(std::string pluginname) {
    lua_State* L = luaL_newstate();
    if(!L) return;

    luaL_openlibs(L);

    std::string home = getenv("HOME");

    if(!fs::exists(home + "/.config/cxp/")) {
        fs::create_directory(home + "/.config/cxp");
    }
    if(!fs::exists(home + "/.config/cxp/plugins/")) {
        fs::create_directory(home + "/.config/cxp/plugins");
    }

    std::string file = home + "/.config/cxp/plugins/" + pluginname + "/main.lua";
    if(luaL_dofile(L, file.c_str()) != LUA_OK) {
        lua_close(L);
        return;
    }

    lua_close(L);
    return;
}