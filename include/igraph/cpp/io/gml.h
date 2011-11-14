/* vim:set ts=4 sw=4 sts=4 et: */

#ifndef IGRAPHPP_IO_GML_H
#define IGRAPHPP_IO_GML_H

#include <igraph/cpp/graph.h>

namespace igraph {

/// Reads a graph from a GML file
Graph read_gml(FILE* instream);

}         // end of namespace

#endif    // IGRAPHPP_IO_GML_H

