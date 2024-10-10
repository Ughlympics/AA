#pragma once
#include "MainGraph.h"
#include <iostream>
#include <vector>
#include <stdexcept>
class UndirectedGraph :
    public MainGraph
{
public:
    UndirectedGraph(int n) : MainGraph(n) {}
    void addEdge(int u, int v, int weight = 0) override {
        if (u >= n || v >= n) throw std::invalid_argument("Vertex out of bounds");
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void removeEdge(int u, int v) override {
        if (u >= n || v >= n) throw std::invalid_argument("Vertex out of bounds");
        adjMatrix[u][v] = 0;
        adjMatrix[v][u] = 0; 
    }

    void removeVertex(int v) override {
        throw std::runtime_error("Remove vertex not implemented");
    }
};

