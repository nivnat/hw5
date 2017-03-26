//
// Created by Ari on 3/22/17.
//

#include "ColoredGraph.h"
#include <iostream>
#include <sstream>

using namespace std;

std::ostream & operator<<(std::ostream& stream, const ColoredGraph& theGraph) {
    stream << "Vertices: " << endl;
    for (int ii = 0; ii < theGraph.numVertices(); ii++)
        stream << theGraph[ii] << endl;

    stream << endl << "Edges: " << endl;
    for (int jj = 0; jj < theGraph.numEdges(); jj++)
        stream << theGraph(jj) << endl;
    return stream;
}

std::ostream & operator<<(std::ostream& stream, const Edge& theEdge) {
    stream << *theEdge.aa << " <-> " << *theEdge.bb << ", edge color: " << theEdge.getColor();
    return stream;
}

std::ostream & operator<<(std::ostream& stream, const Vertex& vert) {
    stream << vert.myVertexId << vert.myVertexColor;
    return stream;
}

std::ostream & operator<<(std::ostream& stream, const Color& col) {
    stream << "[ " << col.myColor << " ]";
    return stream;
}