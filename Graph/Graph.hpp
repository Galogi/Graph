#ifndef GRAPH_H
#define GRAPH_H

/**
 * @file Graph.hpp
 * @brief Defines the Node and Graph classes for representing an undirected weighted graph
 *        using an adjacency list representation.
 * @author galogimaymon@gmail.com
 */

namespace graph {

    /**
     * @struct Node
     * @brief Represents a node in the adjacency list of a graph.
     */
    struct Node {
    private:
        const int val;       ///< The destination vertex.
        const int weight;    ///< The weight of the edge.
        int src;             ///< The source vertex.
        Node* next;          ///< Pointer to the next node in the list.

    public:
        /**
         * @brief Constructs a new Node.
         * @param val The destination vertex.
         * @param weight The weight of the edge.
         * @param src The source vertex.
         * @param next Pointer to the next node (default: nullptr).
         */
        Node(int val, int weight, int src, Node* next = nullptr)
            : val(val), weight(weight), src(src), next(next) {}

        int getVal() const { return val; }
        int getWeight() const { return weight; }
        int getSrc() const { return src; }

        Node* getNext() const { return next; }
        void setNext(Node* newNext) { next = newNext; }
    };

    /**
     * @class Graph
     * @brief Represents an undirected weighted graph using an adjacency list.
     */
    class Graph {
        const int N;         ///< Number of vertices.
        Node** head;         ///< Array of adjacency list heads.

        /**
         * @brief Creates a new adjacency list node.
         * @param dest The destination vertex.
         * @param weight The weight of the edge.
         * @param src The source vertex.
         * @param head The current head of the list.
         * @return Pointer to the new Node.
         */
        Node* getAdjListNode(int dest, int weight, int src, Node* head);

    public:
        /**
         * @brief Constructs a new Graph with a given number of vertices.
         * @param N The number of vertices.
         */
        Graph(int N);

        /**
         * @brief Destructor that frees allocated memory.
         */
        ~Graph();

        /**
         * @brief Adds an undirected edge between two vertices.
         * @param src Source vertex.
         * @param dest Destination vertex.
         * @param weight Weight of the edge (default: 1).
         */
        void addEdge(int src, int dest, int weight = 1);

        /**
         * @brief Removes the edge between two vertices (both directions).
         * @param src Source vertex.
         * @param dest Destination vertex.
         */
        void removeEdge(int src, int dest);

        /**
         * @brief Prints the entire adjacency list of the graph.
         */
        void print_graph();

        /**
         * @brief Prints the tree representation (for traversal results).
         */
        void print_Tree();

        /**
         * @brief Returns the head of the adjacency list for a given vertex.
         * @param v The vertex index.
         * @return Pointer to the head node.
         */
        Node* getHead(int v) const;

        /**
         * @brief Returns the number of vertices in the graph.
         * @return Number of vertices.
         */
        int getSize() const;

        /**
         * @brief Copy constructor.
         * @param other The graph to copy.
         */
        Graph(const Graph& other);

        /**
         * @brief Copy assignment operator.
         * @param other The graph to assign.
         * @return Reference to this graph.
         */
        Graph& operator=(const Graph& other);
    };

}

#endif

