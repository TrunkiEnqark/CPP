#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;

const int LOG = 20;
const int N = 3e5 + 5;

int n, q, up[N][LOG], height[N];
vector<int> g[N];

void dfs(int u) {
    for (int v : g[u]) {
        if (v == up[u][0]) continue;
        height[v] = height[u] + 1;

        up[v][0] = u;
        for (int j = 1; j < LOG; ++j) 
            up[v][j] = up[up[v][j - 1]][j - 1];

        dfs(v);
    }
}

int lift(int u, int k) {
    for (int i = 0; (1 << i) <= k; ++i) 
        if (k & (1 << i)) {
            u = up[u][i];
        }
    return u;
}

int lca(int u, int v) {
    if (height[u] < height[v]) swap(u, v);
    u = lift(u, height[u] - height[v]);

    if (u == v) return u;

    int k = __lg(height[u]);

    for (int i = k; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        int goal = lca(a, b);

        int dist = height[a] + height[b] - 2 * height[goal];
        if (dist <= c) {
            cout << b << '\n';
        } else if (c <= height[a] - height[goal]) {
            cout << lift(a, c) << '\n';
        } else {
            cout << lift(b, dist - c) << '\n';
        }
    }

    return 0;
}