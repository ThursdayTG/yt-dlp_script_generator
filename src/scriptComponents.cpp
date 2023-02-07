#include <string>
#include <vector>




namespace script_components
{
    using str = std::string;


    str flagAssemblyOther()
    {
        /**
        * I decided to base this function on a vector because of a potentially changing amount of flags,
        * particularly if I ever implement user input. A different solution to this problem may be preferable.
        * Feel free to educate me if that's the case.
        */


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


        // cat ─> concatenation (unfortunately not related to felines)
        str flagsOtherCat;
        for (std::size_t i = 0; i < flagsOther.size(); i++)
        {
            flagsOtherCat += flagsOther.at(i);
        }
        return flagsOtherCat;
    }


    str flagAssemblyOutput()
    {
        /**
        * This function doesn't need to utilise a vector to concatenate all segments of the input used for the
        * output flag, as it consists of a known number of elements that won't have to change at any point in time.
        * If the "directory" variable would have to be changed to go to a specific subdirectory, the value of that
        * variable should be changed to contain the path all the way to whichever subdirectory is desired.
        */


        str flagOutput = "--output";

        const str prefix = "\"";      // must start with `\"`
        const str suffix = "\"\\";    // must  end  with `\"\\`

        str directory = "../%(channel)s";
        str filename  = "/%(upload_date>%Y-%m-%d)s ─ %(title)s.%(ext)s";


        str flagOutputCat = prefix + directory + filename + suffix;

        return flagOutputCat;
    }





    // newl -> newLine, used instead of std::endl
    std::string newl()
    {
        return "\n";
    }


    // overload for when multiple newlines need to be written in a row
    std::string newl(int newLinesAmount)
    {
        std::string newLines = "";
        for (int i = 0; i < newLinesAmount; i++)
        {
            newLines += "\n";
        }
        return newLines;
    }




    // reminder: line 8: using str = std::string;
    // reminder: cat ─> concatenation (unfortunately not related to felines)struct scriptComponents
    std::string fileName;
    std::string fileType = ".sh";

    std::string flagAll; //= flagstd::stringing();
    std::string flagOutput = "--output \"../%(channel)s/%(upload_date>%Y-%m-%d)s ─ %(title)s.%(ext)s\"\\";

    std::string urlPrefix = "https://www.youtube.com/channel/";
    std::string urlFull;


    const std::string indent     = "    ";
    const std::string fadeIn     = indent + "░▒▓█";
    const std::string completion = " DOWNLOAD COMPLETED ";
    const std::string fadeOut    = "█▓▒░" + indent;


    str scriptSegmentCat_1()
    {
        str scriptSegmentCat
            = "#!/bin/bash" + newl()
            + newl(4)
            + "clear" + newl()
            + newl(2)
            + "yt-dlp\\" + newl()
            + indent + flagAssemblyOther() + newl()
            + indent + flagAssemblyOutput() + newl()
            + indent;

        return scriptSegmentCat;
    }


    str scriptSegmentCat_2()
    {
        str scriptSegmentCat
            = newl()
            + newl(2)
            + "echo -e \"\\n\\n\\n"
            + fadeIn + completion + fadeOut
            + "\\n\\n\"" + newl();

        return scriptSegmentCat;
    }
}
