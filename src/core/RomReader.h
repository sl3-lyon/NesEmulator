#ifndef NESEMU_ROMREADER
#define NESEMU_ROMREADER

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
    std::map<int, int> map() const;
    RomHeader header() const;
private:
    void read() throw(std::exception);
    bool is_header_ok() const;
    std::map<int, int> mapping_;
    std::ifstream reader_;
    std::vector<int> header_;
};

} // core

#endif
