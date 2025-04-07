// File: Prim.cpp
// Author: galogimaymon@gmail.com
// Description: Implements Prim's algorithm to find a Minimum Spanning Tree (MST)
//              in a connected undirected weighted graph using a priority queue.

#include "Prim.hpp"
#include "../STL/Queue.hpp"
#include <iostream>
#include <climits>
#include "../STL/Stack.hpp"
#include "../STL/PriorityQueue.hpp"
#include "DFS.hpp"

namespace graph {

    /**
     * @brief Runs Prim's algorithm to compute the Minimum Spanning Tree (MST) of a connected graph.
     *
     * @param g The input graph (must be connected).
     * @return Graph A new Graph object representing the MST.
     *
     * @throws std::invalid_argument If the graph is not connected.
     */
    Graph Prim::run(const Graph& g) {
        int N = g.getSize();

        // Memory allocations
        bool* inMST = new bool[N]();    // Marks if a vertex is already in MST
        int* key = new int[N];          // Minimum weight to connect each vertex
        int* parent = new int[N];       // Tracks MST tree edges (not used directly here)

        // Ensure the graph is connected
        if (!DFS::isConnected(g)) {
            delete[] inMST;
            delete[] key;
            delete[] parent;
            throw std::invalid_argument("Prim Error: Graph is not connected – no spanning tree exists.");
        }

        // Initialization
        for (int i = 0; i < N; ++i) {
            key[i] = INT_MAX;
            parent[i] = -1;
        }
        key[0] = 0;
        inMST[0] = true;

        Graph mst(N);  // Output MST

        PriorityQueue pq(N);
        pq.enqueue(0, 0);  // Start from vertex 0

        while (!pq.isEmpty()) {
            int u = pq.dequeue();

            Node* neighbor = g.getHead(u);
            while (neighbor != nullptr) {
                int v = neighbor->getVal();
                int weight = neighbor->getWeight();

                // If v not in MST and found smaller weight
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    pq.enqueue(v, key[v]);

                    mst.addEdge(u, v, weight);  // Add edge to MST
                }

                neighbor = neighbor->getNext();
            }

            inMST[u] = true;  // Mark u as processed
        }

        // Free memory
        delete[] inMST;
        delete[] key;
        delete[] parent;

        return mst;
    }

}
