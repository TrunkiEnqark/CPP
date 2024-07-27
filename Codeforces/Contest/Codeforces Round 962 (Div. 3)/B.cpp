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
const int N = 1e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    int grid[n + 1][n + 1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char ch;
            cin >> ch;
            grid[i][j] = ch - '0';
        }
    }

    for (int i = 1; i <= n; i += k) {
        for (int j = 1; j <= n; j += k) {
            cout << grid[i][j];
        }
        cout << endl;
    }
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}