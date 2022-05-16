cmake_minimum_required(VERSION 3.8)
project(SpreadsheetCell)

set(CMAKE_CXX_STANDARD 17)

add_executable(SpreadsheetCell main.cpp IntCell.cpp DoubleCell.cpp StringCell.cpp)