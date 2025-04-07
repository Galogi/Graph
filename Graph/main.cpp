#include "Graph.hpp"
#include <iostream>
#include "EdgeExistsException.hpp"
#include "Algorithms.hpp"
#include <cassert>
#include "AlgorithmType.hpp"
using namespace std;
using namespace graph;


int main() {
   
    Graph g(10);
    try {
        g.addEdge(0, 1, 2);
        g.addEdge(0, 2, 2);
        g.addEdge(1, 2, 3);

        g.addEdge(4, 5, 1);
        g.addEdge(6, 5, 1);
        g.addEdge(6, 7, 1);
        g.addEdge(7, 5, 1);
        g.addEdge(8, 5, 1);
        g.addEdge(4, 8, 1);

       
    } catch (const EdgeExistsException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "Graph structure:\n";
    g.print_graph();

   
  
    int numComponents;
    Graph** dfsForest = Algorithms::run(g, AlgorithmType::DFS, 0, numComponents);
    std::cout << "\nDFS Forest (from node 0):\n";
    for (int i = 0; i < numComponents; ++i) {
        std::cout << "Tree #" << (i + 1) << ":\n";
        dfsForest[i]->print_Tree();
        delete dfsForest[i];
    }
    delete[] dfsForest;

    
    Graph bfsTree = Algorithms::run(g, AlgorithmType::BFS, 0);
    std::cout << "\nBFS Tree (from node 0):\n";
    bfsTree.print_Tree();

    
    Graph dijkstraTree = Algorithms::run(g, AlgorithmType::Dijkstra, 0);
    std::cout << "\nDijkstra Tree (from node 0):\n";
    dijkstraTree.print_Tree();

    
    try {
        Graph primTree = Algorithms::run(g, AlgorithmType::Prim);
        std::cout << "\nPrim Tree:\n";
        primTree.print_Tree();
    } catch (const std::invalid_argument& e) {
        std::cerr << "Prim Error: " << e.what() << std::endl;
    }

    
    try {
        Graph kruskalTree = Algorithms::run(g, AlgorithmType::Kruskal);
        std::cout << "\nKruskal Tree:\n";
        kruskalTree.print_Tree();
    } catch (const std::invalid_argument& e) {
        std::cerr << "Kruskal Error: " << e.what() << std::endl;
    }
    Graph gg(3);
    gg.addEdge(0, 1, 1);
    gg.addEdge(1, 2, 2);
    gg.print_graph();
    try {
    Graph mst = Algorithms::run(gg, AlgorithmType::Kruskal);
    
    std::cout << "\nKruskal Tree:\n";
        mst.print_Tree();
    } catch (const std::invalid_argument& e) {
        std::cerr << "Kruskal Error: " << e.what() << std::endl;
    }
    Graph** mst2 = Algorithms::run(gg, AlgorithmType::DFS, 0, numComponents);
    std::cout << "\nDFS Forest (from node 0):\n";
    for (int i = 0; i < numComponents; ++i) {
        std::cout << "Tree #" << (i + 1) << ":\n";
        mst2[i]->print_Tree();
        delete mst2[i];
    }
    delete[] mst2;
    

    return 0;

}