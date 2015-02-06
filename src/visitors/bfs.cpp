/* vim:set ts=4 sw=4 sts=4 et: */

#include <igraph/cpp/graph.h>
#include <igraph/cpp/visitors/bfs.h>

namespace igraph {

void bfs(const Graph& graph, integer_t root, Vector* roots, NeighborMode mode,
        bool unreachable, Vector* restricted, Vector* order, Vector* rank,
        Vector* father, Vector* pred, Vector* succ, Vector* dist,
        BFSHandler callback, void* extra) {
    igraph_vector_t* c_roots;
    igraph_vector_t* c_restricted;
    igraph_vector_t* c_order;
    igraph_vector_t* c_rank;
    igraph_vector_t* c_father;
    igraph_vector_t* c_pred;
    igraph_vector_t* c_succ;
    igraph_vector_t* c_dist;

    c_roots = (roots == 0) ? 0 : roots->c_vector();
    c_restricted = (restricted == 0) ? 0 : restricted->c_vector();
    c_order = (order == 0) ? 0 : order->c_vector();
    c_rank = (rank == 0) ? 0 : rank->c_vector();
    c_father = (father == 0) ? 0 : father->c_vector();
    c_pred = (pred == 0) ? 0 : pred->c_vector();
    c_succ = (succ == 0) ? 0 : succ->c_vector();
    c_dist = (dist == 0) ? 0 : dist->c_vector();

    IGRAPH_TRY(igraph_bfs(graph.c_graph(), root, c_roots, mode, unreachable,
                c_restricted, c_order, c_rank, c_father, c_pred, c_succ, c_dist,
                callback, extra));
}

}         // end of namespaces
