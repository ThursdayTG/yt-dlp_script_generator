#include <fstream>
#include <iostream>

#include <string>
#include <vector>

#include <chrono>
#include <thread>

#include "../headers/channelList.hpp"
#include "../headers/stringAssembler.hpp"
#include "../headers/structs.hpp"




int main()
{
    std::vector<channel> list = channelList();


    int filesWrittenTo = 0;

    for (channel& c : list)
    {
        std::ofstream fs;
        fs.open(assembleScriptName(c));
        fs << "#!/bin/bash\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "clear\n"
        "\n"
        "\n"
        "yt-dlp\\\n"
        << assembleFlags(c) << assembleOutput(c) << "\n"
        << assembleUrl(c) << "\n"
        "\n"
        "\n"
        << "echo -e \"" << assembleCompletionMessage() << "\"\n";
        fs.close();

        filesWrittenTo++;
    }


    std::cout
    << "number of scripts created or updated: " << filesWrittenTo << "\n"
    << "process finished. exiting ..." << "\n";

    using std::this_thread::sleep_for;
    using namespace std::chrono_literals;
    sleep_for(1000ms);


    return 0;
}
