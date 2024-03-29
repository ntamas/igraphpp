add_library(
    igraphpp STATIC

    attributes.cpp
    centrality.cpp
    edge.cpp
    graph.cpp
    matching.cpp
    vector.cpp
    vector_bool.cpp
    vector_int.cpp
    vertex.cpp
    vertex_selector.cpp

    analysis/components.cpp
    analysis/non_simple.cpp

    generators/degree_sequence.cpp
    generators/erdos_renyi.cpp
    generators/famous.cpp
    generators/full.cpp
    generators/grg.cpp
    generators/line_graph.cpp
    generators/ring.cpp

    io/edgelist.cpp
    io/gml.cpp
    io/graphml.cpp
    io/leda.cpp
    io/lgl.cpp
    io/ncol.cpp

    visitors/bfs.cpp
)
target_include_directories(
    igraphpp PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)
target_include_directories(
    igraphpp PRIVATE
    ${CMAKE_BINARY_DIR}/include
)
target_link_libraries(
    igraphpp PUBLIC
    igraph::igraph
)

