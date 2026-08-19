extern "C" {
    #include <lua5.4/lua.h>
    #include <lua5.4/lualib.h>
    #include <lua5.4/lauxlib.h>
}
#include <string>
#include <cstdlib>

void executePlugin(std::string pluginname) {
    while (!pluginname.empty() && (pluginname.back() == '\r' || pluginname.back() == '\n' || pluginname.back() == ' ')) {
        pluginname.pop_back();
    }

    lua_State* L = luaL_newstate();
    if(!L) return;

    luaL_openlibs(L);

    const char* homeDir = std::getenv("HOME");
    if (!homeDir) {
        lua_close(L);
        return;
    }

    std::string file = std::string(homeDir) + "/.config/cxp/plugins/" + pluginname + "/main.lua";
    if(luaL_dofile(L, file.c_str()) != LUA_OK) {
        lua_close(L);
        return;
    }

    lua_close(L);
    return;
}