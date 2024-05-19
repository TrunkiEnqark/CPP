#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 2000;

int n, m, dp[N + 5][N + 5];

int main() {
    cin >> n >> m;
    memset(dp, 0, sizeof dp);
    for (int j = 1; j <= n; ++j) 
        dp[1][j] = 1;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = j; k <= n; k += j) {
                dp[i + 1][k] += dp[i][j];
                dp[i + 1][k] %= MOD;
            }
        }
    }

    int res = 0;
    for (int j = 1; j <= n; ++j) { 
        res += dp[m][j];
        res %= MOD;
    }
    cout << res;

    return 0;
}