#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstdlib>
#include "ColoredGraph.h"

/**
 * A poor-quality machine-portable random number generator.
 */
class randomer {
public:
    randomer(long newSeed=1) : seed(newSeed) {}

    /**
     * @requires 1<=low<=high
     * @return a random number in the range low...high, inclusive.
     */
    int nextInRange(int low, int high) {
        seed=(22123*(seed+1))%15486929;
        return seed%(high-low+1) + low;
    }

private:
    long seed;
};

/**
 * Generates a random graph based on #magicNumber.
 * All nodes and edges get the same (default) color.
 * The size of the graph grows with this parameter.
 * @return A random graph.
 */
ColoredGraph generateGraph(const int magicNumber) {
    randomer rr(magicNumber);

    // some constants
    const int numVertices = 2+rr.nextInRange(magicNumber, magicNumber + 5);
    const double lnTerm = trunc(log(numVertices));
    const int numEdges = rr.nextInRange(numVertices * lnTerm, 2*numVertices * lnTerm);

    ColoredGraph result;
    // generate and add vertices
    for (int ii = 0; ii < numVertices; ii++)
        result.addVertex(Vertex());

    // generate and add edges
    for (int ii = 0; ii < numEdges; ii++)
        try {
            Vertex& Vert1 = result[rr.nextInRange(0, numVertices - 1)];
            Vertex& Vert2 = result[rr.nextInRange(0, numVertices - 1)];
            result.addEdge(Edge(&Vert1, &Vert2));
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