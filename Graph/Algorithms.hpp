#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.hpp"
#include "STL/Queue.hpp"
#include "STL/Stack.hpp"
#include "STL/UnionFind.hpp"
#include "AlgorithmType.hpp"

#include "AlgorithmType.hpp"

namespace graph {
    class Algorithms {
    public:
        
        static Graph run(const Graph& g,  AlgorithmType type ,int start=1);
        static Graph** run(const Graph& g, AlgorithmType type, int start, int& numComponents);
        
    };
}







/*namespace graph {

class Algorithms {
public:
    static graph::Graph bfs(const graph::Graph& g, int start);
    static graph::Graph dfs(const graph::Graph& g, int start);
    static graph::Graph dijkstra(const graph::Graph& g, int start);
    static graph::Graph prim(const graph::Graph& g);
    static graph::Graph kruskal(const graph::Graph& g);
    void Algorithms::initSingleSource(int* distances, int* parent, int N, int start);
};

}*/

#endif
