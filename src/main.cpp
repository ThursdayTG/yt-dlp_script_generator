#include <iostream>
#include <fstream>




int main()
{
    using std::ofstream;
    ofstream outf{"NoCopyrightSounds.sh"};

    if (!outf)
    {
        return 1;
    }
    else
    {
        using std::endl;
        outf << "#!/bin/bash" << endl;
        outf << "\n";
        outf << "\n";
        outf << "\n";
        outf << "\n";
        outf << "clear" << endl;
        outf << "\n";
        outf << "\n";
        outf << "yt-dlp\\" << endl;
        outf << "    --console-title --no-continue --force-overwrites --no-part --retries 3 --extract-audio --audio-format mp3\\" << endl;
        outf << "    --output \"../%(channel)s/%(upload_date>%Y-%m-%d)s ─ %(title)s.%(ext)s\"\\" << endl;
        outf << "    https://www.youtube.com/channel/UC_aEa8K-EOJ3D6gOs7HcyNg";
        outf << "\n";
        outf << "\n";
        outf << "echo -e \"\\n\\n\\n    =========================    PROCESS COMPLETED    =========================    \\n\\n\"" << endl;
    }

    return 0;
}
