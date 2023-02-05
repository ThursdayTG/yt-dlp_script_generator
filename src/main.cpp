#include <iostream>
#include <fstream>




int main()
{
    using std::string;
    struct script
    {
        string channel {"NoCopyrightSounds"};
        string filetype {".sh"};
        string filename {channel + filetype};

        string indentation = "    ";

        string urlYoutube {"https://www.youtube.com/channel/"};
        string urlChannel {"UC_aEa8K-EOJ3D6gOs7HcyNg"};
        string urlComplete {urlYoutube + urlChannel};
    };


    script NCS;

    using std::ofstream;
    ofstream outf{NCS.filename};

    if (!outf)
    {
        return 1;
    }

    using std::endl;
    outf
    << "#!/bin/bash" << endl
    << "\n"
    << "\n"
    << "\n"
    << "\n"
    << "clear" << endl
    << "\n"
    << "\n"
    << "yt-dlp\\" << endl << NCS.indentation
    << "--console-title --no-continue --force-overwrites --no-part --retries 3 --extract-audio --audio-format mp3\\" << endl << NCS.indentation
    << "--output \"../%(channel)s/%(upload_date>%Y-%m-%d)s ─ %(title)s.%(ext)s\"\\" << endl << NCS.indentation
    << NCS.urlComplete
    << "\n"
    << "\n"
    << "echo -e \"\\n\\n\\n    =========================    PROCESS COMPLETED    =========================    \\n\\n\"" << endl;

    return 0;
}
