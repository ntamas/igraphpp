/* vim:set ts=4 sw=4 sts=4 et: */

#include <igraph/igraph_games.h>
#include <igraph/cpp/graph.h>
#include <igraph/cpp/generators/erdos_renyi.h>

namespace igraph {

std::unique_ptr<Graph> erdos_renyi_game_gnm(integer_t n, integer_t m, bool directed, bool loops) {
    std::unique_ptr<igraph_t> result(new igraph_t);
    IGRAPH_TRY(igraph_erdos_renyi_game_gnm(result.get(), n, m, directed, loops));
    return std::unique_ptr<Graph>(new Graph(result.release()));
}

std::unique_ptr<Graph> erdos_renyi_game_gnp(integer_t n, real_t p, bool directed, bool loops) {
    std::unique_ptr<igraph_t> result(new igraph_t);
    IGRAPH_TRY(igraph_erdos_renyi_game_gnp(result.get(), n, p, directed, loops));
    return std::unique_ptr<Graph>(new Graph(result.release()));
}

}         // end of namespaces

