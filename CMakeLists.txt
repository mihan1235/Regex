cmake_minimum_required(VERSION 3.18)

project(REGEX)

add_library(Dll1Regex SHARED "Dll1Regex/dll1regex.cpp" "Dll1Regex/dll1regex.h")

add_executable(regex Regex/Regex.cpp)
include_directories(Dll1Regex)
target_link_libraries(regex Dll1Regex)

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__linux__")

