#include <string>




using str = std::string;


// newl -> newLine, used instead of std::endl
str newl()
{
    str newLines = "\n";

    return newLines;
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
