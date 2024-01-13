/* vim:set ts=4 sw=4 sts=4 et: */

#ifndef IGRAPHPP_GENERATORS_DEGREE_SEQUENCE_H
#define IGRAPHPP_GENERATORS_DEGREE_SEQUENCE_H

#include <memory>
#include <igraph/igraph_constants.h>
#include <igraph/cpp/types.h>
#include <igraph/cpp/vector.h>

namespace igraph {

class Graph;

/// Generates an undirected random graph with a given degree sequence
std::unique_ptr<Graph> degree_sequence_game(const VectorInt& degrees,
        DegreeSequenceMethod method = IGRAPH_DEGSEQ_CONFIGURATION);

/// Generates a directed random graph with a given degree sequence
std::unique_ptr<Graph> degree_sequence_game(const VectorInt& outdegrees, const VectorInt& indegrees,
        DegreeSequenceMethod method = IGRAPH_DEGSEQ_CONFIGURATION);

}         // end of namespace

#endif    // IGRAPHPP_GENERATORS_DETERMINISTIC_H
