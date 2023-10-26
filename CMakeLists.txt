cmake_minimum_required(VERSION 3.22)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled exe/main.cpp)

add_library(CurveLibrary SHARED
        lib/curves.cpp lib/Point.cpp
        )

target_include_directories (untitled PUBLIC lib)
target_include_directories (untitled PUBLIC exe)

#find_library(CURVE_LIB CurveLibrary lib)
target_link_libraries(untitled PRIVATE CurveLibrary)