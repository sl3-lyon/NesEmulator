#include "RomHeaderAnalyzer.h"

#include <cassert> // assert

RomHeaderAnalyzer::RomHeaderAnalyzer(const RomHeader& header) : header_(header)
{
    assert(header.bits.size() == 16);
    analyze();
}

RomHeader RomHeaderAnalyzer::header() const
{
    return header_;
}

void RomHeaderAnalyzer::analyze()
{
    auto lowerBits = header_.bits[6] & 0b11110000 >> 4;
    auto upperBits = header_.bits[7] & 0b11110000;
    auto mapperNumber = lowerBits + upperBits;
    header_.mapperNumber = mapperNumber;
    header_.tvSystem = (header_.bits[9] & 1) ?
        TvSystem::Pal :
        TvSystem::Ntsc;
}
