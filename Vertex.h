//
// Created by Ari on 3/22/17.
// Represents one colored vertex in a graph.
//

#ifndef HW5_VERTEX_H
#define HW5_VERTEX_H

class Vertex {
public:
    /**
     * Constructs a new vertex with a unique vertex ID
     */
    Vertex() {myVertexId=vertexId++;}
    bool operator==(const Vertex &other) const { return myVertexId == other.myVertexId; }
private:
    static int vertexId=0;
    int myVertexId;
};

#endif //HW5_VERTEX_H
