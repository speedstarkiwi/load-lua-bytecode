//can load lua bytecode
#include <lua.hpp>
const char* bytecode = "NIGGER";//bytecode
//only luac not luau skid
int main() {
    lua_State *L = luaL_newstate(); // create a new  state
    luaL_openlibs(L); //get em libs

    
    size_t bytecode_size = ...; // the size of the bytecode
    int error = lua_load(L, bytecode, bytecode_size, "Axon", "b");
    if (error) {
        const char *error_msg = lua_tostring(L, -1);
        //TODO: if luau skidsploit then print it out 
        lua_close(L);
        return 1;
    }

    error = lua_pcall(L, 0x0, 0x0, 0);
    if (error) {
        const char *error_msg = lua_tostring(L, -1);
        //TODO: skidsploit must return with getglobal and pushstring
        lua_close(L);
        return 1;
    }

    // the results of the function 
    const char *result = lua_tostring(L, -1);
    //do whatever LOL u got result now

    lua_close(L); // free me
    return 0;
}
