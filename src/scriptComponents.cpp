#include <string>
#include <vector>

#include "../headers/newLines.hpp"
#include "../headers/structs.hpp"




using str = std::string;


str flagstring()
{
    std::vector<str> flags;


    bool overwrite = true;
    if (overwrite)
    {
        flags.push_back("--force-overwrites\\\n   ");
    }
    else
    {
        flags.push_back("--no-overwrites\\\n   ");
    }


    flags.push_back(" --console-title");
    flags.push_back(" --no-continue");
    flags.push_back(" --no-part");
    flags.push_back(" --retries 3");
    flags.push_back(" --extract-audio");
    flags.push_back(" --audio-format mp3");
    flags.push_back("\\");


    // cat -> concatenation (not related to felines)
    str catFlags;
    for (std::size_t i = 0; i < flags.size(); i++)
    {
        catFlags += flags.at(i);
    }
    sc.flagAll = catFlags;


    return sc.flagAll;
}




str catScriptSegment_1()
{
    str scriptSegment_1
    = "#!/bin/bash" + newl()
    + newl(4)
    + "clear" + newl()
    + newl(2)
    + "yt-dlp\\" + newl()
    + sc.indent + flagstring() + newl()
    + sc.indent + sc.flagOutput + newl()
    + sc.indent;

    return scriptSegment_1;
}


str catScriptSegment_2()
{
    str scriptSegment_2
    = newl()
    + newl(2)
    + "echo -e \"\\n\\n\\n"
    + sc.fadeIn + sc.completion + sc.fadeOut
    + "\\n\\n\"" + newl();

    return scriptSegment_2;
}
