#pragma once
#include "../Graph.hpp"

/**
 * @file Prim.hpp
 * @brief Interface for Prim's algorithm to compute a Minimum Spanning Tree (MST).
 * @author galogimaymon@gmail.com
 */

namespace graph {

    /**
     * @class Prim
     * @brief Provides a static method to run Prim's algorithm on a graph.
     */
    class Prim {
    public:
        /**
         * @brief Runs Prim's algorithm to compute the Minimum Spanning Tree (MST).
         * 
         * @param g The input undirected, weighted, and connected graph.
         * @return Graph A new Graph object representing the MST.
         * 
         * @throws std::invalid_argument If the graph is not connected.
         */
        static Graph run(const Graph& g);
    };

}
