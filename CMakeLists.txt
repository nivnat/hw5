cmake_minimum_required(VERSION 3.6)
project(hw5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ColoredGraph.h Color.h Vertex.h Edge.h ColoredGraphB.cpp StreamPrint.cpp Vertex.cpp)
add_executable(hw5 ${SOURCE_FILES})