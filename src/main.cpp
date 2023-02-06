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

    struct scriptComponents
    {
        string fileName;
        string fileType = ".sh";

        string indent = "    ";
        string newl   = "\n";      // new line, used instead of std::endl

        string flagAll    = flagstring();
        string flagOutput = "--output \"../%(channel)s/%(upload_date>%Y-%m-%d)s ─ %(title)s.%(ext)s\"\\";

        string urlPrefix = "https://www.youtube.com/channel/";
        string urlFull;

        string fadeIn     = "░▒▓█ ", fadeOut = " █▓▒░";
        string completion = "DOWNLOAD COMPLETED";
    };

    scriptComponents sc;

    for (std::size_t i = 0; i < list.size(); i++)
    {
        if (i % 2 == 0)
        {
            sc.fileName = list.at(i) + sc.fileType;
        }

        if (i % 2 != 0)
        {
            sc.urlFull = sc.urlPrefix + list.at(i);

            std::ofstream filestream{sc.fileName};
            filestream
            << "#!/bin/bash" << sc.newl
            << "\n\n\n\n"
            << "clear" << sc.newl
            << "\n\n"
            << "yt-dlp\\" << sc.newl
            << sc.indent << sc.flagAll    << sc.newl
            << sc.indent << sc.flagOutput << sc.newl
            << sc.indent << sc.urlFull    << sc.newl
            << "\n\n"
            << "echo -e \"\\n\\n\\n"
            << sc.indent << sc.fadeIn << sc.completion << sc.fadeOut << sc.indent
            << "\\n\\n\"" << sc.newl;

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
