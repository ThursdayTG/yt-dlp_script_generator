#include <string>
#include <vector>




namespace script_components
{
    using str = std::string;


    str flagAssemblyOther();
    str flagAssemblyOutput();


    // newl -> newLine, used instead of std::endl
    std::string newl();
    // overload for when multiple newlines need to be written in a row
    std::string newl(int newLinesAmount);


    // reminder: line 8: using str = std::string;
    // reminder: cat ─> concatenation (unfortunately not related to felines)
    str scriptSegmentCat_1();
    str scriptSegmentCat_2();
}
