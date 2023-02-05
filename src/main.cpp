#include <cstdlib>
#include <fstream>
#include <iostream>

#include <string>
#include <vector>

#include "../headers/channelList.hpp"
#include "../headers/flags.hpp"




int main()
{
    using std::string;
    std::vector<string> list = channelList();


    struct generic
    {
        string filetype {".sh"};
        string indentation {"    "};
        string urlYoutube {"https://www.youtube.com/channel/"};
    };
    generic gen;


    string filename;
    string urlComplete;

    for (size_t i = 0; i < list.size(); i++)
    {


        if (i % 2 == 0)
        {
            filename = list.at(i) + gen.filetype;
        }

        if (i % 2 != 0)
        {
            urlComplete = gen.urlYoutube + list.at(i);

            string allflagsconst = flagstring();

            std::ofstream outf{filename};

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
        }
    }

    return 0;
}
