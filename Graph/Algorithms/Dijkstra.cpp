// File: Dijkstra.cpp
// Author: galogimaymon@gmail.com
// Description: Implements Dijkstra's algorithm for shortest paths in a weighted graph
//              with non-negative edge weights. Returns a tree representing the shortest paths from a start node.

#include "Dijkstra.hpp"
#include "../STL/Queue.hpp"
#include "../STL/PriorityQueue.hpp"
#include "../STL/Stack.hpp"
#include <iostream>
#include <climits>

namespace graph {

    /**
     * @brief Runs Dijkstra's algorithm from a given starting node and builds a graph of shortest paths.
     * 
     * @param g The input graph.
     * @param start The starting vertex.
     * @return Graph A new Graph object representing the shortest path tree from the start node.
     * 
     * @throws std::invalid_argument If the graph contains a negative edge weight.
     */
    Graph Dijkstra::run(const Graph& g, int start) {
        int N = g.getSize();

        // Validate: Dijkstra cannot handle negative weights
        for (int i = 0; i < N; ++i) {
            Node* neighbor = g.getHead(i);
            while (neighbor != nullptr) {
                if (neighbor->getWeight() < 0) {
                    throw std::invalid_argument("Dijkstra algorithm does not support negative edge weights.");
                }
                neighbor = neighbor->getNext();
            }
        }

        // Initialize distances and visited array
        int* distances = new int[N];
        bool* visited = new bool[N]();
        Graph shortestPaths(N);

        for (int i = 0; i < N; ++i) {
            distances[i] = INT_MAX;
        }
        distances[start] = 0;

        // Priority queue for Dijkstra
        PriorityQueue pq(N);
        pq.enqueue(start, 0);

        while (!pq.isEmpty()) {
            int curr = pq.dequeue();
            if (visited[curr]) continue;
            visited[curr] = true;

            Node* neighbor = g.getHead(curr);
            while (neighbor != nullptr) {
                int next = neighbor->getVal();
                int weight = neighbor->getWeight();

                if (distances[curr] + weight < distances[next]) {
                    distances[next] = distances[curr] + weight;
                    pq.enqueue(next, distances[next]);
                }

                neighbor = neighbor->getNext();
            }
        }

        // Build the shortest path tree using the distances found
        bool* visitedSP = new bool[N]();
        Stack stack(N);
        stack.push(start);
        visitedSP[start] = true;
        int count = 1;

        while (!stack.isEmpty() && count < N) {
            int curr = stack.pop();
            Node* neighbor = g.getHead(curr);

            while (neighbor != nullptr) {
                int next = neighbor->getVal();
                int weight = neighbor->getWeight();

                if (distances[curr] + weight == distances[next] && !visitedSP[next]) {
                    shortestPaths.addEdge(curr, next, weight);
                    stack.push(next);
                    visitedSP[next] = true;
                    count++;
                }

                neighbor = neighbor->getNext();
            }
        }

        // Print the distances
        std::cout << "\n\033[1mDijkstra distance: \033[0m\n" << std::endl;
        for (int i = 0; i < N; ++i) {
            std::cout << "Distance from " << start << " to " << i << " is " << distances[i] << std::endl;
        }

        // Free allocated memory
        delete[] visitedSP;
        delete[] distances;
        delete[] visited;

        return shortestPaths;
    }

}
