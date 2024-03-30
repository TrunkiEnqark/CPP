#include <bits/stdc++.h>

#define ii pair<int, int>
#define iii pair<long long, ii>

using namespace std;

const int N = 1e5 + 5;

int n, m, k;
long long dist[N];
vector<pair<long long, int>> adj[N];
int trace[N];

void dijkstra(int x) {
    fill(dist, dist + N, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, x});
    dist[x] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (dist[u] != du) continue;

        for (auto it : adj[u]) {
            int v = it.second;
            int uv = it.first;
            if (dist[v] > du + uv) {
                pq.push({dist[v] = du + uv, v});
                trace[v] = u;
            }
        }
    }
}

int d[N][19];
bool vst[N];

void dijkstra_optimize(int s) {
    queue<pair<int, int>> pq;
    pq.push({0, s});
    // dist[x] = 0;
    while (!pq.empty()) {
        int u = pq.front().second;
        int du = pq.front().first;
        pq.pop();
        // cout << u << ' ' << du << endl;
        // if (dist[u] != du) continue;

        for (auto it : adj[u]) {
            int v = it.second;
            int uv = it.first;
            for (int j = 1; j <= k; ++j) {
                if (d[v][j] > d[u][j - 1]) {
                    pq.push({d[v][j] = d[u][j - 1], v});
                }

                int w = min(d[u][j], d[u][j - 1]) + uv;
                if (d[v][j] > w) {
                    pq.push({d[v][j] = w, v});
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int _ = m; _--;) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }
    dijkstra(1);
    for (int i = 1; i <= n; ++i) {
        d[i][0] = dist[i];
        if (i == 1) continue;
        for (int j = 1; j <= 18; ++j) d[i][j] = 1e9;
    }
    // cout << d[4][0] << endl;
    dijkstra_optimize(1);
    // cout << "-------------------\n";
    for (int i = 1; i <= n; ++i) {
        int res = 1e9;
        // cout << d[i][0] << endl;
        for (int j = 0; j <= k; ++j) res = min(res, d[i][j]);
        cout << res << ' ';
        // cout << min(dist[i][0], dist[i][1]) << ' ';
        // cout << i << ' ' << dist[i] << endl;
        // cout << i << ' ' << dist[i][1] << endl;
    }

    return 0;
}