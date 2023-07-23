#pragma once

#include <string>




struct channel
{
    std::string name;
    std::string notes;
    std::string genre;
    std::string id;

    bool overwrite = false;
};
