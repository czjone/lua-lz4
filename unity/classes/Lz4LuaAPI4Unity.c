//xlua版本的unity初始化第三方插件
#include <lua.h>

LUA_API int luaopen_lz4(lua_State *L);

LUA_API int Test(int a,int b) {
    return a * b ;
}

LUA_API int addA(int a,int b){
    return a + b;
}

LUA_API int initLz4(lua_State *L) {
    return luaopen_lz4(L);
}
