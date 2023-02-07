#include <fstream>
#include <iostream>

#include <string>
#include <vector>

#include "../headers/channelList.hpp"
#include "../headers/scriptComponents.hpp"
#include "../headers/sleep.hpp"




int main()
{
    using str = std::string;
    std::vector<str> list = channelList();


    // variables declared outside for-loop to preserve values between iterations
    int scriptsTotal = 0;

    str file = "";
    const str fileType = ".sh";

    const str urlPrefix = "https://www.youtube.com/channel/";
    str urlFull = "";

    namespace sc = script_components;
    const str scriptSegment_1 = sc::scriptSegmentCat_1();
    const str scriptSegment_2 = sc::scriptSegmentCat_2();


    for (std::size_t i = 0; i < list.size(); i++)
    {
        if (i % 2 == 0)
        {
            str fileName = list.at(i);
            file = fileName + fileType;
        }

        if (i % 2 != 0)
        {
            urlFull = urlPrefix + list.at(i);

            std::ofstream filestreamOutput{file};
            filestreamOutput
            << scriptSegment_1
            << urlFull
            << scriptSegment_2;

            scriptsTotal++;
        }
    }


    std::cout
    << " total scripts written: " << scriptsTotal << sc::newl()
    << " process finished. exiting ..." << sc::newl();

    bool sleepv = true;
    if (sleepv)
    {
        sleep();
    }


    return 0;
}
