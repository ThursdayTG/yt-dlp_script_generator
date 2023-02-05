#!/bin/bash




clang++\
    -O3 -std=c++20\
    -Wall -Wextra -Wpedantic -Wshadow -Werror\
    -fcolor-diagnostics\
    -Wno-unused-variable\
    "../src/main.cpp"\
    "../src/flags.cpp"\
    -o\
    "../executable"


echo -e "\n\n\n ────[ COMPILATION ATTEMPT FINISHED ]──── \n\n"
