AUX_SOURCE_DIRECTORY(. DIR_API_SRCS)
ADD_LIBRARY(api SHARED ${DIR_API_SRCS})

target_link_libraries(api exceptions output function)

#ADD_LIBRARY(api SHARED ${DIR_API_SRCS}
#                ../function/func.cpp
#                ../function/hasCycle.cpp
#                ../function/readWordFromFile.cpp
#                ../function/tool.cpp
#                ../function/task3.cpp
#                ../function/task2.cpp
#                ../function/task1.cpp
#                ../function/withRing.cpp
#        )