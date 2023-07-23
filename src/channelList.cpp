#include <string>
#include <vector>

#include "../headers/structs.hpp"




std::vector<channel> channelList()
{
    std::vector<channel> list;


    list.push_back(channel{
        .name  = "NoCopyrightSounds",
        .notes = "",
        .genre = "",
        .id    = "UC_aEa8K-EOJ3D6gOs7HcyNg",
        .overwrite = false
    });


    return list;
}
