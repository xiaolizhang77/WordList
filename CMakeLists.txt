cmake_minimum_required(VERSION 3.23)
project(WordList)
#set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_STANDARD 14)

#静态库
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#动态库
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#可执行文件
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#未知
#include_directories(src src/api src/function src/output src/exceptions)

ADD_SUBDIRECTORY(src)

#add_library(api_api SHARED
#        src/api/api.cpp
#        src/function/func.cpp
#        src/function/hasCycle.cpp
#        src/function/readWordFromFile.cpp
#        src/function/tool.cpp
#        src/function/task3.cpp
#        src/function/task2.cpp
#        src/function/task1.cpp
#        src/function/withRing.cpp
#        )

add_library(MyLibrary SHARED
        src/api/api.cpp
        src/exceptions/exceptions.cpp
        src/output/output.cpp
        src/function/func.cpp
        src/function/hasCycle.cpp
        src/function/readWordFromFile.cpp
        src/function/tool.cpp
        src/function/task3.cpp
        src/function/task2.cpp
        src/function/task1.cpp
        src/function/withRing.cpp
        )

ADD_EXECUTABLE(WordList ./src/main.cpp)

target_link_libraries(WordList api exceptions function output)