#ifndef NESEMU_ROMREADER
#define NESEMU_ROMREADER

#include <array>   // std::array
#include <fstream> // std::ifstream
#include <map>     // std::map
#include <string>  // std::string
#include <vector>  // std::vector

#include "RomHeader.h"

namespace core {

class RomReader
{
public:
    explicit RomReader(const std::string& filename);
    std::map<unsigned, unsigned> map() const;
    RomHeader header() const;
private:
    void read() throw(std::exception);
    bool is_header_ok() const;
    std::map<unsigned, unsigned> mapping_;
    std::ifstream reader_;
    std::array<unsigned, 16> header_;
};

} // core

#endif
