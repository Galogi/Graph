#pragma once

/**
 * @file AlgorithmType.hpp
 * @brief Defines an enumeration for selecting graph algorithm types at runtime or via interface logic.
 * @author galogimaymon@gmail.com
 */

namespace graph {

    /**
     * @enum AlgorithmType
     * @brief Enumerates supported graph algorithms.
     */
    enum class AlgorithmType {
        BFS,       ///< Breadth-First Search
        DFS,       ///< Depth-First Search
        Dijkstra,  ///< Dijkstra's Shortest Path Algorithm
        Prim,      ///< Prim's Minimum Spanning Tree Algorithm
        Kruskal    ///< Kruskal's Minimum Spanning Tree Algorithm
    };

}
