// File: DFS.cpp
// Author: galogimaymon@gmail.com
// Description: Implements Depth-First Search (DFS) for an undirected graph.
//              Supports multiple connected components and provides a method to check graph connectivity.

#include "DFS.hpp"
#include "../STL/Queue.hpp"
#include <iostream>
#include <climits>
#include "../STL/Stack.hpp"

namespace graph {

    /**
     * @brief Runs DFS on a given graph starting from the given node, and continues to find all connected components.
     *        For each component found, a corresponding DFS tree (Graph) is created.
     * 
     * @param g The input graph.
     * @param start The starting vertex for the first DFS.
     * @param numComponents Output parameter: the number of connected components found.
     * @return Graph** An array of pointers to Graph objects representing each DFS tree.
     * 
     * @note The caller is responsible for deleting the returned Graph pointers and the array itself.
     */
    Graph** DFS::run(const Graph& g, int start, int& numComponents) {
        int N = g.getSize();
        bool* visited = new bool[N]();          // Track visited nodes
        Graph** dfsTrees = new Graph*[N];       // Array to hold trees for each component
        Stack stack(N);
        int componentCount = 0;

        // Run DFS from starting node (if not already visited)
        if (!visited[start]) {
            dfsTrees[componentCount] = new Graph(N);
            stack.push(start);
            visited[start] = true;

            while (!stack.isEmpty()) {
                int curr = stack.pop();
                Node* neighbor = g.getHead(curr);

                while (neighbor != nullptr) {
                    int next = neighbor->getVal();
                    if (!visited[next]) {
                        visited[next] = true;
                        dfsTrees[componentCount]->addEdge(curr, next, neighbor->getWeight());
                        stack.push(next);
                    }
                    neighbor = neighbor->getNext();
                }
            }
            componentCount++;
        }

        // Continue DFS for unvisited nodes to find other components
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                Graph* tempGraph = new Graph(N);
                stack.push(i);
                visited[i] = true;
                bool hasEdge = false;

                while (!stack.isEmpty()) {
                    int curr = stack.pop();
                    Node* neighbor = g.getHead(curr);

                    while (neighbor != nullptr) {
                        int next = neighbor->getVal();
                        if (!visited[next]) {
                            visited[next] = true;
                            tempGraph->addEdge(curr, next, neighbor->getWeight());
                            stack.push(next);
                            hasEdge = true;
                        }
                        neighbor = neighbor->getNext();
                    }
                }

                // Add only non-empty components to the result
                if (hasEdge) {
                    dfsTrees[componentCount++] = tempGraph;
                } else {
                    delete tempGraph;
                }
            }
        }

        numComponents = componentCount;
        delete[] visited;
        return dfsTrees;
    }

    /**
     * @brief Checks if the graph is fully connected using DFS.
     * 
     * @param g The graph to check.
     * @return true If the graph has only one connected component.
     * @return false If the graph has more than one component.
     */
    bool DFS::isConnected(const Graph& g) {
        int numComponents;
        Graph** forest = DFS::run(g, 0, numComponents);

        // Clean up allocated DFS trees
        for (int i = 0; i < numComponents; ++i)
            delete forest[i];
        delete[] forest;

        return numComponents == 1;
    }

}


