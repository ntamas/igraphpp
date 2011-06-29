/* vim:set ts=4 sw=4 sts=4 et: */

#ifndef IGRAPHPP_EDGE_H
#define IGRAPHPP_EDGE_H

#include <utility>
#include <igraph/cpp/any.hpp>
#include <igraph/cpp/types.h>

namespace igraph {

class Graph;

class Edge {
private:
    /// The graph the edge is a member of
    const Graph* m_pGraph;

    /// The index of the edge in the given graph
    integer_t m_index;

public:
    /// Constructs a reference to a given edge of a given graph
    Edge(const Graph* pGraph, integer_t index) : m_pGraph(pGraph), m_index(index) {}

    /// Returns the destination of the edge
    integer_t destination();

    /// Returns the head (i.e. destination) of the edge
    integer_t head() { return destination(); }

    /// Returns the value of the given edge attribute for this edge
    any getAttribute(const std::string& attribute) const;

    /**
     * \brief Returns the value of the given edge attribute for this edge,
     *        or a default value if there is no such attribute.
     */
    any getAttribute(const std::string& attribute, const any& defaultValue) const;

    /// Returns the source of the edge
    integer_t source();

    /// Returns the tail (i.e. source) of the edge
    integer_t tail() { return source(); }
};

}         // end of namespace

#endif    // IGRAPHPP_EDGE_H
