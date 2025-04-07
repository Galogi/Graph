// Author: galogimaymon@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Graph.hpp"
#include "Algorithms.hpp"
#include "AlgorithmType.hpp"
#include "EdgeExistsException.hpp"

using namespace graph;

TEST_CASE("DFS returns correct number of trees in forest") {
    Graph g(6);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(3, 4, 1);

    int numTrees;
    Graph** trees = Algorithms::run(g, AlgorithmType::DFS, 0, numTrees);
    CHECK(numTrees == 2);

    for (int i = 0; i < numTrees; ++i)
        delete trees[i];
    delete[] trees;
}

TEST_CASE("Dijkstra finds correct distances") {
    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 3, 10);

    Graph dijkstra = Algorithms::run(g, AlgorithmType::Dijkstra, 0);
    Node* head = dijkstra.getHead(0);

    bool found1 = false, found3 = false;
    while (head != nullptr) {
        if (head->getVal() == 1) found1 = true;
        if (head->getVal() == 3) found3 = true;
        head = head->getNext();
    }
    CHECK(found1);
    CHECK(found3);
}

TEST_CASE("BFS marks unreachable nodes correctly") {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);

    Graph bfs = Algorithms::run(g, AlgorithmType::BFS, 0);
    CHECK(bfs.getHead(4) == nullptr);
}

TEST_CASE("Prim MST has n-1 edges") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);

    Graph mst = Algorithms::run(g, AlgorithmType::Prim);
    int count = 0;
    for (int i = 0; i < g.getSize(); ++i) {
        Node* curr = mst.getHead(i);
        while (curr != nullptr) {
            count++;
            curr = curr->getNext();
        }
    }

    CHECK((count / 2) == g.getSize() );
}

TEST_CASE("Kruskal MST has n-1 edges") {
    Graph g(3);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);

    Graph mst = Algorithms::run(g, AlgorithmType::Kruskal);
    int count = 0;
    for (int i = 0; i < g.getSize(); ++i) {
        Node* curr = mst.getHead(i);
        while (curr != nullptr) {
            count++;
            curr = curr->getNext();
        }
    }

    CHECK((count / 2) == g.getSize() - 1);
}

TEST_CASE("Duplicate edge throws exception") {
    Graph g(3);
    g.addEdge(0, 1, 1);
    CHECK_THROWS_AS(g.addEdge(0, 1, 1), EdgeExistsException);
}

TEST_CASE("Dijkstra throws on negative edge weight") {
    Graph g(3);
    g.addEdge(0, 1, -1);
    CHECK_THROWS_AS(Algorithms::run(g, AlgorithmType::Dijkstra, 0), std::invalid_argument);
}
