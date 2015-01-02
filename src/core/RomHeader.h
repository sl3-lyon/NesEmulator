#ifndef NESEMU_ROMHEADER
#define NESEMU_ROMHEADER

struct RomHeader
{
    std::vector<int> bits;
    int PrgRomPagesCount;
    int ChrRomPagesCount;
};

#endif // NESEMU_ROMHEADER
