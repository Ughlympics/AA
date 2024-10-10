#pragma once
#include "MainGraph.h"
#include <iostream>
#include <vector>
#include <stdexcept>
class WeightedGraph :
    public MainGraph
{
    WeightedGraph(int n) : MainGraph(n) {}


    void addEdge(int u, int v, int weight) override {
        if (u >= n || v >= n)
            throw std::invalid_argument("Vertex out of bounds");
        adjMatrix[u][v] = weight;  
        std::cout << "Added weighted edge: " << u << " -> " << v << " with weight " << weight << std::endl;
    }

    void removeEdge(int u, int v) override {
        if (u >= n || v >= n) throw std::invalid_argument("Vertex out of bounds");
        adjMatrix[u][v] = 0;
    }

    void removeVertex(int v) override {
        throw std::runtime_error("Remove vertex not implemented");
    }
};

