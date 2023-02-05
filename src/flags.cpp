#include <string>
#include <vector>




using std::string;

string flagstring()
{
    std::vector<string> flags {
    "--force-overwrites\\\n    ",
    "--no-overwrites\\\n    ",

    "--console-title ",
    "--no-continue ",
    "--no-part ",
    "--retries 3 ",

    "--extract-audio --audio-format mp3",
    "\\"
    };


    string allflags;
    for (size_t i = 0; i < flags.size(); i++)
    {
        if (i != 0)
        {
            allflags += flags.at(i);
        }
    }
    const string allflagsconst = allflags;


    return allflagsconst;
}
