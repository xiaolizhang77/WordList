cmake_minimum_required(VERSION 3.23)
project(WordList)
#set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ./CMakeDir/bin)

add_library(MyLibrary SHARED
        exceptions.cpp
        exceptions.h
        func.cpp
        function.h
        hasCycle.cpp
        main.cpp
        readWordFromFile.cpp
        task1.cpp
        task2.cpp
        task3.cpp
        task6.cpp
        tool.cpp
        api.cpp
        )

add_executable(WordList
        exceptions.cpp
        func.cpp
        readWordFromFile.cpp
        hasCycle.cpp
        task1.cpp
        task6.cpp
        task2.cpp
        task3.cpp
        function.h
        tool.cpp
        main.cpp
        api.cpp
        )
#add_executable(WordList main.cpp)
target_link_libraries(WordList MyLibrary)
