#include "Graph.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include "EdgeExistsException.hpp"
using namespace std;

namespace graph {

Node* Graph::getAdjListNode(int dest, int weight,int src , Node* head) {
    return new Node(dest, weight, src ,head); 
}

Graph::Graph(int N) : N(N) {
    head = new Node*[N];
    for (int i = 0; i < N; i++)
        head[i] = nullptr;
}

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

void Graph::addEdge(int src, int dest, int weight) {
    
    if (src < 0 || src >= N || dest < 0 || dest >= N) {
        std::ostringstream msg;
        msg << "Invalid edge: src=" << src << ", dest=" << dest << " (allowed range: 0 to " << (N - 1) << ")";
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

   
    Node* newNode = getAdjListNode(dest, weight,src, head[src]);
    head[src] = newNode;

    newNode = getAdjListNode(src, weight,src ,head[dest]);
    head[dest] = newNode;
}

void Graph::removeEdge(int src, int dest) {
    
    if (src < 0 || src >= N || dest < 0 || dest >= N) {
        throw std::out_of_range("Source or destination node index is out of bounds.");
    }

    bool removed = false;
    Node* prev = nullptr;
    Node* curr = head[src];

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

void Graph::print_graph() {
    for (int i = 0; i < N; i++) {
        cout <<  "Vertex " << i << " --> ";
        Node* ptr = head[i];
        while (ptr != nullptr) {
            cout << "(" << ptr->getVal() << ", w=" << ptr->getWeight() << ") ";
            ptr = ptr->getNext();
        }
        cout << endl;
    }cout << "\n"  << endl;
}
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


Node* Graph::getHead(int v) const {
    return head[v];
}

int Graph::getSize() const {
    return N;
}



}