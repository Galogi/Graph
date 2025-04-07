#pragma once
#include "../Graph.hpp"

/**
 * @file Kruskal.hpp
 * @brief Interface for Kruskal's algorithm to find a Minimum Spanning Tree (MST).
 * @author galogimaymon@gmail.com
 */

namespace graph {

    /**
     * @class Kruskal
     * @brief Provides a static method to run Kruskal's algorithm on a graph.
     */
    class Kruskal {
    public:
        /**
         * @brief Runs Kruskal's algorithm to compute the Minimum Spanning Tree (MST).
         * 
         * @param g The input undirected, weighted, connected graph.
         * @return Graph A new Graph object representing the MST.
         * 
         * @throws std::invalid_argument If the graph is not connected.
         */
        static Graph run(const Graph& g);
    };

}
