#!/usr/bin/fish
g++ -std=c++11 (wx-config --cxxflags --libs | string trim | string split " ") main.cpp -o MyApp