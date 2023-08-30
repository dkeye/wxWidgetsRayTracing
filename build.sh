#!/usr/bin/fish
g++ --std=c++17 (wx-config --cxxflags --libs | string trim | string split " ") -c -o main.o main.cpp &&
g++ --std=c++17 (wx-config --cxxflags --libs | string trim | string split " ") -c -o Camera.o Camera.cpp &&
g++ --std=c++17 (wx-config --cxxflags --libs | string trim | string split " ") -c -o Geometry.o Geometry.cpp &&
g++ --std=c++17 (wx-config --cxxflags --libs | string trim | string split " ") -c -o RayTracingUtils.o RayTracingUtils.cpp &&
g++ --std=c++17 (wx-config --cxxflags --libs | string trim | string split " ") -c -o Vector3d.o Vector3d.cpp &&

g++ --std=c++17 (wx-config --cxxflags --libs | string trim | string split " ") -o MyApp main.o Camera.o Geometry.o RayTracingUtils.o Vector3d.o
