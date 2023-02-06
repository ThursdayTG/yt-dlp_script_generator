#include <fstream>
#include <iostream>

#include <string>
#include <vector>

#include <chrono>
#include <thread>

#include "../headers/channelList.hpp"
#include "../headers/flags.hpp"
#include "../headers/newLines.hpp"




int main()
{
    using str = std::string;
    std::vector<str> list = channelList();


    // need to be declared outside the for-loop to preserve values between iterations
    int scriptsTotal = 0;

    struct scriptComponents
    {
        str fileName;
        str fileType = ".sh";

        str indent = "    ";

        str flagAll    = flagstring();
        str flagOutput = "--output \"../%(channel)s/%(upload_date>%Y-%m-%d)s ─ %(title)s.%(ext)s\"\\";

        str urlPrefix = "https://www.youtube.com/channel/";
        str urlFull;

        str fadeIn     = "░▒▓█ ", fadeOut = " █▓▒░";
        str completion = "DOWNLOAD COMPLETED";
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
            << "#!/bin/bash" << newl()
            << newl(4)
            << "clear" << newl()
            << newl(2)
            << "yt-dlp\\" << newl()
            << sc.indent << sc.flagAll    << newl()
            << sc.indent << sc.flagOutput << newl()
            << sc.indent << sc.urlFull    << newl()
            << newl(2)
            << "echo -e \"\\n\\n\\n"
            << sc.indent << sc.fadeIn << sc.completion << sc.fadeOut << sc.indent
            << "\\n\\n\"" << newl();

            scriptsTotal++;
        }
    }


    std::cout
    << " total scripts written: " << scriptsTotal << newl()
    << " process finished. exiting ..." << newl();

    using std::this_thread::sleep_for;
    using std::chrono::milliseconds;
    sleep_for(milliseconds(2000));

    return 0;
}
