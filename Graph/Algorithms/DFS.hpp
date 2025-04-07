#pragma once
#include "../Graph.hpp"

namespace graph {
    class DFS {
    public:
        static Graph** run(const Graph& g, int start, int& numComponents);
        static bool isConnected(const Graph& g); 
    };
}
