/* vim:set ts=4 sw=4 sts=4 et: */

#include <igraph/cpp/graph.h>
#include <igraph/cpp/io/ncol.h>
#include <memory>

namespace igraph {

Graph read_ncol(FILE* instream, bool names, AddWeights weights, bool directed) {
    std::auto_ptr<igraph_t> result(new igraph_t);
    IGRAPH_TRY(igraph_read_graph_ncol(result.get(), instream, 0, names, weights, directed));
    return Graph(result.release());
}

}         // end of namespace

