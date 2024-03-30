#include <bits/stdc++.h>

#define ii pair<int, int>

using namespace std;

const int N = 1e3 + 5;

int n, m, dist[N][N];
vector<ii> g[N];

int dijkstra(int s) {
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j) dist[i][j] = 1e9;
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        while(m--) {
            int u, v, c;
            cin >> u >> v >> c;
            g[u].push_back({c, v});
        }
    }
}