#include "RomReader.h"
#include "../tools/NesemuException.h"

using namespace core;

RomReader::RomReader(const std::string & filename)
    : reader_(filename, std::ios::in | std::ios::binary), header_(0)
{
    if (!reader_)
    {
        std::string message { "Cannot open " + filename };
        throw tools::NesemuException(message);
    }
    read();
}

std::map<int, int> RomReader::map() const
{
    return mapping_;
}

RomHeader RomReader::header() const
{
    RomHeader header;
    header.bits = header_;
    return header;
}

void RomReader::read() throw(std::exception)
{
    int address {};
    while (reader_)
    {
        mapping_.insert(std::pair<int, int>(address, reader_.get()));
        address++;
    }
    for (auto& map : mapping_)
    {
        header_.push_back(map.second);
        if (map.first == 15)
        {
            break;
        }
    }
    if (!is_header_ok())
    {
        throw tools::NesemuException { "Bad ROM header" };
    }
}

bool RomReader::is_header_ok() const
{
    /*
    The format of the header is as follows:
    0-3: Constant $4E $45 $53 $1A ("NES" followed by MS-DOS end-of-file)
    4: Size of PRG ROM in 16 KB units
    5: Size of CHR ROM in 8 KB units (Value 0 means the board uses CHR RAM)
    6: Flags 6
    7: Flags 7
    8: Size of PRG RAM in 8 KB units (Value 0 infers 8 KB for compatibility; see PRG RAM circuit)
    9: Flags 9
    10: Flags 10 (unofficial)
    11-15: Zero filled
    */
    if (header_.size() != 16)
    {
        return false;
    }
    // ...
    return (header_[0] == 'N' && header_[1] == 'E' && header_[2] == 'S' && header_[3] == 0x1a);
}

