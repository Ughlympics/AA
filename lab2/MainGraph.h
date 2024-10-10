#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

class MainGraph {
protected:
    int n;  
    std::vector<std::vector<int>> adjMatrix; 
    std::vector<std::vector<std::pair<int, int>>> adjList;

public:
    MainGraph(int n) : n(n) {
        adjMatrix.resize(n, std::vector<int>(n, 0));
    }

    virtual void addVertex() {
        n++;
        for (auto& row : adjMatrix) {
            row.push_back(0);  
        }
        adjMatrix.push_back(std::vector<int>(n, 0));  
    }

    void matrixToList() {
        adjList.clear();
        adjList.resize(n);

        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (adjMatrix[u][v] != 0) {
                    adjList[u].push_back({ v, adjMatrix[u][v] });
                }
            }
        }
    }

    void listToMatrix() {
        adjMatrix.clear();
        adjMatrix.resize(n, std::vector<int>(n, 0));

        for (int u = 0; u < n; u++) {
            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                adjMatrix[u][v] = weight;
            }
        }
    }

    virtual void addEdge(int u, int v, int weight) = 0;

    virtual void removeVertex(int v) = 0;

    virtual void removeEdge(int u, int v) = 0;

    virtual void printMatrix() const {
        for (const auto& row : adjMatrix) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
};