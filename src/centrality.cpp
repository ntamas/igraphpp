/* vim:set ts=4 sw=4 sts=4 et: */

#include <igraph/cpp/centrality.h>
#include <igraph/cpp/graph.h>
#include <igraph/cpp/vector.h>
#include <igraph/cpp/vertex_selector.h>
#include <igraph/igraph_centrality.h>

namespace igraph {

Vector betweenness(const Graph& graph, const VertexSelector& vids,
        bool directed, const Vector* weights) {
    Vector result;
    betweenness(graph, &result, vids, directed, weights);
    return result;
}

void betweenness(const Graph& graph, Vector* result, const VertexSelector& vids,
        bool directed, const Vector* weights) {
    IGRAPH_TRY(igraph_betweenness(graph.c_graph(),
                result ? result->c_vector() : 0,
                *vids.c_vs(), directed,
                weights ? weights->c_vector() : 0));
}

}          // end of namespace

