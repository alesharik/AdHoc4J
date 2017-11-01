cmake_minimum_required(VERSION 3.7.2)

set(LANGUAGE CXX)
project(adhoc4j)

SET(CMAKE_SYSTEM_NAME Windows)

SET(CMAKE_C_COMPILER i686-w64-mingw32-gcc)
SET(CMAKE_CXX_COMPILER i686-w64-mingw32-g++)
SET(CMAKE_RC_COMPILER i686-w64-mingw32-windres)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})

if (WIN32)
    set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
    set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")
endif ()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Utils.h Utils.cpp AdHocNetwork.cpp AdHocInterface.cpp AdHocManager.cpp)

add_library(adhoc4j SHARED ${SOURCE_FILES})
include_directories(.)
if (WIN32)
#    include_directories($ENV{JAVA_HOME}/include/win32)
endif ()
if (UNIX)
    include_directories(include)
#    include_directories($ENV{JAVA_HOME}/include/linux)
    target_include_directories(adhoc4j PRIVATE include)
endif ()
if (UNIX)
    target_link_libraries(adhoc4j ole32 oleaut32)
endif ()
if (WIN32)
    target_link_libraries(adhoc4j)
endif ()
