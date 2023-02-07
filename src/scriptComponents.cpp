#include <string>
#include <vector>




namespace script_components
{
    using str = std::string;


    /**
    * This particular function doesn't need a vector to concatenate all segments of the input used for the
    * output flag, as it consists of a number of elements that won't have to change at any point in time.
    * If the "directory" variable would have to be changed to go to a specific subdirectory, the value of that
    * variable should be changed to contain the path all the way to whichever subdirectory is desired.
    *
    * Note: cat ─> conCATenation
    */
    str flagAssemblyOutput()
    {
        str flagOutput = "--output";

        const str prefix = "\"";      // must start with `\"`
        const str suffix = "\"\\";    // must  end  with `\"\\`

        str directory = "../%(channel)s";
        str filename  = "/%(upload_date>%Y-%m-%d)s ─ %(title)s.%(ext)s";


        str flagOutputCat = prefix + directory + filename + suffix;

        return flagOutputCat;
    }


    str flagAssemblyOther()
    {
        std::vector<str> flagsOther;

        bool overwrite = true;
        if (overwrite)
        {
            flagsOther.push_back("--force-overwrites\\\n   ");
        }
        else
        {
            flagsOther.push_back("--no-overwrites\\\n   ");
        }

        flagsOther.push_back(" --console-title");
        flagsOther.push_back(" --no-continue");
        flagsOther.push_back(" --no-part");
        flagsOther.push_back(" --retries 3");
        flagsOther.push_back(" --extract-audio");
        flagsOther.push_back(" --audio-format mp3");
        flagsOther.push_back("\\");


        str flagsOtherCat;
        for (std::size_t i = 0; i < flagsOther.size(); i++)
        {
            flagsOtherCat += flagsOther.at(i);
        }

        return flagsOtherCat;
    }




    // newl ─> newLine, used instead of std::endl
    str newl()
    {
        return "\n";
    }


    // overload for when multiple newlines need to be written in a row
    str newl(int newLinesAmount)
    {
        str newLines = "";
        for (int i = 0; i < newLinesAmount; i++)
        {
            newLines += "\n";
        }

        return newLines;
    }




    // reminder: line 9: using str = std::string;
    const str indent     = "    ";
    const str fadeIn     = indent + "░▒▓█";
    const str completion = " DOWNLOAD COMPLETED ";
    const str fadeOut    = "█▓▒░" + indent;


    // reminder: cat ─> conCATenation
    str scriptSegmentCat_1()
    {
        std::vector<str> scriptSegment
        {
            "#!/bin/bash", newl(),
            newl(4),
            "clear", newl(),
            newl(2),
            "yt-dlp\\", newl(),
            indent, flagAssemblyOther(), newl(),
            indent, flagAssemblyOutput(), newl(),
            indent,
        };


        str scriptSegmentCat = "";
        for (std::size_t i = 0; i < scriptSegment.size(); i++)
        {
            scriptSegmentCat += scriptSegment.at(i);
        }

        return scriptSegmentCat;
    }


    str scriptSegmentCat_2()
    {
        std::vector<str> scriptSegment
        {
           newl(),
           newl(2),
           "echo -e \"\\n\\n\\n",
           fadeIn, completion, fadeOut,
           "\\n\\n\"", newl(),
        };


        str scriptSegmentCat = "";
        for (std::size_t i = 0; i < scriptSegment.size(); i++)
        {
            scriptSegmentCat += scriptSegment.at(i);
        }

        return scriptSegmentCat;
    }
}
