#include <string>
#include <vector>




namespace script_components
{
    using str = std::string;


    /**
    * `flagAssemblyOutput()` doesn't need a vector to concatenate all segments of the input used for the
    * output flag, because its number of elements doesn't have to change at any point in time.
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
            flagsOther.push_back("--force-overwrites");
        }
        else
        {
            flagsOther.push_back("--no-overwrites");
        }
        flagsOther.push_back("\\\n   ");


        std::vector<str> flagsOtherList {
            "--console-title",
            "--no-continue",
            "--no-part",
            "--retries 3",
            "--extract-audio",
            "--audio-format mp3",
        };
        for (const auto& flag : flagsOtherList)
        {
            flagsOther.push_back(" ");
            flagsOther.push_back(flag);
        }
        flagsOther.push_back("\\");


        str flagsOtherCat;
        for (const auto& flag : flagsOther)
        {
            flagsOtherCat += flag;
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


    // used for inserting `\n` sequences into the shellscript itself
    str newlScript()
    {
        return "\\n";
    }


    str newlScript(int newLinesAmount)
    {
        str newLines = "";
        for (int i = 0; i < newLinesAmount; i++)
        {
            newLines += "\\n";
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
            indent, /*urlFull, newl()*/
        };


        str scriptSegmentCat = "";
        for (const auto& snippet : scriptSegment)
        {
            scriptSegmentCat += snippet;
        }

        return scriptSegmentCat;
    }


    str scriptSegmentCat_2()
    {
        std::vector<str> scriptSegment
        {
           /*indent, urlFull,*/ newl(),
           newl(2),
           "echo -e \"", newlScript(3),
           fadeIn, completion, fadeOut,
           newlScript(2), "\"", newl(),
        };


        str scriptSegmentCat = "";
        for (const auto& snippet : scriptSegment)
        {
            scriptSegmentCat += snippet;
        }

        return scriptSegmentCat;
    }
}
