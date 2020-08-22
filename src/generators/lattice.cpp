/* vim:set ts=4 sw=4 sts=4 et: */

#include <igraph/cpp/graph.h>
#include <igraph/cpp/generators/lattice.h>

namespace igraph {


    // TODO: Why is, in this installation, the parameter bool circular missing?
    // it exists both in the manual and on github.
std::unique_ptr<Graph> lattice(const Vector& dimvector,
                               integer_t nei,
                               bool directed,
                               bool mutual) {
    std::unique_ptr<igraph_t> result(new igraph_t);
    IGRAPH_TRY(igraph_lattice(result.get(),
                              dimvector.c_vector(),
                              nei,
                              directed,
                              mutual));
    return std::unique_ptr<Graph>(new Graph(result.release()));
}

}         // end of namespaces

