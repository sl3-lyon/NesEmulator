#include <exception>
#include <iostream>
#include "graphics/graphics.h"
#include "cpu/cpu.h"
#include "tools/tools.h"
#include "core/RomReader.h"

#ifdef LUA_OK
extern "C"
{
    #include "lua.h"
    #include "lauxlib.h"
    #include "lualib.h"
}
#endif

// #$ => value
// $  => value in memory address

int main()
{
    //if (DEBUG) std::cout << "Debug mode" << std::endl;
    // Exemple
    int bin = 0b0010'1100'1101'0001; // 11100011 00101100 11010001
    // bin est un exemple de code binaire après lecture de la ROM
#ifdef DEBUG
    std::cout << "compilation done!" << std::endl;
#endif
    while (bin)
    {
        int opcode = bin & 0xff;
        bin >>= 8;
        switch (opcode)
        {
            case 0x00:
                return 0; // BRK instruction
                break;
                
            case 0x01:
                // ...
                break;
                
            case 0x30:
                // BPL $           ; Goto $ while X is not -1.
                break;
                
            case 0x4c:
            case 0x6c:
                // JMP #$1 #$2     ; Jump #$2#$1 (little-endiant)
                break;
                
            case 0x95:
                // STA $, X        ; Store A into $ offset with X.
                break;
                
            case 0xa2:
                // LDX #$
                break;
                
            case 0x0a:
                //ASL();
                break;
                
            case 0xa5:
                // LDA $
                break;
                
            case 0xa9:
                // LDA #$
                break;
                
            case 0xaa:
                //TAX();
                break;

            case 0xad:
                // LDA A, $ (avec value sur 2 octets)
                break;
                
            case 0xca:
                // DEX (decrement X)
                break;
                
            case 0xff:
                // ...
                break;
            default:
                break;
        }
    }
#ifdef LUA_OK
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, "test.lua");
    lua_close(L);
#endif
    graphics::show();
    return 0;
}
