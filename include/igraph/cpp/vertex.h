/* vim:set ts=4 sw=4 sts=4 et: */

#ifndef IGRAPHPP_VERTEX_H
#define IGRAPHPP_VERTEX_H

#include <utility>
#include <igraph/cpp/any.hpp>
#include <igraph/cpp/types.h>

namespace igraph {

class Graph;

class Vertex {
private:
    /// The graph the vertex is a member of
    const Graph* m_pGraph;

    /// The index of the vertex in the given graph
    integer_t m_index;

public:
    /// Constructs a reference to a given vertex of a given graph
    Vertex(const Graph* pGraph, integer_t index) : m_pGraph(pGraph), m_index(index) {}

    /// Returns the value of the given vertex attribute for this vertex
    any getAttribute(const std::string& attribute) const;

    /**
     * \brief Returns the value of the given vertex attribute for this vertex,
     *        or a default value if there is no such attribute.
     */
    any getAttribute(const std::string& attribute, const any& defaultValue) const;
};

}         // end of namespace

#endif    // IGRAPHPP_VERTEX_H
