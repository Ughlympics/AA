#pragma once
#include <cstdlib>
#include <ctime>
#include "MainGraph.h"
class RandomGraph :
    public MainGraph
{
    RandomGraph(int n, double p, int minWeight = 1, int maxWeight = 10) : MainGraph(n) {
        srand(time(0));

        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                double prob = (double)rand() / RAND_MAX;  
                if (prob <= p) {
                    int weight = minWeight + rand() % (maxWeight - minWeight + 1);
                    addEdge(u, v, weight);
                    addEdge(v, u, weight);
                }
            }
        }
    }

    void addEdge(int u, int v, int weight) override {
        if (u >= n || v >= n)
            throw std::invalid_argument("Vertex out of bounds");
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    void removeEdge(int u, int v) override {
        if (u >= n || v >= n) throw std::invalid_argument("Vertex out of bounds");
        adjMatrix[u][v] = 0;
    }

    void removeVertex(int v) override {
        throw std::runtime_error("Remove vertex not implemented");
    }
};

