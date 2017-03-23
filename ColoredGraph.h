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

using namespace std;

/** Type definitions to make life easier. */
typedef pair<int, int> directedEdge;
typedef set<int>::iterator vertexIterator;


class ColoredGraph {
    /**
    * Implements an undirected, unweighted graph, where vertices and edges each have color.
    */
public:


    // CONSTRUCTORS
    /**
    * Constructs a graph with no edges or vertices.
    */
    Graph();

    // SETTERS
    /**
    * Adds a vertex to the graph with color <color>.
    * @param color The color of the added vertex.
    * @return The ID of the vertex that was added.
    */
    int addVertex(int color);

    /**
    * Adds the given edge to the graph.
  * @param newEdge An edge to add to the graph.
    * @require the vertices of <newEdge> must currently exist in the graph.
    */
    void addEdge(directedEdge newEdge);

    // GETTERS

    /**
    * @param vertex the vertex whose color is of interest.
    * @require the vertex <vertex> must currently exist in the graph.
    * @return the color of vertex <vertex>.
    */
    int getColor(int vertex);

    /**
    * @return true iff there is an edge in the graph with the same vertices as newEdge
    */
    bool isEdge(directedEdge newEdge);

    /**
    * Returns a string representing a human-readable version of the adjacency list of the graph.
    * Format is:  vertex [color]: adjacent_vertex_1 adjacent_vertex_2 ...
     */
    string print();

private:
    set<int> vertices;       /** The set of vertices of the graph. */
    set<directedEdge> edges; /** A set of edges of the graph. */
    map<int, int> colors;    /** A mapping between vertices and their colors. */

};


#endif //HW5_COLOREDGRAPH_H
