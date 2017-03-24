//
// Created by Ari on 3/22/17.
// Represents one colored vertex in a graph.
//

#ifndef HW5_VERTEX_H
#define HW5_VERTEX_H

#include "Color.h"

class Vertex {
public:
    /**
     * Constructs a new vertex with a unique vertex ID
     */
    Vertex(Color theColor=Color(0))
            : myVertexColor(theColor), myVertexId(vertexId++) {}
    bool operator==(const Vertex &other) const { return myVertexId == other.myVertexId; }

    // getters/setters
    const Color getColor() const { return myVertexColor; }
    void setColor(Color theColor) { myVertexColor=theColor; }

    /**
     * Prints a human-readable version of the vertex onto the output stream
     */
    friend std::ostream & operator<<(std::ostream& stream, const Vertex& vert);
private:
    static int vertexId;
    int myVertexId;
    Color myVertexColor;
};

#endif //HW5_VERTEX_H
