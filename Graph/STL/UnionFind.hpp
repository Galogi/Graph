#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP

/**
 * @file UnionFind.hpp
 * @brief Header file for the Union-Find (Disjoint Set Union - DSU) data structure,
 *        implementing union by rank and path compression optimizations.
 * @author galogimaymon@gmail.com
 */

class UnionFind {
private:
    int* parent;  ///< Parent array for disjoint sets.
    int* rank;    ///< Rank array for balancing trees.
    int size;     ///< Number of elements in the structure.

public:
    /**
     * @brief Constructs a Union-Find structure with n elements.
     * @param n The number of elements.
     */
    UnionFind(int n);

    /**
     * @brief Destructor to clean up allocated memory.
     */
    ~UnionFind();

    /**
     * @brief Finds the representative (root) of the set containing x.
     *        Uses path compression to flatten the structure.
     * @param x The element to find.
     * @return The root of the set containing x.
     */
    int find(int x);

    /**
     * @brief Unites the sets containing x and y using union by rank.
     * @param x An element in the first set.
     * @param y An element in the second set.
     */
    void unionSets(int x, int y);

    /**
     * @brief Checks whether x and y are in the same set.
     * @param x First element.
     * @param y Second element.
     * @return true If x and y are connected.
     * @return false Otherwise.
     */
    bool connected(int x, int y);
};

#endif
