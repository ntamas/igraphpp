/* vim:set ts=4 sw=4 sts=4 et: */

#ifndef IGRAPHPP_CENTRALITY_H
#define IGRAPHPP_CENTRALITY_H

namespace igraph {

class Graph;
class Vector;
class VertexSelector;

Vector betweenness(const Graph& graph, const VertexSelector& vids,
        bool directed = true, const Vector* weights = 0);
void betweenness(const Graph& graph, Vector* result, const VertexSelector& vids,
        bool directed = true, const Vector* weights = 0);

}         // end of namespace

#endif    // IGRAPHPP_CENTRALITY_H

