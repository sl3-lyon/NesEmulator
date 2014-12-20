#ifndef CORE_H
#define CORE_H

#include "MultiMemoryController.h"
#include "RomReader.h"

#include <string> // std::string
#include <vector> // std::vector

std::vector<std::string> get_roms(const std::string& folder = "roms/");

#endif // CORE_H
