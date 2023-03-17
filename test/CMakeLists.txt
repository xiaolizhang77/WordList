# 设置测试目标名称
set(TEST_TARGET_NAME wordlist_test)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

# 添加测试源文件
set(TEST_SOURCES
        readWordFromFile.cpp
        test_wordlist.cpp
        word_list.h
        )

# 添加可执行文件
add_executable(${TEST_TARGET_NAME} ${TEST_SOURCES})

# 设置测试可执行文件的输出目录
set_target_properties(${TEST_TARGET_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/test
        )

# 包含头文件目录
target_include_directories(${TEST_TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 链接libword_list.dll
find_library(WORD_LIST_LIBRARY NAMES libword_list PATHS ${CMAKE_SOURCE_DIR}/bin)
target_link_libraries(${TEST_TARGET_NAME} PRIVATE MyLibrary)

# 启用C++11标准
target_compile_features(${TEST_TARGET_NAME} PRIVATE cxx_std_11)