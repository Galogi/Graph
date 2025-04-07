#pragma once
#include "../Graph.hpp"

namespace graph {
    class BFS {
    public:
        static Graph run(const Graph& g, int start);
    };
}
