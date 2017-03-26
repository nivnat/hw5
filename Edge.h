//
// Created by Ari Trachtenberg on 3/23/17.
//

#ifndef HW5_EDGE_H
#define HW5_EDGE_H

#include <stdexcept>
#include "Vertex.h"

class Edge {
public:
    /**
     * Constructs a new edge connecting #v1 and #v2
     */
    Edge(Vertex *v1, Vertex *v2, Color theColor = Color(0))
            : edgeColor(theColor), aa(v1), bb(v2)
    {
        if (*v1==*v2)
            throw std::invalid_argument("v1 equals v2 in edge construction");
    }

    /**
     * @return true iff #this edge and #other involve the same vertices (i.e. does not look at color)
     */
    bool operator==(const Edge &other) const {
        return ((*aa==*other.aa) && (*bb==*other.bb)) || ((*aa==*other.bb) && (*bb==*other.aa));
    }

    /**
     * @return true iff this edge is incident on Vertex #vv
     */
    bool incidentQ(Vertex vv) {
        return (*aa==vv) || (*bb==vv);
    }

    /**
     * Prints a human-readable version of the vertex onto the output stream
     */
    friend std::ostream & operator<<(std::ostream& stream, const Edge& theEdge);

    // getters and setters
    const Vertex& getV1()  { return *aa; }
    const Vertex& getV2()  { return *bb; }
    const Color getColor() const { return edgeColor; }
    void setColor(Color theColor) { edgeColor=theColor; }

private:
    Edge(); // no default constructor

    Vertex *aa, *bb; // the vertices involved with the edge
    Color edgeColor; // the color of this edge
};
#endif //HW5_EDGE_H
