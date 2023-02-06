#include <fstream>
#include <iostream>

#include <string>
#include <vector>

#include <chrono>
#include <thread>

#include "../headers/channelList.hpp"
#include "../headers/flags.hpp"




int main()
{
    using std::string;
    std::vector<string> list = channelList();


    // need to be declared outside the for-loop to preserve values between iterations
    int scriptsTotal = 0;
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
            string newl   = "\n";      // new line, used instead of std::endl
            string indent = "    ";

            string flagAll    = flagstring();
            string flagOutput = "--output \"../%(channel)s/%(upload_date>%Y-%m-%d)s ─ %(title)s.%(ext)s\"\\";

            string urlPrefix = "https://www.youtube.com/channel/";
                   urlFull   = urlPrefix + list.at(i);

            string fadeIn     = "░▒▓█ ", fadeOut = " █▓▒░";
            string completion = "DOWNLOAD COMPLETED";

            std::ofstream filestream{fileName};
            filestream
            << "#!/bin/bash" << newl
            << "\n\n\n\n"
            << "clear" << newl
            << "\n\n"
            << "yt-dlp\\" << newl
            << indent << flagAll    << newl
            << indent << flagOutput << newl
            << indent << urlFull    << newl
            << "\n\n"
            << "echo -e \"\\n\\n\\n"
            << indent << fadeIn << completion << fadeOut << indent
            << "\\n\\n\"" << newl;

            scriptsTotal++;
        }
    }


    std::cout
    << " total scripts written: " << scriptsTotal << "\n"
    << " process finished. exiting ..." << "\n";

    using std::this_thread::sleep_for;
    using std::chrono::milliseconds;
    sleep_for(milliseconds(2000));

    return 0;
}
