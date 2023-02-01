cmake_minimum_required(VERSION 3.12)

project(CMakeExamples)

add_subdirectory(1_basic)
add_subdirectory(2_var_n_config)
add_subdirectory(3_lib)

# Next examples are disabled as they require manual work for a successful build:
# add_subdirectory(4_lib_install)
# add_subdirectory(5_lib_module)
# add_subdirectory(6_option)
# add_subdirectory(7_compile_features)