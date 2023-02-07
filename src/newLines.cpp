#include <string>




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
