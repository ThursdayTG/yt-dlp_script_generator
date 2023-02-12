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
    std::vector<str> channels = channelList();


    // variables declared outside for-loop to preserve values between iterations
    int scriptsTotal = 0;

          str file = "";
    const str fileType = ".sh";

    const str urlPrefix = "https://www.youtube.com/channel/";
          str urlFull = "";

    namespace sc = script_components;
    const str scriptSegment_1 = sc::scriptSegmentCat_1();
    const str scriptSegment_2 = sc::scriptSegmentCat_2();


    for (std::size_t i = 0; i < channels.size(); i++)
    {
        if (i % 2 == 0)
        {
            // gets channel name from every 1st entry of each pair and uses it for the filename.
            // has to check for even index values because of index 0.
            str fileName = channels.at(i);
            file = fileName + fileType;
        }
        else
        {
            // gets channel URL from every 2nd entry of each pair for the download script
            urlFull = urlPrefix + channels.at(i);

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

    // enabling call of `sleep()` can be helpful when running the program like `./executable && exit` from shell
    bool sleepVariable = true;
    if  (sleepVariable)
    {
        sleep();
    }


    return 0;
}
