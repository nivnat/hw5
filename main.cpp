#include <iostream>
#include <stdexcept>
#include <cmath>
#include "ColoredGraph.h"

/**
 * @return a random integer in the range low...high, inclusive
 */
int rand(int low, int high) {
    if (low>high)
        low=1;
    return rand()%(high-low+1) + low;
}

/**
 * Generates a random graph based on #magicNumber.
 * All nodes and edges get the same (default) color.
 * The size of the graph grows with this parameter.
 * @return A random graph.
 */
ColoredGraph generateGraph(const int magicNumber) {
    srand(magicNumber); // not a good random number generator, but it will do

    // some constants
    const double lnMagic = trunc(log(magicNumber));
    const int numVertices = rand(magicNumber - 5, magicNumber + 5);
    const int numEdges = rand(magicNumber * lnMagic, magicNumber + 2 * lnMagic);

    ColoredGraph result;
    // generate and add vertices
    for (int ii = 0; ii < numVertices; ii++)
        result.addVertex(Vertex());

    // generate and add edges
    for (int ii = 0; ii < numEdges; ii++)
        try {
            Vertex Vert1 = result[rand(0, numVertices - 1)];
            Vertex Vert2 = result[rand(0, numVertices - 1)];
            result.addEdge(Edge(Vert1, Vert2));
        }
        catch (std::invalid_argument err) {
            ii--;
        }
    return result;
}

int main() {
    cout << "Magic Number: ";
    int mn; cin >> mn;
    std::cout << generateGraph(mn) << endl;
}