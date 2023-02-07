#!/bin/bash




clang++\
    -O3 -std=c++20\
    -Wall -Wextra -Wpedantic -Wshadow -Werror\
    -fcolor-diagnostics\
    -Wno-unused-variable\
    "../src/main.cpp"\
    "../src/channelList.cpp"\
    "../src/scriptComponents.cpp"\
    "../src/sleep.cpp"\
    -o\
    "../executable"


echo -e "\n\n\n ░▒▓█ COMPILATION ATTEMPT COMPLETED █▓▒░ \n\n"
