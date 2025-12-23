#include<iostream>
#include<vector>
using namespace std;

struct DSU {
    vector<int> parent;

    DSU(int n){
        parent.resize(n);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b)
            parent[b] = a;
    }
    void reset(int x) {
        parent[x] = x;
    }
};