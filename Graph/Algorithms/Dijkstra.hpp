#pragma once
#include "../Graph.hpp"

/**
 * @file Dijkstra.hpp
 * @brief Interface for Dijkstra's shortest path algorithm.
 * @author galogimaymon@gmail.com
 */

namespace graph {

    /**
     * @class Dijkstra
     * @brief Provides a static method to run Dijkstra's algorithm on a graph.
     */
    class Dijkstra {
    public:
        /**
         * @brief Runs Dijkstra's algorithm from a given starting node.
         *        Returns a new graph representing the shortest path tree.
         * 
         * @param g The input graph.
         * @param start The starting node for shortest path calculations.
         * @return Graph A new Graph object representing the shortest path tree.
         * 
         * @throws std::invalid_argument If the graph contains negative edge weights.
         */
        static Graph run(const Graph& g, int start);
    };

}
