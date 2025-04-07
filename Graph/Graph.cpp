// File: Graph.cpp
// Description: Implements an undirected weighted graph using an adjacency list representation.
//              Includes edge insertion, removal, and graph traversal utilities.
// Author: galogimaymon@gmail.com

#include "Graph.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include "EdgeExistsException.hpp"

using namespace std;

namespace graph {

    /**
     * Creates a new adjacency list node.
     *
     * @param dest The destination vertex.
     * @param weight The weight of the edge.
     * @param src The source vertex.
     * @param head Pointer to the next node in the list.
     * @return A pointer to the newly created Node.
     */
    Node* Graph::getAdjListNode(int dest, int weight, int src, Node* head) {
        return new Node(dest, weight, src, head); 
    }

    /**
     * Constructs a Graph with a specified number of vertices.
     *
     * @param N The number of vertices in the graph.
     */
    Graph::Graph(int N) : N(N) {
        head = new Node*[N];
        for (int i = 0; i < N; i++)
            head[i] = nullptr;
    }

    /**
     * Destructor that frees all dynamically allocated memory.
     */
    Graph::~Graph() {
        for (int i = 0; i < N; i++) {
            Node* current = head[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->getNext();
                delete temp;
            }
        }
        delete[] head;
    }

    /**
     * Adds an undirected edge to the graph with a given weight.
     *
     * @param src The source vertex.
     * @param dest The destination vertex.
     * @param weight The weight of the edge.
     * @throws std::out_of_range If src or dest are invalid indices.
     * @throws EdgeExistsException If the edge already exists or src == dest.
     */
    void Graph::addEdge(int src, int dest, int weight) {
        if (src < 0 || src >= N || dest < 0 || dest >= N) {
            std::ostringstream msg;
            msg << "Invalid edge: src=" << src << ", dest=" << dest 
                << " (allowed range: 0 to " << (N - 1) << ")";
            throw std::out_of_range(msg.str());
        }

        if (src == dest) {
            std::ostringstream msg;
            msg << "Invalid edge: source and destination cannot be the same (src=" << src << ")";
            throw EdgeExistsException(msg.str());
        }

        Node* temp = head[src];
        while (temp != nullptr) {
            if (temp->getVal() == dest) {
                std::ostringstream msg;
                msg << "Edge already exists between src=" << src << " and dest=" << dest;
                throw EdgeExistsException(msg.str());
            }
            temp = temp->getNext();
        }

        // Add edge in both directions
        Node* newNode = getAdjListNode(dest, weight, src, head[src]);
        head[src] = newNode;

        newNode = getAdjListNode(src, weight, src, head[dest]);
        head[dest] = newNode;
    }

    /**
     * Removes an undirected edge from the graph.
     *
     * @param src The source vertex.
     * @param dest The destination vertex.
     * @throws std::out_of_range If indices are out of bounds.
     * @throws std::runtime_error If the edge does not exist.
     */
    void Graph::removeEdge(int src, int dest) {
        if (src < 0 || src >= N || dest < 0 || dest >= N) {
            throw std::out_of_range("Source or destination node index is out of bounds.");
        }

        bool removed = false;
        Node* prev = nullptr;
        Node* curr = head[src];

        // Remove from src list
        while (curr != nullptr) {
            if (curr->getVal() == dest) {
                if (prev == nullptr)
                    head[src] = curr->getNext();
                else
                    prev->setNext(curr->getNext());
                delete curr;
                removed = true;
                break;
            }
            prev = curr;
            curr = curr->getNext();
        }

        // Remove from dest list
        prev = nullptr;
        curr = head[dest];
        while (curr != nullptr) {
            if (curr->getVal() == src) {
                if (prev == nullptr)
                    head[dest] = curr->getNext();
                else
                    prev->setNext(curr->getNext());
                delete curr;
                break;
            }
            prev = curr;
            curr = curr->getNext();
        }

        if (!removed)
            throw std::runtime_error("Edge does not exist!");
    }

    /**
     * Prints the entire graph's adjacency list.
     */
    void Graph::print_graph() {
        for (int i = 0; i < N; i++) {
            cout << "Vertex " << i << " --> ";
            Node* ptr = head[i];
            while (ptr != nullptr) {
                cout << "(" << ptr->getVal() << ", w=" << ptr->getWeight() << ") ";
                ptr = ptr->getNext();
            }
            cout << endl;
        }
        cout << "\n" << endl;
    }

    /**
     * Prints the adjacency list of the tree (for example, after running BFS/DFS).
     */
    void Graph::print_Tree() {
        for (int i = 0; i < N; i++) {
            Node* ptr = head[i];
            if (ptr == nullptr) continue;

            cout << "Vertex " << i << " --> ";
            while (ptr != nullptr) {
                cout << "(" << ptr->getVal() << ", w=" << ptr->getWeight() << ") ";
                ptr = ptr->getNext();
            }
            cout << endl;
        }
        cout << "\n" << endl;
    }

    /**
     * Returns the head of the adjacency list for a given vertex.
     *
     * @param v The vertex index.
     * @return A pointer to the head of its adjacency list.
     */
    Node* Graph::getHead(int v) const {
        return head[v];
    }

    /**
     * Returns the number of vertices in the graph.
     *
     * @return The number of vertices (N).
     */
    int Graph::getSize() const {
        return N;
    }

}
