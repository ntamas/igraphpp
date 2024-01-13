/* vim:set ts=4 sw=4 sts=4 et: */

#include <igraph/cpp/error.h>
#include <igraph/cpp/io/gml.h>
#include <memory>

namespace igraph {

Graph read_gml(FILE* instream) {
    std::unique_ptr<igraph_t> result(new igraph_t);
    IGRAPH_TRY(igraph_read_graph_gml(result.get(), instream));
    return Graph(result.release());
}

void write_gml(const Graph& graph, FILE* outstream) {
    // TODO: handle "id" argument
    IGRAPH_TRY(igraph_write_graph_gml(graph.c_graph(), outstream, IGRAPH_WRITE_GML_DEFAULT_SW, 0, 0));
}

void write_gml(const Graph& graph, FILE* outstream, const std::string& creator) {
    // TODO: handle "id" argument
    IGRAPH_TRY(igraph_write_graph_gml(graph.c_graph(), outstream, IGRAPH_WRITE_GML_DEFAULT_SW, 0, creator.c_str()));
}

}         // end of namespace

