cmake_minimum_required(VERSION 3.23)
project(WordList)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_STANDARD 14)

add_executable(WordList exceptions.cpp func.cpp readWordFromFile.cpp hasCycle.cpp task2.cpp task3.cpp function.h tool.cpp main.cpp)
