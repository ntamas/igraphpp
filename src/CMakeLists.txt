add_library(igraphpp STATIC attributes.cpp
                            centrality.cpp
                            edge.cpp
                            graph.cpp
                            matching.cpp
                            vector.cpp
                            vector_bool.cpp
                            vector_long.cpp
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

