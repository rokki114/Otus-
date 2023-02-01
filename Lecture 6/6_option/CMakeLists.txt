cmake_minimum_required(VERSION 3.12)

project(7_option VERSION 0.0.3)

option(BUILD_EXAMPLES "Whether to build an examples or not." OFF)

add_subdirectory(src)

# "-BUILD_EXAMPLES=1" or "-BUILD_EXAMPLES=0"
if(BUILD_EXAMPLES)
    message("Expmples are enabled by BUILD_EXAMPLES.")
    add_subdirectory(example)
endif()