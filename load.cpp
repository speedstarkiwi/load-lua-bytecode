#include <lua.hpp>

int main() {
    lua_State *L = luaL_newstate(); // create a new Lua state
    luaL_openlibs(L); // load standard Lua libraries

    // assume the bytecode is stored in a buffer named 'bytecode'
    size_t bytecode_size = ...; // the size of the bytecode buffer
    int error = lua_load(L, bytecode, bytecode_size, "mychunk", "b");
    if (error) {
        const char *error_msg = lua_tostring(L, -1);
        // handle the error, e.g. print the error message
        lua_close(L);
        return 1;
    }

    // the bytecode is loaded into a function on top of the stack
    // you can call this function with lua_pcall or lua_call
    int nargs = 0; // number of arguments to the function
    int nresults = 0; // number of results to expect
    error = lua_pcall(L, nargs, nresults, 0);
    if (error) {
        const char *error_msg = lua_tostring(L, -1);
        // handle the error, e.g. print the error message
        lua_close(L);
        return 1;
    }

    // the results of the function are on top of the stack
    // you can manipulate them with lua_to* functions
    // e.g. to get a string result:
    const char *result = lua_tostring(L, -1);
    // do something with the result

    lua_close(L); // free the Lua state
    return 0;
}
