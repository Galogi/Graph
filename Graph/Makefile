
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I -g.


SRC_DIR := .
STL_DIR := STL
ALG_DIR := Algorithms


MAIN_SRC := main.cpp
TMAIN_SRC := make_tesr.cpp
GRAPH_SRC := Graph.cpp
ALG_SRC := Algorithms.cpp $(ALG_DIR)/BFS.cpp $(ALG_DIR)/DFS.cpp $(ALG_DIR)/Dijkstra.cpp $(ALG_DIR)/Prim.cpp $(ALG_DIR)/Kruskal.cpp
STL_SRC := $(STL_DIR)/Queue.cpp $(STL_DIR)/Stack.cpp $(STL_DIR)/PriorityQueue.cpp $(STL_DIR)/UnionFind.cpp


MAIN_OBJ := main.o
GRAPH_OBJ := Graph.o
ALG_OBJ := $(ALG_SRC:.cpp=.o)
STL_OBJ := $(STL_SRC:.cpp=.o)


all: main


main: $(MAIN_OBJ) $(GRAPH_OBJ) $(ALG_OBJ) $(STL_OBJ)
	$(CXX) -o $@ $^

main_test: $(TMAIN_SRC) $(GRAPH_OBJ) $(ALG_OBJ) $(STL_OBJ)
	$(CXX) -o $@ $^


graph_only: main_graph_only.o $(GRAPH_OBJ) $(STL_DIR)/Queue.o $(STL_DIR)/Stack.o $(STL_DIR)/PriorityQueue.o
	$(CXX) -o $@ $^


main_graph_only.o: $(MAIN_SRC) Graph.hpp $(STL_DIR)/Queue.hpp $(STL_DIR)/Stack.hpp EdgeExistsException.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

valgrind: main
	valgrind --leak-check=full ./main

valgrind2: main_test
	valgrind --leak-check=full ./main_test


clean:
	rm -f *.o main graph_only main_test
	rm -f $(STL_DIR)/*.o
	rm -f $(ALG_DIR)/*.o
