#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;

const int LOG = 10;
const int N = 1005;

int n, q, up[N][LOG + 1], dist[N][LOG + 1], height[N];
vector<pair<int, int> > g[N];

void dfs(int u) {
    for (auto i : g[u]) {
        int v = i.second;
        int weight = i.first;
        if (v == up[u][0]) continue;
        height[v] = height[u] + 1;

        up[v][0] = u;
        dist[v][0] = weight;
        for (int j = 1; j < LOG; ++j) {
            up[v][j] = up[up[v][j - 1]][j - 1];
            dist[v][j] = dist[v][j - 1] + dist[up[v][j - 1]][j - 1];
        }

        dfs(v);
    }
}

int lca(int u, int v) {
    if (height[u] < height[v]) swap(u, v);

    int k = height[u] - height[v];
    int result = 0;
    for (int i = 0; (1 << i) <= k; ++i) 
        if (k & (1 << i)) {
            result += dist[u][i];
            u = up[u][i];
        }

    if (u == v) return result;

    k = __lg(height[u]);

    for (int i = k; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            result += dist[u][i] + dist[v][i];
            u = up[u][i];
            v = up[v][i];
        }
    }
    return result + dist[u][0] + dist[v][0];
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({c, v});
        g[v].push_back({c, u});
    }

    dfs(1);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }

    return 0;
}