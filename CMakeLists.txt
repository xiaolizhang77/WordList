cmake_minimum_required(VERSION 3.23)
project(WordList)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES(./ ./src ./src/api ./src/exceptions ./src/function ./src/output)
ADD_SUBDIRECTORY(./src)
ADD_EXECUTABLE(WordList ./src/main.cpp)
TARGET_LINK_LIBRARIES(WordList api exceptions function output)