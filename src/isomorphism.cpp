/* vim:set ts=4 sw=4 sts=4 et: */

#include <igraph/cpp/graph.h>
#include <igraph/igraph_topology.h>

namespace igraph {

    bool isomorphic(const Graph& graph1, const Graph& graph2){
        igraph_bool_t result;
        IGRAPH_TRY(igraph_isomorphic(graph1.c_graph(), graph2.c_graph(), result))
        return result;
    }

}
