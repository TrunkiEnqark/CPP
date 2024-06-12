#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int LOG = 20;

int n, m;
bool is_mst[N];
vector<pair<int, int>> mst[N];
vector<pair<int, pair<int, int>>> edges;

struct DSU {
    int par[N];

    DSU() {
        memset(par, -1, sizeof par);
    }

    int set_find(int u) {
        if (par[u] == -1) return u;
        return par[u] = set_find(par[u]);
    }

    bool union_sets(int u, int v) {
        u = set_find(u);
        v = set_find(v);
        if (u == v) return false;
        par[v] = u;
        return true;
    }
} dsu;

struct LCA {
    int up[N][LOG + 1];
    int max_edge[N][LOG + 1];
    int min_edge[N][LOG + 1];
    int depth[N];

    LCA() {
        memset(up, 0, sizeof up);
        memset(max_edge, 0, sizeof max_edge);
        memset(min_edge, 0, sizeof min_edge);
        memset(depth, 0, sizeof depth);
    }

    void dfs(int u) {
        for (auto i : mst[u]) {
            int w = i.first;
            int v = i.second;
            if (v == up[u][0]) continue;
            
            depth[v] = depth[u] + 1;

            up[v][0] = u;
            max_edge[v][0] = w;
            min_edge[v][0] = w;
            for (int j = 1; j < LOG; ++j) {
                up[v][j] = up[up[v][j - 1]][j - 1];
                max_edge[v][j] = max(max_edge[v][j - 1], max_edge[up[v][j - 1]][j - 1]);
                min_edge[v][j] = min(min_edge[v][j - 1], min_edge[up[v][j - 1]][j - 1]);
            }

            dfs(v);
        }
    }

    pair<int, int> find_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        
        pair<int, int> res = {INT_MAX, INT_MIN};
        int k = depth[u] - depth[v];
        for (int i = 0; (1 << i) <= k; ++i) 
            if (k & (1 << i)) {
                res.first = min(res.first, min_edge[u][i]);
                res.second = max(res.second, max_edge[u][i]);
                u = up[u][i];
            }

        if (u == v) return res;

        k = __lg(depth[u]);
        for (int i = k; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                res.first = min({res.first, min_edge[u][i], min_edge[v][i]});
                res.second = max({res.second, max_edge[u][i], max_edge[v][i]});
                u = up[u][i];
                v = up[v][i];
            }
        }
        res.first = min({res.first, min_edge[u][0], min_edge[v][0]});
        res.second = max({res.second, max_edge[u][0], max_edge[v][0]});
        return res;
    }

    void init() {
        depth[1] = 0;
        dfs(1);
    }

    int get_diff(int u, int v) {
        auto res = find_lca(u, v);
        return res.first;
    }
} lca;

void kruskal() {
    sort(edges.begin(), edges.end(), [] (pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) { return a.first > b.first; });
    memset(is_mst, false, sizeof is_mst);
    for (int i = 0; i < m; ++i) {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if (dsu.union_sets(u, v)) {
            is_mst[i] = true;
            mst[u].push_back({w, v});
            mst[v].push_back({w, u});
        }
    }
}

void print_mst() {
    for (int i = 1; i <= n; ++i) {
        cout << "Adj of " << i << ": ";
        for (auto j : mst[i]) {
            cout << j.second << ", "; 
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    for (int t = 0; t < m; ++t) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    kruskal();
    lca.init();

    // print_mst();

    long long res = 0;
    for (int i = 0; i < m; ++i) {
        if (!is_mst[i]) {
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int w = edges[i].first;
            int c = lca.get_diff(u, v);
            res += abs(w - c);
        }
    }
    cout << res;
}   