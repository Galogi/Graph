#ifndef ALGORITHMS_H
#define ALGORITHMS_H

/**
 * @file Algorithms.hpp
 * @brief Central interface to run various graph algorithms by selecting from an enum type.
 *        Supports both traversal and optimization algorithms like BFS, DFS, Dijkstra, Prim, and Kruskal.
 * @author galogimaymon@gmail.com
 */

#include "Graph.hpp"
#include "STL/Queue.hpp"
#include "STL/Stack.hpp"
#include "STL/UnionFind.hpp"
#include "AlgorithmType.hpp"

namespace graph {

    /**
     * @class Algorithms
     * @brief Provides a unified interface to run different graph algorithms using AlgorithmType enum.
     */
    class Algorithms {
    public:
        /**
         * @brief Runs a graph algorithm that produces a single resulting Graph (e.g. BFS, Dijkstra, Prim, Kruskal).
         *
         * @param g The input graph.
         * @param type The type of algorithm to run.
         * @param start The starting vertex (if applicable to the algorithm).
         * @return Graph The resulting graph after algorithm execution.
         *
         * @throws std::invalid_argument If the algorithm type is unknown.
         */
        static Graph run(const Graph& g, AlgorithmType type, int start = 1);

        /**
         * @brief Runs a traversal algorithm that may return multiple connected components (DFS).
         *
         * @param g The input graph.
         * @param type The type of algorithm to run (currently only DFS supported here).
         * @param start The starting vertex.
         * @param numComponents Output parameter: the number of components found.
         * @return Graph** Array of pointers to resulting Graphs (one per component).
         *
         * @throws std::invalid_argument If the algorithm type is unknown.
         *
         * @note Caller is responsible for freeing the returned array and its Graph pointers.
         */
        static Graph** run(const Graph& g, AlgorithmType type, int start, int& numComponents);
    };

}

#endif

