#include "BFS.hpp"
#include "../STL/Queue.hpp"
#include <iostream>
#include <climits>
#include "../STL/Stack.hpp"


namespace graph {



    Graph BFS::run(const Graph& g, int start) {
        int N = g.getSize();
        bool* visited = new bool[N]();  
        int* distances = new int[N];     
        Graph bfsTree(N);                
        Queue q(N);                      
    
        for (int i = 0; i < N; ++i) distances[i] =  INT_MAX;  
    
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
                    bfsTree.addEdge(curr, next, neighbor->getWeight());  
                }
                neighbor = neighbor->getNext(); 
            }
        }
    
        std::cout <<"\n" << "\033[1mBFS distance: \033[0m\n" << std::endl;
        for (int i = 0; i < N; ++i) {
            std::cout << "Distance from " << start << " to " << i << " is " << distances[i] << std::endl;
        }
    
        delete[] visited;
        delete[] distances;
        return bfsTree;
    }

    }