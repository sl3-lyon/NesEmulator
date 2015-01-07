#ifndef NESEMU_ROMHEADER
#define NESEMU_ROMHEADER

#include <array>  // std::array
#include <vector> // std::vector

enum TvSystem { Ntsc, Pal };

constexpr int maxPrgBankSize = 16384;
constexpr int maxChrBankSize = 8192;

struct RomHeader
{
    std::array<unsigned, 16> bits;
    std::array<unsigned, 0x1fff> sram;
    int prgRomPagesCount;
    int prgBanksCount;
    int chrRomPagesCount;
    int chrBanksCount;
};

#endif // NESEMU_ROMHEADER
