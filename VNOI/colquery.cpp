#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct DSU {
    int parent[N], sz[N];
    vector<map<int, int>> colors;

    void make_set(int u, int color) {
        parent[u] = u;
        sz[u] = 1;
        colors[u][color] = 1;
    }

    int find_set(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find_set(parent[u]);
    }

    void update(int u, int v) {
        for (auto p : colors[v]) {
            colors[u][p.first] += p.second;
        }
        colors[v].clear();
    }

    void union_sets(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u != v) {
            if (sz[u] < sz[v]) swap(u, v);
            parent[v] = u;
            update(u, v);
            sz[u] += sz[v];
        }
    }

    int count_color(int u, int color) {
        u = find_set(u);
        if (colors[u].find(color) != colors[u].end()) return colors[u][color];
        return 0;
    }
} dsu;

int n, q;

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> q;
    dsu.colors.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        dsu.make_set(i, d);
    }   
    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            dsu.union_sets(u, v);
        } else {
            cout << dsu.count_color(u, v) << '\n';
        }
    }
}