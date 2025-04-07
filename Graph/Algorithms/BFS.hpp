#pragma once
#include "../Graph.hpp"

/**
 * @file BFS.hpp
 * @brief Interface for the Breadth-First Search (BFS) algorithm on a graph.
 */

namespace graph {

    /**
     * @class BFS
     * @brief Provides a static method to run the Breadth-First Search (BFS) algorithm on a graph.
     */
    class BFS {
    public:
        /**
         * @brief Runs BFS on the given graph starting from the specified node.
         *        Returns a new graph representing the BFS traversal tree.
         *
         * @param g The input graph.
         * @param start The starting node for the BFS traversal.
         * @return Graph A new Graph object representing the BFS tree.
         */
        static Graph run(const Graph& g, int start);
    };

}
