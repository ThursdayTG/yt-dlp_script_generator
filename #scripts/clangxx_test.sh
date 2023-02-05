#!/bin/bash




clang++\
    -O0 -std=c++20\
    -Wall -Wextra -Wpedantic -Wshadow\
    -fcolor-diagnostics\
    "../src/main.cpp"\
    "../src/genericFunctions.cpp"\
    -o\
    "../executable_test"


echo -e "\n\n\n ────[ COMPILATION ATTEMPT FINISHED ]──── \n\n"
