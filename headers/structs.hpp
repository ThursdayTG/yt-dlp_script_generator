#pragma once

#include <string>




struct scriptComponents
{
    const std::string indent = "    ";

          std::string fileName;
    const std::string fileType = ".sh";

          std::string flagAll; //= flagstd::stringing();
    const std::string flagOutput = "--output \"../%(channel)s/%(upload_date>%Y-%m-%d)s ─ %(title)s.%(ext)s\"\\";

    const std::string urlPrefix = "https://www.youtube.com/channel/";
          std::string urlFull;

    const std::string fadeIn     = indent + "░▒▓█";
    const std::string completion = " DOWNLOAD COMPLETED ";
    const std::string fadeOut    = "█▓▒░" + indent;
};
inline scriptComponents sc;
