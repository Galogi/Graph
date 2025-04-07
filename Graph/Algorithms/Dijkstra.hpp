#pragma once
#include "../Graph.hpp"

namespace graph {
    class Dijkstra {
    public:
        static Graph run(const Graph& g, int start);
    };
}
