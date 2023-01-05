/* vim:set ts=4 sw=4 sts=4 et: */

#ifndef IGRAPHPP_VISITORS_BFS_H
#define IGRAPHPP_VISITORS_BFS_H

#include <igraph/igraph_visitor.h>
#include <igraph/cpp/types.h>
#include <igraph/cpp/vector_int.h>

namespace igraph {

class Graph;

typedef igraph_bfshandler_t BFSHandler;

/// Runs a breadth first traversal on a graph
void bfs(const Graph& graph, integer_t root, VectorInt* roots=0,
        NeighborMode mode=IGRAPH_OUT, bool unreachable=false, VectorInt* restricted=0,
        VectorInt* order=0, VectorInt* rank=0, VectorInt* father=0,
        VectorInt* pred=0, VectorInt* succ=0, VectorInt* dist=0,
        BFSHandler callback=0, void* extra=0);

}         // end of namespace

#endif    // IGRAPHPP_VISITORS_BFS_H
