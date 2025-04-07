#pragma once
#include "../Graph.hpp"

/**
 * @file DFS.hpp
 * @brief Interface for the Depth-First Search (DFS) algorithm and graph connectivity check.
 */
// Author: galogimaymon@gmail.com

namespace graph {

    /**
     * @class DFS
     * @brief Provides static methods to run Depth-First Search and check if a graph is connected.
     */
    class DFS {
    public:
        /**
         * @brief Runs DFS on the given graph starting from a specified node.
         *        Also finds additional components if they exist.
         *
         * @param g The input graph.
         * @param start The starting vertex for the DFS.
         * @param numComponents Output parameter to store the number of connected components.
         * @return Graph** An array of pointers to Graph objects representing DFS trees (one per component).
         *
         * @note The caller is responsible for deleting the returned array and each Graph* inside it.
         */
        static Graph** run(const Graph& g, int start, int& numComponents);

        /**
         * @brief Checks whether the input graph is fully connected (only one connected component).
         *
         * @param g The input graph.
         * @return true If the graph is connected.
         * @return false If the graph has more than one component.
         */
        static bool isConnected(const Graph& g); 
    };

}
