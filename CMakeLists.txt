cmake_minimum_required(VERSION 3.6)
project(FileSearchEngine)

set(CMAKE_CXX_STANDARD 14)

# source files
file(GLOB_RECURSE engine_src "src/*.cpp")
add_executable(enigine ${engine_src})
