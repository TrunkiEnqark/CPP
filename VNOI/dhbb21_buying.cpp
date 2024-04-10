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
const int N = 3e3 + 5;

int n, a[N][3];
ll dp[N][N][2];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        for (int k = 0; k < 3; ++k) cin >> a[i][k];
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[i + 1][j][1] = min(dp[i + 1][j][1], dp[i][j][k] + a[i + 1][k]);
            }
        }



    ll res = 1e18;
    for (int j = 0; j <= n; ++j) 
        for (int k = 0; k < 3; ++k) {
            cout << dp[n][j][k] << endl;
            res = min(res, dp[n][j][k]);
        }
    cout << res;
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