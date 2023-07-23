#pragma once

#include <string>

#include "./structs.hpp"




std::string assembleScriptName(channel c);
std::string assembleFlags(channel c);
std::string assembleOutput(channel c);
std::string assembleUrl(channel c);
std::string assembleCompletionMessage();
