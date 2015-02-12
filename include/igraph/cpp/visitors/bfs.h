/* vim:set ts=4 sw=4 sts=4 et: */

#ifndef IGRAPHPP_VISITORS_BFS_H
#define IGRAPHPP_VISITORS_BFS_H

#include <igraph/igraph_visitor.h>
#include <igraph/cpp/types.h>
#include <igraph/cpp/vector.h>

namespace igraph {

class Graph;

typedef igraph_bfshandler_t BFSHandler;

/// Runs a breadth first search on the graph
void bfs(const Graph& graph, integer_t root, Vector* roots=0,
        NeighborMode mode=IGRAPH_OUT, bool unreachable=false,
        Vector* restricted=0, Vector* order=0, Vector* rank=0,
        Vector* father=0, Vector* pred=0, Vector* succ=0, Vector* dist=0,
        BFSHandler callback=0, void* extra=0);

}         // end of namespace

#endif    // IGRAPHPP_VISITORS_BFS_H

