/* vim:set ts=4 sw=4 sts=4 et: */

#include <igraph/igraph_games.h>
#include <igraph/cpp/graph.h>
#include <igraph/cpp/generators/degree_sequence.h>

namespace igraph {

Graph degree_sequence_game(const Vector& degrees, DegreeSequenceMethod method) {
    std::auto_ptr<igraph_t> result(new igraph_t);
    IGRAPH_TRY(igraph_degree_sequence_game(result.get(), degrees.c_vector(),
                0, method));
    return Graph(result.release());
}

Graph degree_sequence_game(const Vector& outdegrees, const Vector& indegrees,
        DegreeSequenceMethod method) {
    std::auto_ptr<igraph_t> result(new igraph_t);
    IGRAPH_TRY(igraph_degree_sequence_game(result.get(), outdegrees.c_vector(),
                indegrees.c_vector(), method));
    return Graph(result.release());
}

}         // end of namespaces

