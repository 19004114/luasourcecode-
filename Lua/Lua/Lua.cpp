#include <iostream>
#include <string>
extern "C" {
#include "lua4/include/lua.h"
#include "lua4/include/lauxlib.h"
#include "lua4/include/lualib.h"
}

void runF1() {
    lua_State* L = lua_open(0);
    lua_baselibopen(L);
    lua_strlibopen(L);
    lua_mathlibopen(L);
    lua_iolibopen(L);
    lua_dofile(L, "D:\\luaex\\Bai1.lua");
    lua_getglobal(L, "Main");
    lua_call(L, 0, 0);
    lua_close(L);
}

void runF2() {
    lua_State* L = lua_open(0);
    lua_baselibopen(L);
    lua_strlibopen(L);
    lua_mathlibopen(L);
    lua_iolibopen(L);
    lua_dofile(L, "D:\\luaex\\Bai2.lua");
    lua_getglobal(L, "Main");
    lua_call(L, 0, 0);
    lua_close(L);
}

int ktsnt(lua_State* L);

int main()
{
    runF1();
    runF2();

    lua_State* L = lua_open(0);
    lua_baselibopen(L);
    lua_strlibopen(L);

    lua_pushcfunction(L, ktsnt);
    lua_setglobal(L, "ktsnt");
    lua_dofile(L, "D:\\luaex\\Bai5.lua");
    lua_getglobal(L, "Main");
    lua_call(L, 0, 0);
    return 0;
}

int ktsnt(lua_State* L) {
    int so = lua_tonumber(L, 1);
    if (so > 1) {
        for (int i = 2; i <= so; i++)
            if (so != i)
                if (so % i == 0) {
                    lua_pushnumber(L, 0);
                    return 1;
                }
    }
    lua_pushnumber(L, 1);
    return 1;
}
