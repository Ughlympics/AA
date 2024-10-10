#pragma once
#include "MainGraph.h"
#include <iostream>
#include <stdexcept>
class DirectedGraph : public MainGraph {
public:
    DirectedGraph(int n) : MainGraph(n) {}

    void addEdge(int u, int v, int weight = 0) override {
        if (u >= n || v >= n) throw std::invalid_argument("Vertex out of bounds");
        adjMatrix[u][v] = 1; 
    }

    void removeEdge(int u, int v) override {
        if (u >= n || v >= n) throw std::invalid_argument("Vertex out of bounds");
        adjMatrix[u][v] = 0;
    }

    void removeVertex(int v) override {
        throw std::runtime_error("Remove vertex not implemented");
    }
};

