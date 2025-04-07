#include "Algorithms.hpp"
#include "Graph.hpp"
#include "STL/Queue.hpp"
#include "STL/PriorityQueue.hpp"
#include "STL/Stack.hpp"
#include "STL/UnionFind.hpp"
#include <iostream>
#include <climits>
#include "Algorithms.hpp"
#include "Algorithms/BFS.hpp"
#include "Algorithms/DFS.hpp"
#include "Algorithms/Dijkstra.hpp"
#include "Algorithms/Prim.hpp"
#include "Algorithms/Kruskal.hpp"
#include "AlgorithmType.hpp"



    namespace graph {


        Graph** Algorithms::run(const Graph& g, AlgorithmType type, int start, int& numComponents){
            switch (type) {
                case AlgorithmType::DFS:
                return DFS::run(g, start, numComponents);
                default:
                    throw std::invalid_argument("Unknown algorithm type.");
        }
    }

        Graph Algorithms::run(const Graph& g, AlgorithmType type ,int start) {
            switch (type) {
                case AlgorithmType::BFS:
                    return BFS::run(g, start);
                case AlgorithmType::Dijkstra:
                    return Dijkstra::run(g, start);
                case AlgorithmType::Prim:
                    return Prim::run(g);
                case AlgorithmType::Kruskal:
                    return Kruskal::run(g); // לא צריך start
                default:
                    throw std::invalid_argument("Unknown algorithm type.");
                
            }
        }
       

    }
    


