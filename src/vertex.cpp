/* vim:set ts=4 sw=4 sts=4 et: */

#include <igraph/cpp/graph.h>
#include <igraph/cpp/vertex.h>

namespace igraph {

any Vertex::getAttribute(const std::string& attribute) const {
    const AttributeHolder& attributeHolder = *m_pGraph->getAttributeHolder();
    return attributeHolder.getVertexAttribute(attribute, m_index);
}

any Vertex::getAttribute(const std::string& attribute, const any& defaultValue) const {
    const AttributeHolder& attributeHolder = *m_pGraph->getAttributeHolder();
    if (!attributeHolder.hasVertexAttribute(attribute))
        return defaultValue;
    return attributeHolder.getVertexAttribute(attribute, m_index);
}

}         // end of namespace

