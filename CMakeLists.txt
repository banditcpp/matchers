cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)

file(GLOB spec_sources specs/*.cpp)
add_executable(specs ${spec_sources})
