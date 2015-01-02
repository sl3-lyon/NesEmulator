#ifndef NESEMU_ROMHEADER
#define NESEMU_ROMHEADER

#include <array>  // std::array
#include <vector> // std::vector

enum TvSystem { Ntsc, Pal };

struct RomHeader
{
    std::vector<int> bits;
    std::array<int, 1fff> sram;
    //int PrgRomPagesCount;
    //int ChrRomPagesCount;
};

#endif // NESEMU_ROMHEADER
