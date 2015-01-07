#ifndef NESEMU_ROMHEADER
#define NESEMU_ROMHEADER

#include <array>  // std::array
#include <vector> // std::vector

enum TvSystem { Ntsc, Pal };

constexpr int maxPrgBankSize = 16384; // bytes
constexpr int maxChrBankSize = 8192;  // bytes

struct RomHeader
{
    std::array<unsigned, 16> bits;
    std::array<unsigned, 0x1fff> sram;
    unsigned prgRomPagesCount;
    unsigned prgBanksCount;
    unsigned chrRomPagesCount;
    unsigned chrBanksCount;
    unsigned mapperNumber;
    TvSystem tvSystem;
};

#endif // NESEMU_ROMHEADER
