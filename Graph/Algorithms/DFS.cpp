#include "DFS.hpp"
#include "../STL/Queue.hpp"
#include <iostream>
#include <climits>
#include "../STL/Stack.hpp"

namespace graph {

    Graph** DFS::run(const Graph& g, int start, int& numComponents) {
        int N = g.getSize();
        bool* visited = new bool[N]();
        Graph** dfsTrees = new Graph*[N];  
        Stack stack(N);
        int componentCount = 0;

       
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
            }componentCount++;
            
              
        }

        
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

    bool DFS::isConnected(const Graph& g) {
        int numComponents;
        Graph** forest = DFS::run(g, 0, numComponents);

        for (int i = 0; i < numComponents; ++i)
            delete forest[i];
        delete[] forest;

        return numComponents == 1; 
    }
}


