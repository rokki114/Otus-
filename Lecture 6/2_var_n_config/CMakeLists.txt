cmake_minimum_required(VERSION 3.12)

# ##############################################################################

# Set default value for PATCH_VERSION, but value could be changed from outside:
# cmake .. -DPATCH_VERSION=111
set(PATCH_VERSION "5" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 2.0.${PATCH_VERSION})

message ("PROJECT_VERSION ${PROJECT_VERSION}!!")
project(2_var_n_config VERSION ${PROJECT_VERSION})

# ##############################################################################

# Using variables in CMake.
# https://cmake.org/cmake/help/latest/command/set.html
# "set" is set, ${} is get.
set(SOURCES
        main.cpp
        answer.cpp
)
set(HEADERS
        answer.h
)

# The same as: add_executable(configure main.cpp version.cpp version.h)
add_executable(configure ${SOURCES} ${HEADERS})

# ##############################################################################

# Configuring project by sending vars into C++ code.
configure_file(
        config.h.in
        ${CMAKE_CURRENT_BINARY_DIR}/sub/config.h
)

target_include_directories(
        configure
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}/sub
)

# ##############################################################################
#
target_compile_features(configure PUBLIC cxx_std_17)
set_target_properties(configure PROPERTIES CXX_STANDARD_REQUIRED ON)

if(MSVC)
        target_compile_options(configure PUBLIC /W4 /WX)
else()
        target_compile_options(configure PUBLIC -Wall -Wextra -Werror -pedantic)
endif()