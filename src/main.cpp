#include <fstream>
#include <iostream>

#include <string>
#include <vector>

#include "../headers/channelList.hpp"
#include "../headers/flags.hpp"




int main()
{
    using std::string;

    std::vector <std::string> channels;
    channelList(&channels);


    struct generic
    {
        string filetype {".sh"};
        string indentation {"    "};
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
    << "--output \"../%%(channel)s/%%(upload_date>%%Y-%%m-%%d)s ─ %%(title)s.%%(ext)s\"\\" << endl << gen.indentation
    << urlComplete << endl
    << "\n"
    << "\n"
    << "echo -e \"\\n\\n\\n    =========================    PROCESS COMPLETED    =========================    \\n\\n\"" << endl;

    return 0;
}
