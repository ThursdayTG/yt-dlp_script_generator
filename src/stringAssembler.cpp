#include <fstream>
#include <iostream>

#include <string>
#include <vector>

#include "../headers/channelList.hpp"
#include "../headers/structs.hpp"




using std::string;

static const string indent = "    ";




string assembleScriptName(channel c)
{
    string fileName = c.name;
    string fileNameSeparator = " | ";

    if (!c.genre.empty())
    {
        fileName += fileNameSeparator + c.genre;
    }

    string fileExtension = ".sh";
    fileName += fileExtension;


    return fileName;
}


string assembleFlags(channel c)
{
    std::vector<string> flagList
    {
        "",
        "--console-title",
        "--concurrent-fragments 30",
        "--fragment-retries 1000",
        "--retries 1000",
        "--verbose",
        "",
        "--continue",
        "--embed-thumbnail",
        "--part",
        "--yes-playlist",
        "",
        "--extract-audio",
        "--audio-format mp3",
        "",
        "--output"
    };


    string flagString = indent;
    string newl = "\\\n" + indent;


    if (c.overwrite)
    {
        flagString += "--force-overwrites";
    }
    else
    {
        flagString += "--no-overwrites";
    }


    for (std::size_t i = 0; i < flagList.size(); i++)
    {

        if (flagList[i].empty())
        {
            flagString += newl;
        }
        else
        {
            if (!flagList[i-1].empty())
            {
                flagString += " ";
            }

            flagString += flagList[i];
        }
    }
    flagString += " ";


    return flagString;
}


string assembleOutput(channel c)
{
    string preface = "\"";

    string directory = "../" + c.name;
    if (!c.notes.empty())
    {
        directory += " (" + c.notes + ")";
    }
    if (!c.genre.empty())
    {
        directory += " | " + c.genre;
    }
    directory += "/";

    string filename = "%(upload_date>%Y-%m-%d)s ─ %(title)s.%(ext)s";
    string postface = "\"\\";

    string output = preface + directory + filename + postface;


    return output;
}


string assembleUrl(channel c)
{
    string urlPrefix = "https://www.youtube.com/channel/";
    string urlFull   = indent + urlPrefix + c.id;


    return urlFull;
}


string assembleCompletionMessage()
{
    string preface  = "\\n\\n\\n";
    string fadeIn   = "░▒▓█ ";
    string fadeOut  = " █▓▒░";
    string text     = "DOWNLOAD COMPLETED";
    string postface = "\\n\\n";

    string message = preface + indent + fadeIn + text + fadeOut + indent + postface;


    return message;
}
