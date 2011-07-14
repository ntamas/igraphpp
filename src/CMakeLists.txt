add_library(igraphpp STATIC attributes
                            edge
                            graph
                            matching
                            vector
                            vector_bool
                            vector_long
                            vertex
                            vertex_selector

							generators/degree_sequence
							generators/erdos_renyi
                            generators/line_graph

                            io/edgelist
                            io/graphml
                            io/leda
							io/lgl
                            io/ncol
)

