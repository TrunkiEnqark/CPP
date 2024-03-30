#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
const int MAXM = 1e2;
const int MOD = 1e9 + 7;

int n, m, arr[MAXN + 5], dp[MAXN + 5][MAXM + 5];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> arr[i];

    if (arr[1] == 0) {
        for (int i = 1; i <= m; ++i) dp[1][i] = 1;
    } else dp[1][arr[1]] = 1;

    for (int i = 2; i <= n; ++i) {
        if (arr[i] != 0) {
            (dp[i][arr[i]] += dp[i - 1][arr[i]]) %= MOD;
            if (arr[i] > 1) (dp[i][arr[i]] += dp[i - 1][arr[i] - 1]) %= MOD;
            if (arr[i] < m) (dp[i][arr[i]] += dp[i - 1][arr[i] + 1]) %= MOD;
        }

        if (arr[i] == 0) {
            for (int j = 1; j <= m; ++j) {
                if (dp[i - 1][j] > 0) {
                    (dp[i][j] += dp[i - 1][j]) %= MOD;
                    if (j > 1) (dp[i][j - 1] += dp[i - 1][j]) %= MOD;
                    if (j < m) (dp[i][j + 1] += dp[i - 1][j]) %= MOD;
                }
            }
        }
    }

    int result = 0;
    for (int j = 1; j <= m; ++j) (result += dp[n][j]) %= MOD;

    // for (int i = 1; i <= n; ++i)
    //     for (int j = 1; j <= m; ++j) cout << dp[i][j] << " \n"[j == m];

    cout << result;
}