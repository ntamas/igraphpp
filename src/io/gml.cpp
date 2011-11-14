/* vim:set ts=4 sw=4 sts=4 et: */

#include <igraph/cpp/error.h>
#include <igraph/cpp/io/gml.h>
#include <memory>

namespace igraph {

Graph read_gml(FILE* instream) {
    std::auto_ptr<igraph_t> result(new igraph_t);
    IGRAPH_TRY(igraph_read_graph_gml(result.get(), instream));
    return Graph(result.release());
}

}         // end of namespace

