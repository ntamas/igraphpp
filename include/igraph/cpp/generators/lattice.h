/* vim:set ts=4 sw=4 sts=4 et: */

#ifndef IGRAPHPP_GENERATORS_LATTICE_H
#define IGRAPHPP_GENERATORS_LATTICE_H

#include <memory>

namespace igraph {

class Graph;

/// Generates a lattice graph
std::unique_ptr<Graph> lattice(const Vector& dimvector,
                               integer_t nei,
                               bool directed = false,
                               bool mutual = false);

}         // end of namespace

#endif    // IGRAPHPP_GENERATORS_LATTICE_H
