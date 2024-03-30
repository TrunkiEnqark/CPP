#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e2 + 5;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m, a[N][N], b[N][N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) cin >> a[i][j];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) 
            if (a[i][j] == 0) {
                bool ok = true;
                for (int k = 0; k < 4; ++k) {
                    if (a[i + dx[k]][j + dy[k]] == 0) ok = false;
                }
                if (ok) {
                    int mi = 20;
                    for (int k = 0; k < 4; ++k) {
                        mi = min(mi, a[i + dx[k]][j + dy[k]]);
                    }
                    for (int k = 0; k < 4; ++k) {
                        a[i + dx[k]][j + dy[k]] -= mi;
                    }
                    b[i][j] = mi;
                }
            }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << max(0, b[i][j]) << ' ';
        }
        cout << endl;
    }
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}