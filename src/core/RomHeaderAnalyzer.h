#ifndef NESEMU_ROMHEADERANALYSER
#define NESEMU_ROMHEADERANALYSER

#include "RomHeader.h"

/************************************
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
*************************************/

/************************************
@ Flags 6
76543210
||||||||
||||+||+- 0xx0: vertical arrangement/horizontal mirroring (CIRAM A10 = PPU A11)
|||| ||   0xx1: horizontal arrangement/vertical mirroring (CIRAM A10 = PPU A10)
|||| ||   1xxx: four-screen VRAM
|||| |+-- 1: SRAM in CPU $6000-$7FFF, if present, is battery backed
|||| +--- 1: 512-byte trainer at $7000-$71FF (stored before PRG data)
++++----- Lower nybble of mapper number
*************************************/

/************************************
@ Flags 7
76543210
||||||||
|||||||+- VS Unisystem
||||||+-- PlayChoice-10 (8KB of Hint Screen data stored after CHR data)
||||++--- If equal to 2, flags 8-15 are in NES 2.0 format
++++----- Upper nybble of mapper number
*************************************/

/************************************
@ Flags 9
76543210
||||||||
|||||||+- TV system (0: NTSC; 1: PAL)
+++++++-- Reserved, set to zero
*************************************/

/************************************
@ Flags 10
76543210
  ||  ||
  ||  ++- TV system (0: NTSC; 2: PAL; 1/3: dual compatible)
  |+----- SRAM in CPU $6000-$7FFF is 0: present; 1: not present
  +------ 0: Board has no bus conflicts; 1: Board has bus conflicts
*************************************/

/************************************
// SRAM = Static Random Access Memory
*************************************/

enum TvSystem { Ntsc, Pal };

class RomHeaderAnalyzer
{
public:
    RomHeaderAnalyzer() = delete;
    RomHeaderAnalyzer(const RomHeader& header);
    RomHeader header();
private:
    void analyze();
    RomHeader header_;
};
    
#endif // NESEMU_ROMHEADERANALYSER
