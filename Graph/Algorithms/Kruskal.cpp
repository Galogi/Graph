// File: Kruskal.cpp
// Author: galogimaymon@gmail.com
// Description: Implements Kruskal's algorithm for finding a Minimum Spanning Tree (MST)
//              in a connected undirected weighted graph using Union-Find.

#include "Kruskal.hpp"
#include "../STL/UnionFind.hpp"
#include <iostream>
#include <climits>
#include "DFS.hpp"

namespace graph {

    /**
     * @brief Runs Kruskal's algorithm to compute the Minimum Spanning Tree (MST) of a connected graph.
     * 
     * @param g The input graph (must be connected).
     * @return Graph A new Graph object representing the MST.
     * 
     * @throws std::invalid_argument If the input graph is not connected.
     */
    Graph Kruskal::run(const Graph& g) {
        int N = g.getSize();

        // Ensure the graph is connected before attempting to build a spanning tree
        if (!DFS::isConnected(g)) {
            throw std::invalid_argument("Prim Error: Graph is not connected – no spanning tree exists.");
        }

        // Count number of unique edges (only u < v to avoid duplicates)
        int edgesCount = 0;
        for (int u = 0; u < N; ++u) {
            Node* neighbor = g.getHead(u);
            while (neighbor != nullptr) {
                int v = neighbor->getVal();
                if (u < v) {
                    edgesCount++;
                }
                neighbor = neighbor->getNext();
            }
        }

        // Extract all edges into an array
        Node** edges = new Node*[edgesCount];
        int edgeIndex = 0;

        for (int u = 0; u < N; ++u) {
            Node* neighbor = g.getHead(u);
            while (neighbor != nullptr) {
                int v = neighbor->getVal();
                int w = neighbor->getWeight();
                if (u < v) {
                    edges[edgeIndex++] = new Node(u, w, v, nullptr);  // Store as (src=u, weight=w, val=v)
                }
                neighbor = neighbor->getNext();
            }
        }

        // Sort edges by weight using Bubble Sort (can be replaced with better sort if needed)
        for (int i = 0; i < edgesCount - 1; ++i) {
            for (int j = 0; j < edgesCount - i - 1; ++j) {
                if (edges[j]->getWeight() > edges[j + 1]->getWeight()) {
                    Node* temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }

        // Initialize the MST and Union-Find structure
        Graph mst(N);
        UnionFind uf(N);

        // Build MST by adding edges that connect disjoint sets
        for (int i = 0; i < edgesCount; ++i) {
            int u = edges[i]->getSrc();
            int v = edges[i]->getVal();
            int w = edges[i]->getWeight();

            if (!uf.connected(u, v)) {
                mst.addEdge(u, v, w);
                uf.unionSets(u, v);
            }
        }

        // Clean up allocated edge nodes
        for (int i = 0; i < edgesCount; ++i) {
            delete edges[i];
        }
        delete[] edges;

        return mst;
    }

}

