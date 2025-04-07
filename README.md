# Graph Project

This project implements key graph algorithms and supporting data structures in modern C++ .  
It includes manual implementations (without STL) of BFS, DFS, Dijkstra, Prim, and Kruskal algorithms, as well as data structures such as Queue, Stack, Union-Find, and Priority Queue.

---

##  Project Structure

```
graph_project/
├── main.cpp
├── make_test.cpp
├── Graph.cpp / Graph.hpp
├── EdgeExistsException.hpp
├── Algorithms/
│   ├── BFS.cpp
│   ├── DFS.cpp
│   ├── Dijkstra.cpp
│   ├── Prim.cpp
│   └── Kruskal.cpp
├── STL/
│   ├── Queue.cpp / Queue.hpp
│   ├── Stack.cpp / Stack.hpp
│   ├── PriorityQueue.cpp / PriorityQueue.hpp
│   └── UnionFind.cpp / UnionFind.hpp
└── Makefile
```

---

##  Modules Overview

| Module/Class         | Description |
|----------------------|-------------|
| `Graph`              | Graph implementation using adjacency lists |
| `Algorithms`         | Collection of static methods: `bfs`, `dfs`, `dijkstra`, `prim`, `kruskal` |
| `Queue / Stack`      | Basic data structures used in traversals |
| `PriorityQueue`      | Used in Dijkstra's algorithm |
| `UnionFind`          | Used in Kruskal's algorithm |
| `main.cpp`           | Demo for running algorithms on sample graphs |
| `make_test.cpp`      | Optional: Unit tests for components |

---

##  Build and Run


| Command            | Description                                |
|-------------------|--------------------------------------------|
| `make Main`        | Compile the main demo                     |
| `make test`        | Compile and run unit tests (if present)   |
| `make valgrind`    | Run Valgrind to check for memory leaks    |
| `make clean`       | Remove all compiled files                 |



##  Unit Testing

Unit tests (if present) reside in `make_test.cpp`.  
They verify:
- Graph creation
- Edge addition/removal
- Correct output of algorithms
- Edge case handling



##  Memory Safety

Memory usage is tested using Valgrind:

```bash
valgrind --leak-check=full ./Main
```

Expected output:
```
All heap blocks were freed -- no leaks are possible
```



## Requirements

- g++ compiler (C++17 support)
- Linux / WSL environment
- [Optional] Valgrind

---
his project was completed with assistance from various sources, including:

## ChatGPT (OpenAI) – used to:
- Clarifying the behavior and differences between **BFS** and **DFS**.
- Understanding how to build **shortest path trees** from Dijkstra's algorithm.
- Improving memory management and integrating **Valgrind** into the build process.
- Optimizing the structure of the `Algorithms` class and modularizing code.
- Writing a professional `Makefile` with support for multiple targets.
- Formatting a clean, GitHub-ready `README.md`.

#### Example Questions Asked:
- “What does DFS do and when should I use it over BFS?”
- “Why is my DFS tree missing some nodes in a disconnected graph?”
- “How do I detect memory leaks using Valgrind and interpret its output?”
- “What’s the difference between stack and heap memory in C++?”
- “When should I pass a variable as a `const` reference vs. by value?”
- “What is the proper way to handle input validation in graph constructors?”
- “How do I prevent duplicate edges when building graphs?”
- “What’s the difference between a tree and a graph in terms of structure?”


## youtubr:

https://www.youtube.com/watch?v=cl1p4SE29OY

These videos were helpful for:
- Understanding the design of the `Graph` class using adjacency lists.

## Classroom Materials

- Core logic and pseudocode for Dijkstra, BFS, DFS, Prim, and Kruskal were based on algorithms provided in class lectures and course slides.




Gal MAYMON 
Computer Science Student,
Ariel University.  
