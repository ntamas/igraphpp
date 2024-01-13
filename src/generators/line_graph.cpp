/* vim:set ts=4 sw=4 sts=4 et: */

#include <igraph/igraph_structural.h>
#include <igraph/cpp/error.h>
#include <igraph/cpp/graph.h>
#include <igraph/cpp/generators/line_graph.h>

namespace igraph {

std::unique_ptr<Graph> line_graph(const Graph& graph) {
    std::unique_ptr<igraph_t> result(new igraph_t);
    IGRAPH_TRY(igraph_linegraph(graph.c_graph(), result.get()));
    return std::unique_ptr<Graph>(new Graph(std::move(result)));
}

}         // end of namespaces

