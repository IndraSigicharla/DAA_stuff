#!/bin/zsh
clang++ -std=c++17 $1/$2.cpp -o $1/$2.out && $1/$2.out
