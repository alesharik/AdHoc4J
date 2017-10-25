cmake_minimum_required (VERSION 3.7.2)
project (adhoc4j)

set (CMAKE_C_STANDARD 99)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Utils.c AdHocManager.c)

add_library(adhoc4j SHARED ${SOURCE_FILES})

include_directories($ENV{JAVA_HOME}/include)
target_link_libraries(adhoc4j)
