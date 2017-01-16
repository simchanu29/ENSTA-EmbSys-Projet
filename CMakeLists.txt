cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 11)
project(Armadeus-Morse)

# Set up the build directory
set(dir ${CMAKE_CURRENT_SOURCE_DIR}/build/)
set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})
set(CMAKE_BUILD_FILES_DIRECTORY ${dir})
set(CMAKE_BUILD_DIRECTORY ${dir})
set(CMAKE_BINARY_DIR  ${dir})
set(EXECUTABLE_OUTPUT_PATH ${dir})
set(LIBRARY_OUTPUT_PATH ${dir}lib)
set(CMAKE_CACHEFILE_DIR ${dir})

# Cross compilation
# Comment this if not necessary
#set(CMAKE_TOOLCHAIN_FILE Toolschains/armadeus.cmake)


# Compilation of sources
add_subdirectory(src)
