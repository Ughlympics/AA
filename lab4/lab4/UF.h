#pragma once
#include <vector>
#include <iostream>

class UF {
private:
    std::vector<int> id; 
    std::vector<int> sz; 
    int cnt; 

public:
    UF(int N) : id(N), sz(N, 1), cnt(N) {
        for (int i = 0; i < N; ++i) {
            id[i] = i;
        }
    }

    UF(const UF&) = delete;
    UF& operator=(const UF&) = delete;

    int find(int p) {
        int root = p;
        while (root != id[root]) {
            root = id[root];
        }
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        if (sz[rootX] < sz[rootY]) {
            id[rootX] = rootY;
            sz[rootY] += sz[rootX];
        }
        else {
            id[rootY] = rootX;
            sz[rootX] += sz[rootY];
        }

        --cnt;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int count() const {
        return cnt;
    }
};
