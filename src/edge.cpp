/* vim:set ts=4 sw=4 sts=4 et: */

#include <igraph/cpp/edge.h>
#include <igraph/cpp/graph.h>

namespace igraph {

integer_t Edge::destination() {
    return IGRAPH_TO(m_pGraph->c_graph(), m_index);
}

any Edge::getAttribute(const std::string& attribute) const {
    const AttributeHolder& attributeHolder = *m_pGraph->getAttributeHolder();
    return attributeHolder.getEdgeAttribute(attribute, m_index);
}

any Edge::getAttribute(const std::string& attribute, const any& defaultValue) const {
    const AttributeHolder& attributeHolder = *m_pGraph->getAttributeHolder();
    if (!attributeHolder.hasEdgeAttribute(attribute))
        return defaultValue;
    return attributeHolder.getEdgeAttribute(attribute, m_index);
}

integer_t Edge::source() {
    return IGRAPH_FROM(m_pGraph->c_graph(), m_index);
}

}         // end of namespace

