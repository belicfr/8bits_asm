cmake_minimum_required(VERSION 3.24)
project(8bits_asm)

set(CMAKE_CXX_STANDARD 14)

include_directories(core)

add_executable(8bits_asm
        core/Prompt.h
        main.cpp core/Assembly.h
        core/Processor.h)
