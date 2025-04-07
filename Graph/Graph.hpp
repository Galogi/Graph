#ifndef GRAPH_H
#define GRAPH_H

namespace graph {

struct Node {
private:
    const int val;       
    const int weight;
    int src;    
    Node* next;

public:
    Node(int val, int weight,int src ,Node* next = nullptr)
        : val(val), weight(weight),src(src) ,next(next) {}

    int getVal() const { return val; }
    int getWeight() const { return weight; }
    int getSrc() const { return src; }

    Node* getNext() const { return next; }
    void setNext(Node* newNext) { next = newNext; }
};

class Graph {
    const int N;
    Node** head;

    Node* getAdjListNode(int dest, int weight, int src , Node* head);

public:
    Graph(int N);
    ~Graph();

    void addEdge(int src, int dest, int weight = 1);
    void removeEdge(int src, int dest);
    void print_graph();
    void print_Tree();
    Node* getHead(int v) const;
    int getSize() const;
    Graph(const Graph& other);                // copy constructor
    Graph& operator=(const Graph& other);
};

}

#endif
