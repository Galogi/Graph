#include "Dijkstra.hpp"
#include "../STL/Queue.hpp"
#include "../STL/PriorityQueue.hpp"
#include "../STL/Stack.hpp"
#include <iostream>
#include <climits>



namespace graph {



    Graph Dijkstra::run(const Graph& g, int start) {
			int N = g.getSize();
	
	   
			 for (int i = 0; i < N; ++i) {
				Node* neighbor = g.getHead(i);
				while (neighbor != nullptr) {
					if (neighbor->getWeight() < 0) {
					throw std::invalid_argument("Dijkstra algorithm does not support negative edge weights.");
				}
				neighbor = neighbor->getNext();
			}
		}
			int* distances = new int[N];
			bool* visited = new bool[N]();
			Graph shortestPaths(N);
		
		   
			for (int i = 0; i < N; ++i) {
				distances[i] = INT_MAX;  
			}
			distances[start] = 0;
		
		   
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
				
					
					
			bool* visitedSP = new bool[N]();
			Stack stack(N);
			stack.push(start);
			visitedSP[start] = true;
			int count = 1;
	
			while ((!stack.isEmpty() && count < N)) {
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
	
			delete[] visitedSP;
	
	
	
		
			
			std::cout << "\n\033[1mDijkstra distance: \033[0m\n" << std::endl;
			for (int i = 0; i < N; ++i) {
				std::cout << "Distance from " << start << " to " << i << " is " << distances[i] << std::endl;
			}
		
			delete[] distances;
			delete[] visited;
			return shortestPaths;
		}
}