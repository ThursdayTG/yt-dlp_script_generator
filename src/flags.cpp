#include <vector>
#include <string>




std::string flagstring()
{
    std::vector <std::string> flags {
    "--force-overwrites\\\n    ",
    "--no-overwrites\\\n    ",

    "--console-title ",
    "--no-continue ",
    "--no-part ",
    "--retries 3 ",
    "--extract-audio ",
    "--audio-format mp3",
    "\\"
    };


    std::string allflags;
    for (int i = 0; i < flags.size(); i++)
    {
        if (i != 0)
        {
            allflags += flags.at(i);
        }
    }
    const std::string allflagsconst = allflags;


    return allflagsconst;
}
