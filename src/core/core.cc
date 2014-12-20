#include "core.h"
#include <dirent.h>

/*
 Lecture des ROMs ici
*/

std::vector<std::string> get_roms(const std::string& folder)
{
    DIR *dir;
    struct dirent *ent;
    std::vector<std::string> roms;
    if ((dir = opendir(folder.c_str())) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            std::string rom = ent->d_name;
            const auto ext = rom.substr(rom.size() - 4, rom.size());
            if (ext == ".nes")
            {
                roms.push_back(rom);
            }
        }
        closedir(dir);
        delete ent;
    }
    return roms;
}
