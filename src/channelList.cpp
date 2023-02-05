#include <string>
#include <vector>




void channelList(std::vector <std::string> &channels)
{
    std::vector <std::string> list {
        "NoCopyrightSounds",
        "UC_aEa8K-EOJ3D6gOs7HcyNg",
    };

    for (int i = 0; i < list.size(); i++)
    {
        channels.resize(i + 1);
        channels.at(i) = list.at(i);
    }
}
