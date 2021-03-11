cmake_minimum_required(VERSION 3.17)
project(Random_Commit)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS " -static")

add_executable(Random_Commit
        src/main.cpp src/messages.h)
