// File: Algorithms.cpp
// Description: Implements the dispatcher for running various graph algorithms (BFS, DFS, Dijkstra, Prim, Kruskal)
//              based on the selected AlgorithmType. This file delegates execution to specific algorithm modules.
// Author: galogimaymon@gmail.com

#include "Algorithms.hpp"
#include "Graph.hpp"
#include "STL/Queue.hpp"
#include "STL/PriorityQueue.hpp"
#include "STL/Stack.hpp"
#include "STL/UnionFind.hpp"
#include <iostream>
#include <climits>
#include "Algorithms/BFS.hpp"
#include "Algorithms/DFS.hpp"
#include "Algorithms/Dijkstra.hpp"
#include "Algorithms/Prim.hpp"
#include "Algorithms/Kruskal.hpp"
#include "AlgorithmType.hpp"

namespace graph {

    /**
     * Runs a graph traversal algorithm that may involve multiple connected components.
     *
     * @param g The graph to run the algorithm on.
     * @param type The algorithm type to execute (currently only DFS supports this variant).
     * @param start The starting node (used if relevant for the algorithm).
     * @param numComponents Output parameter that will hold the number of connected components found.
     * @return An array of pointers to Graph objects representing the result for each component (if applicable).
     * @throws std::invalid_argument if the algorithm type is unknown or unsupported in this context.
     */
    Graph** Algorithms::run(const Graph& g, AlgorithmType type, int start, int& numComponents) {
        switch (type) {
            case AlgorithmType::DFS:
                return DFS::run(g, start, numComponents);
            default:
                throw std::invalid_argument("Unknown algorithm type.");
        }
    }

    /**
     * Runs a single graph algorithm and returns the resulting Graph object.
     *
     * @param g The graph to run the algorithm on.
     * @param type The algorithm type to execute (BFS, Dijkstra, Prim, Kruskal).
     * @param start The starting node (used for BFS and Dijkstra).
     * @return A Graph object representing the result of the algorithm (e.g., BFS tree, shortest path tree, MST).
     * @throws std::invalid_argument if the algorithm type is unknown.
     */
    Graph Algorithms::run(const Graph& g, AlgorithmType type, int start) {
        switch (type) {
            case AlgorithmType::BFS:
                return BFS::run(g, start);
            case AlgorithmType::Dijkstra:
                return Dijkstra::run(g, start);
            case AlgorithmType::Prim:
                return Prim::run(g); // MST – no need for start
            case AlgorithmType::Kruskal:
                return Kruskal::run(g); // MST – no need for start
            default:
                throw std::invalid_argument("Unknown algorithm type.");
        }
    }

}



