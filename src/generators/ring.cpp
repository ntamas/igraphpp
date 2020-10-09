/* vim:set ts=4 sw=4 sts=4 et: */

#include <igraph/cpp/graph.h>
#include <igraph/cpp/generators/ring.h>

namespace igraph {

std::unique_ptr<Graph> ring(integer_t n, bool directed, bool mutual, bool circular) {
    std::unique_ptr<igraph_t> result(new igraph_t);
    IGRAPH_TRY(igraph_ring(result.get(), n, directed, mutual, circular));
    return std::unique_ptr<Graph>(new Graph(result.release()));
}

}         // end of namespaces

