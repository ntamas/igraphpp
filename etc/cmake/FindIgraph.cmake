#author Jan Christoph Uhde <jan@uhdejc.com>

cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

if(TARGET igraph)
    return()
endif()

message(STATUS "igraph find module")
message(STATUS "-----------------------------------------")
message(STATUS "forcing igraph path: ${IGRAPH_PATH_FORCE}")
message(STATUS "given igraph path: ${IGRAPH_PATH}")

if(IGRAPH_PATH AND IGRAPH_PATH_FORCE)
    set(libname libigraph.so)
    if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
        set(libname libigraph.dylib)
    endif()

    add_library(igraph SHARED IMPORTED)
    file(MAKE_DIRECTORY ${IGRAPH_PATH}/include)
    target_include_directories(igraph INTERFACE ${IGRAPH_PATH}/include)
    set_property(TARGET igraph PROPERTY IMPORTED_LOCATION ${IGRAPH_PATH}/lib/${libname})
    set(Igraph_FOUND TRUE)
    return()
endif()

include(CMakePushCheckState)
include(FindPackageHandleStandardArgs)

cmake_push_check_state()

if(IGRAPH_PATH)
    set(igraph_no_default_path NO_DEFAULT_PATH)
else()
    set(igraph_no_default_path)
endif()

find_path(Igraph_INCLUDE_DIR igraph.h
    HINTS
        ENV
            IGRPAH_PATH
    PATHS ${IGRAPH_PATH}
    PATH_SUFFIXES igraph
    DOC "Location of the igraph headers"
    ${igraph_no_default_path}
)
mark_as_advanced(Igraph_INCLUDE_DIR)

if(igraph_INCLUDE_DIR STREQUAL igraph_INCLUDE_DIR-NOTFOUNS)
    message(WARNING "could not find igraph includes")
endif()

find_library(Igraph_LIBRARY
    NAMES libigraph.so libigraph.dylib
    HINTS
        ENV
            IGRPAH_PATH
    PATHS ${IGRAPH_PATH}
    PATH_SUFFIXES lib
    DOC "Location of the igraph library"
    ${igraph_no_default_path}
)
mark_as_advanced(Igraph_LIBRARY)

find_package_handle_standard_args(Igraph
    REQUIRED_VARS Igraph_INCLUDE_DIR Igraph_LIBRARY
)


if(Igraph_FOUND)
    add_library(igraph SHARED IMPORTED)
    target_include_directories(igraph INTERFACE ${Igraph_INCLUDE_DIR})
    set_property(TARGET igraph PROPERTY IMPORTED_LOCATION ${Igraph_LIBRARY})
endif()

cmake_pop_check_state()

