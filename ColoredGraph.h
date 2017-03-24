//
// Created by Ari on 3/22/17.
//

#ifndef HW5_COLOREDGRAPH_H
#define HW5_COLOREDGRAPH_H

#include <set>
#include <map>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

class ColoredGraph {
    /**
    * Implements an undirected, unweighted graph, where vertices and edges each have color.
    */
public:


    // CONSTRUCTORS
    /**
    * Constructs a graph with no edges or vertices.
    */
    ColoredGraph();

    // SETTERS
    /**
    * Adds a vertex to the graph with color <color>.
    * @param color The color of the added vertex.
    */
    void addVertex(const Vertex& newVertex);

    /**
    * Adds the given edge to the graph.
    * @param newEdge An edge to add to the graph.
    * @throws an invalid_argument if the vertices of newEdge are not already in the graph,
    *           or if an edge between the same vertices already exists in the graph
    */
    void addEdge(const Edge& newEdge);

    // GETTERS

    /**
    * @return the #index -th vertex in the graph.  The first vertex has index 0.
    * @throws an invalid_argument if there is no such vertex currently in the graph.
    */
    const Vertex& operator[](int index) const;
    Vertex& operator[](int index);

    /**
     * @return the number of vertices in the graph
     */
    int numVertices() const;
    /**
     * @return # index -th edge in the graph.  The first edge has index 0.
    * @throws an invalid_argument if there is no such edge currently in the graph.
     */
    const Edge& operator()(int index) const;
    Edge& operator()(int index);

    /**
     * @return the number of edges in the graph
     */
    int numEdges() const;

    /**
    * @return true iff newEdge== an edge in the graph
    */
    bool isEdgeQ(const Edge &newEdge) const;

    /**
     * @return true iff the graph is a proper coloring, as defined in the homework
     */
    bool isColoredQ() const;

    /**
     * Cleans up the graph memory, as needed.
     */
    virtual ~ColoredGraph();

    /**
    * Returns a string representing a human-readable version of the graph
     */
    friend std::ostream & operator<<(std::ostream& stream, const ColoredGraph& theGraph);

private:
    vector<Vertex> vertices;       /** The set of vertices of the graph. */
    vector<Edge> edges;            /** A set of edges of the graph. */
};


#endif //HW5_COLOREDGRAPH_H
