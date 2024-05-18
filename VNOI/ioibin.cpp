#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4;

struct DSU {
    int parent[N], sz[N];

    void make_set(int u) {
        parent[u] = u;
        sz[u] = 1;
    }

    int find_set(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find_set(parent[u]);
    }

    void union_sets(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u != v) {
            if (sz[u] > sz[v]) swap(u, v);
            parent[v] = u;
            sz[u] += sz[v];
        }
    }

    bool is_connected(int u, int v) {
        return find_set(u) == find_set(v);
    }
} dsu;

int main() {
    for (int i = 1; i <= 10000; ++i)
        dsu.make_set(i);
    
    int p;
    cin >> p;
    while (p--) {
        int x, y, type;
        cin >> x >> y >> type;
        if (type == 1) {
            dsu.union_sets(x, y);
        } else {
            cout << dsu.is_connected(x, y) << '\n';
        }
    }
}