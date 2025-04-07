// File: BFS.cpp
// Author: galogimaymon@gmail.com
// Description: Implements Breadth-First Search (BFS) on a graph and returns a BFS tree with distance output.

#include "BFS.hpp"
#include "../STL/Queue.hpp"
#include <iostream>
#include <climits>
#include "../STL/Stack.hpp"

namespace graph {

    /**
     * @brief Runs Breadth-First Search (BFS) on a given graph from a starting node.
     *        Constructs and returns a BFS tree (Graph object) and prints shortest distances.
     * 
     * @param g The input graph.
     * @param start The starting node for BFS traversal.
     * @return Graph A new Graph object representing the BFS tree (edges as discovered in BFS order).
     */
    Graph BFS::run(const Graph& g, int start) {
        int N = g.getSize();

        // Array to track visited nodes
        bool* visited = new bool[N]();  

        // Array to store shortest distance from start node
        int* distances = new int[N];     

        // Output tree graph to hold BFS result
        Graph bfsTree(N);                

        // Queue for BFS traversal
        Queue q(N);                      

        // Initialize all distances to infinity
        for (int i = 0; i < N; ++i)
            distances[i] = INT_MAX;  

        visited[start] = true;
        distances[start] = 0;           
        q.enqueue(start);
    
        while (!q.isEmpty()) {
            int curr = q.dequeue();  
            Node* neighbor = g.getHead(curr); 

            while (neighbor != nullptr) {
                int next = neighbor->getVal();  

                if (!visited[next]) { 
                    visited[next] = true;  
                    distances[next] = distances[curr] + 1; 
                    q.enqueue(next);  

                    // Add edge to BFS tree
                    bfsTree.addEdge(curr, next, neighbor->getWeight());  
                }

                neighbor = neighbor->getNext(); 
            }
        }

        // Output distances from start to all other vertices
        std::cout << "\n" << "\033[1mBFS distance: \033[0m\n" << std::endl;
        for (int i = 0; i < N; ++i) {
            std::cout << "Distance from " << start << " to " << i << " is " << distances[i] << std::endl;
        }

        // Free dynamic memory
        delete[] visited;
        delete[] distances;

        return bfsTree;
    }

}


    }
