//xlua版本的unity初始化第三方插件
#include <lua.h>

int luaopen_lz4(lua_State *L);

LUA_API int Test(int a,int b) {
    return a * b ;
}

LUA_API int initLz4(lua_State *L) {
    int ret = 0;
    return  ret = luaopen_lz4(L);
}
