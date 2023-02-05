#include <iostream>
#include <fstream>

#include "../headers/flags.hpp"




int main()
{
    using std::string;
    struct channel
    {
        string channel {"NoCopyrightSounds"};
        string urlChannel {"UC_aEa8K-EOJ3D6gOs7HcyNg"};
    };
    channel NCS;


    struct generic
    {
        string filetype {".sh"};
        string indentation = "    ";
        string urlYoutube {"https://www.youtube.com/channel/"};
    };
    generic gen;

    string filename = NCS.channel + gen.filetype;
    string urlComplete = gen.urlYoutube + NCS.urlChannel;
    string allflagsconst = flagstring();




    using std::ofstream;
    ofstream outf{filename};

    if (!outf)
    {
        return 1;
    }

    using std::endl;
    outf
    << "#!/bin/bash" << endl
    << "\n"
    << "\n"
    << "\n"
    << "\n"
    << "clear" << endl
    << "\n"
    << "\n"
    << "yt-dlp\\" << endl << gen.indentation
    << allflagsconst << endl << gen.indentation
    << "--output \"../%(channel)s/%(upload_date>%Y-%m-%d)s ─ %(title)s.%(ext)s\"\\" << endl << gen.indentation
    << urlComplete << endl
    << "\n"
    << "\n"
    << "echo -e \"\\n\\n\\n    =========================    PROCESS COMPLETED    =========================    \\n\\n\"" << endl;

    return 0;
}
