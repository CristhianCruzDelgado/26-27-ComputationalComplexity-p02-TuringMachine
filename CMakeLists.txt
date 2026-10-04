cmake_minimum_required(VERSION 3.10)

project(ComputationalComplexity-p02-TuringMachine)

file(GLOB_RECURSE SOURCES src/*.cc)

# debuging ...
# add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
# add_link_options(-fsanitize=address)

add_executable(turing-machine ${SOURCES})

target_include_directories(turing-machine PRIVATE include)
target_compile_features(turing-machine PRIVATE cxx_std_17)
