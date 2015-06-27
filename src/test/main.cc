#include "noncopyable.h"
#include "cpu.h"

#include <lua.hpp>

int main() {
	lua_State *L = luaL_newstate(); //lua_open();
	luaL_openlibs(L);
	luaL_dostring(L, "print('lol')");
}
