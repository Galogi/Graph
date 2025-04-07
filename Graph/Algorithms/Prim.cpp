#include "Prim.hpp"
#include "../STL/Queue.hpp"
#include <iostream>
#include <climits>
#include "../STL/Stack.hpp"
#include "../STL/PriorityQueue.hpp"
#include "DFS.hpp"


namespace graph {



    Graph Prim::run(const Graph& g) {
        int N = g.getSize();
        bool* inMST = new bool[N]();  
        int* key = new int[N];         
        int* parent = new int[N];  
        if (!DFS::isConnected(g)) {
            delete[] inMST;
            delete[] key;
            delete[] parent;
            throw std::invalid_argument("Prim Error: Graph is not connected  no spanning tree exists.");
        }    
        
        
        for (int i = 0; i < N; ++i) {
            key[i] = INT_MAX;         
            parent[i] = -1;           
        }
    
        key[0] = 0;  
        inMST[0] = true;  
    
        Graph mst(N);
    
       
        PriorityQueue pq(N);
    
        pq.enqueue(0, 0);  
    
        while (!pq.isEmpty()) {
            int u = pq.dequeue();  
    
            Node* neighbor = g.getHead(u); 
            while (neighbor != nullptr) {
                int v = neighbor->getVal();
                int weight = neighbor->getWeight();
    
                
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    pq.enqueue(v, key[v]);  
    
                    mst.addEdge(u, v, weight);  
                }
                neighbor = neighbor->getNext();
            }
        }
    
        delete[] inMST;
        delete[] key;
        delete[] parent;
        return mst;
    }

    }