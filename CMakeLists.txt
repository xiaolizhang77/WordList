cmake_minimum_required(VERSION 3.23)
project(WordList)
#set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
#可执行文件
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 设置 .exe 文件的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# 设置 .dll 文件的输出目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

#未知
#include_directories(src src/api src/function src/output src/exceptions)

ADD_SUBDIRECTORY(src)
# 添加test子目录
ADD_SUBDIRECTORY(test)

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

#add_subdirectory(googletest)
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

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


set_target_properties(MyLibrary PROPERTIES OUTPUT_NAME "word_list")

ADD_EXECUTABLE(word_list ./src/main.cpp)

target_link_libraries(word_list api exceptions function output)

target_link_libraries(word_list MyLibrary)