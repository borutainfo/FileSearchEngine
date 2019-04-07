cmake_minimum_required(VERSION 3.6)

project(FileSearchEngine)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(src)

# source files
file(GLOB_RECURSE engine_src "src/*.cpp")
add_executable(engine ${engine_src})

# target: engine
target_link_libraries(engine)
