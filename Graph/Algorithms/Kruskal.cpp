#include "Kruskal.hpp"
#include "../STL/UnionFind.hpp"
#include <iostream>
#include <climits>
#include "DFS.hpp"


namespace graph {

    Graph Kruskal::run(const Graph& g) {
        int N = g.getSize();

        
        if (!DFS::isConnected(g)) {
            throw std::invalid_argument("Prim Error: Graph is not connected – no spanning tree exists.");
        }

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

        Node** edges = new Node*[edgesCount];
        int edgeIndex = 0;

        for (int u = 0; u < N; ++u) {
            Node* neighbor = g.getHead(u);
            while (neighbor != nullptr) {
                int v = neighbor->getVal();
                int w = neighbor->getWeight();
                if (u < v) {
                    edges[edgeIndex++] = new Node(u, v, w, nullptr);
                }
                neighbor = neighbor->getNext();
            }
        }

        
        for (int i = 0; i < edgesCount - 1; ++i) {
            for (int j = 0; j < edgesCount - i - 1; ++j) {
                if (edges[j]->getWeight() > edges[j + 1]->getWeight()) {
                    Node* temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }

        
        Graph mst(N);
        UnionFind uf(N);

        for (int i = 0; i < edgesCount; ++i) {
            int u = edges[i]->getSrc();
            int v = edges[i]->getVal();
            int w = edges[i]->getWeight();

            if (!uf.connected(u, v)) {
                mst.addEdge(u, v, w);
                uf.unionSets(u, v);
            }
        }

        for (int i = 0; i < edgesCount; ++i) {
            delete edges[i];
        }
        delete[] edges;

        return mst;
    }

} 
