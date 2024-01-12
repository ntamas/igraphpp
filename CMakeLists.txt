cmake_minimum_required(VERSION 3.5)

#####################################################################
# General project properties
#####################################################################

project(igraphpp C CXX)

#####################################################################
# Build options
#####################################################################

#####################################################################
# Version information
#####################################################################

#####################################################################
# Tweaking CMake
#####################################################################

#####################################################################
# Find dependencies
#####################################################################

find_package(igraph REQUIRED)

#####################################################################
# Compiler flags for different build configurations
#####################################################################

set(CMAKE_C_FLAGS   "${CMAKE_ARCH_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_ARCH_FLAGS} -Wall")
set(CMAKE_C_FLAGS_DEBUG   "${CMAKE_ARCH_FLAGS} -O0 -ggdb")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_ARCH_FLAGS} -O0 -ggdb")
set(CMAKE_C_FLAGS_RELEASE   "${CMAKE_ARCH_FLAGS} -O3 -DNDEBUG -Wall -s")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_ARCH_FLAGS} -O3 -DNDEBUG -Wall -s")
set(CMAKE_C_FLAGS_PROFILING "${CMAKE_ARCH_FLAGS} -pg")
set(CMAKE_CXX_FLAGS_PROFILING "${CMAKE_ARCH_FLAGS} -pg")

#####################################################################
# Process subdirectories
#####################################################################

add_subdirectory(src)
