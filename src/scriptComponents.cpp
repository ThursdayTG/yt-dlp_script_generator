#include <string>
#include <vector>

#include "../headers/newLines.hpp"




using str = std::string;


str flagstring()
{
    std::vector<str> flags {
    "--force-overwrites\\\n    ",
    "--no-overwrites\\\n    ",

    "--console-title ",
    "--no-continue ",
    "--no-part ",
    "--retries 3 ",

    "--extract-audio --audio-format mp3",
    "\\"
    };


    str allflags;
    for (std::size_t i = 0; i < flags.size(); i++)
    {
        if (i != 0)
        {
            allflags += flags.at(i);
        }
    }
    const str allflagsconst = allflags;


    return allflagsconst;
}


void strings()
{
    struct scriptComponents
    {
        const str indent = "    ";

              str fileName;
        const str fileType = ".sh";

        const str flagAll    = flagstring();
        const str flagOutput = "--output \"../%(channel)s/%(upload_date>%Y-%m-%d)s ─ %(title)s.%(ext)s\"\\";

        const str urlPrefix = "https://www.youtube.com/channel/";
              str urlFull;

        const str fadeIn     = indent + "░▒▓█";
        const str completion = " DOWNLOAD COMPLETED ";
        const str fadeOut    = "█▓▒░" + indent;
    };
    scriptComponents sc;


    const str catFirst
    = "#!/bin/bash" + newl()
    + newl(4)
    + "clear" + newl()
    + newl(2)
    + "yt-dlp\\" + newl()
    + sc.indent + sc.flagAll + newl()
    + sc.indent;

    const str catLast
    = newl()
    + sc.indent + sc.urlFull + newl()
    + newl(2)
    + "echo -e \"\\n\\n\\n"
    + sc.fadeIn + sc.completion + sc.fadeOut
    + "\\n\\n\"" + newl();
}
