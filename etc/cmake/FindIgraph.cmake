#author Jan Christoph Uhde <jan@uhdejc.com>

cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

if(TARGET igraph)
    return()
endif()

message(STATUS "-- FindIgraph.cmake")

if(IGRAPH_PATH})
    message(STATUS "-- IGRAPH_PATH: ${IGRAPH_PATH}")
endif()

if(IGRAPH_PATH)
    set(igraph_no_default_path NO_DEFAULT_PATH)
else()
    set(igraph_no_default_path)
endif()

include(CMakePushCheckState)
cmake_push_check_state()

find_path(Igraph_INCLUDE_DIR igraph.h
    HINTS
        ENV
            IGRPAH_PATH
    PATHS ${IGRAPH_PATH}
    PATH_SUFFIXES igraph
    DOC "Location of the igraph headers"
    ${igraph_no_default_path}
)

find_library(Igraph_LIBRARY
    NAMES igraph
    HINTS
        ENV
            IGRPAH_PATH
    PATHS ${IGRAPH_PATH}
    PATH_SUFFIXES lib
    DOC "Location of the igraph library"
    ${igraph_no_default_path}
)

if(Igraph_FIND_VERSION)
    message(WARNING "Could not verify igraph version")
    #TODO implement version check
    return()
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Igraph
    REQUIRED_VARS Igraph_INCLUDE_DIR Igraph_LIBRARY
)
mark_as_advanced(Igraph_INCLUDE_DIR Igraph_LIBRARY)
cmake_pop_check_state()

if(Igraph_FOUND)
    add_library(igraph UNKNOWN IMPORTED)
    target_include_directories(igraph INTERFACE ${Igraph_INCLUDE_DIR})
    set_property(TARGET igraph PROPERTY IMPORTED_LOCATION ${Igraph_LIBRARY})
endif()
