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


    // need to be declared outside the for-loop to preserve their values between iterations
    string fileName;
    string urlFull;

    for (std::size_t i = 0; i < list.size(); i++)
    {
        if (i % 2 == 0)
        {
            string fileType = ".sh";
            fileName = list.at(i) + fileType;
        }

        if (i % 2 != 0)
        {
            string indent     = "    ";
            string fadeIn     = "░▒▓█ ";
            string fadeOut    = " █▓▒░";
            string completion = "DOWNLOAD COMPLETED";

            string flagAll    = flagstring();
            string flagOutput = "--output \"../%(channel)s/%(upload_date>%Y-%m-%d)s ─ %(title)s.%(ext)s\"\\";

            string urlPrefix = "https://www.youtube.com/channel/";
                   urlFull   = urlPrefix + list.at(i);

            std::ofstream outf {fileName};
            using std::endl;
            outf
            << "#!/bin/bash" << endl
            << "\n\n\n\n"
            << "clear" << endl
            << "\n\n"
            << "yt-dlp\\" << endl
            << indent << flagAll    << endl
            << indent << flagOutput << endl
            << indent << urlFull    << endl
            << "\n\n"
            << "echo -e \"\\n\\n\\n"
            << indent << fadeIn << completion << fadeOut << indent
            << "\\n\\n\"" << endl;
        }
    }

    return 0;
}
