// File: UnionFind.cpp
// Author: galogimaymon@gmail.com
// Description: Implementation of the Union-Find (Disjoint Set Union - DSU) data structure
//              with path compression and union by rank optimizations.

#include "UnionFind.hpp"

/**
 * @brief Constructs a Union-Find structure with n elements.
 *        Each element initially belongs to its own set.
 * @param n The number of elements.
 */
UnionFind::UnionFind(int n) {
    size = n;
    parent = new int[n];
    rank = new int[n];

    for (int i = 0; i < n; ++i) {
        parent[i] = i;  // Each node is its own parent
        rank[i] = 0;    // Initial rank is 0
    }
}

/**
 * @brief Destructor to free allocated memory.
 */
UnionFind::~UnionFind() {
    delete[] parent;
    delete[] rank;
}

/**
 * @brief Finds the representative (root) of the set containing x.
 *        Applies path compression for efficiency.
 * @param x The element to find.
 * @return int The root of the set containing x.
 */
int UnionFind::find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // Path compression
    }
    return parent[x];
}

/**
 * @brief Merges the sets containing elements x and y.
 *        Uses union by rank to keep tree height minimal.
 * @param x First element.
 * @param y Second element.
 */
void UnionFind::unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        // Attach smaller tree to larger tree based on rank
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

/**
 * @brief Checks whether elements x and y belong to the same set.
 * @param x First element.
 * @param y Second element.
 * @return true If both elements are in the same set.
 * @return false Otherwise.
 */
bool UnionFind::connected(int x, int y) {
    return find(x) == find(y);
}
