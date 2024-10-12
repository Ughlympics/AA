#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class UnionFind {
private:
    std::vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; 
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void union_sets(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            }
            else if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            }
            else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
        }
    }
};

struct Edge {
    int u, v, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class KruskalMST {
private:
    std::vector<Edge> edges;
    int numVertices;

public:
    KruskalMST(int vertices) : numVertices(vertices) {}

    void addEdge(int u, int v, int weight) {
        edges.push_back({ u, v, weight });
    }

    void findMST() {
        std::sort(edges.begin(), edges.end()); 
        UnionFind uf(numVertices);
        std::vector<Edge> mstEdges;

        for (const auto& edge : edges) {
            if (uf.find(edge.u) != uf.find(edge.v)) {
                mstEdges.push_back(edge);
                uf.union_sets(edge.u, edge.v);
            }
        }

        std::cout << "Edges in the Minimum Spanning Tree:\n";
        for (const auto& edge : mstEdges) {
            std::cout << edge.u << " - " << edge.v << " : " << edge.weight << '\n';
        }
    }
};