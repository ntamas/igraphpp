cmake_minimum_required(VERSION 3.16)
cmake_policy(SET CMP0003 NEW)
project(igraphpp C CXX)

if(NOT TARGET igraph)
    set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/etc/cmake;${CMAKE_MODULE_PATH})
    find_package(igraph REQUIRED)
endif()

add_library(igraphpp STATIC
    src/attributes
    src/centrality
    src/edge
    src/graph
    src/matching
    src/vector
    src/vector_bool
    src/vector_long
    src/vertex
    src/vertex_selector

    src/analysis/components
    src/analysis/non_simple

    src/generators/degree_sequence
    src/generators/erdos_renyi
    src/generators/famous
    src/generators/full
    src/generators/grg
    src/generators/line_graph
    src/generators/ring

    src/io/edgelist
    src/io/gml
    src/io/graphml
    src/io/leda
    src/io/lgl
    src/io/ncol

    src/visitors/bfs
)

target_include_directories(igraphpp PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}/include
)

target_link_libraries(igraphpp PUBLIC igraph)
