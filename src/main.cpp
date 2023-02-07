#include <fstream>
#include <iostream>

#include <string>
#include <vector>

#include "../headers/channelList.hpp"
#include "../headers/newLines.hpp"
#include "../headers/scriptComponents.hpp"
#include "../headers/sleep.hpp"
#include "../headers/structs.hpp"




int main()
{
    using str = std::string;
    std::vector<str> list = channelList();


    // need to be declared outside the for-loop to preserve values between iterations
    int scriptsTotal = 0;

    const str scriptSegment_1 = catScriptSegment_1();
    const str scriptSegment_2 = catScriptSegment_2();


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
            << scriptSegment_1
            << sc.urlFull
            << scriptSegment_2;

            scriptsTotal++;
        }
    }


    std::cout
    << " total scripts written: " << scriptsTotal << newl()
    << " process finished. exiting ..." << newl();

    bool sleepv = true;
    if (sleepv)
    {
        sleep();
    }

    return 0;
}
