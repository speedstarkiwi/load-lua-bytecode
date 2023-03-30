# load-lua-bytecode

Loads the lua bytecode with an OK error catcher. Do not use for `luau` purposes!

# how?

If there is an error in loading the bytecode, we print the error message and exit. Otherwise, we call the function using lua_pcall, and then manipulate the results using lua_tostring. 

# example?

```
const char *bytecode = ...; 
size_t bytecode_size = ...; // size 
const char *chunkname = "axon"; 
const char *mode = "b"; 
int error = lua_load(L, (const unsigned char *) bytecode, bytecode_size, chunkname, mode);//get error
```
