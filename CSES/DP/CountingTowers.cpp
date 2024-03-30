#include <bits/stdc++.h>

using namespace std;

const int LIM = 1e6;
const int MOD = 1e9 + 7;

long long dp[LIM + 2][2];

int main() {
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i <= LIM; ++i) {
        (dp[i][1] += 2*dp[i - 1][1]) %= MOD;
        (dp[i][0] += 4*dp[i - 1][0]) %= MOD;
        (dp[i][0] += dp[i - 1][1]) %= MOD;
        (dp[i][1] += dp[i - 1][0]) %= MOD;
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << (1ll * dp[n][0] + 1ll * dp[n][1]) % MOD << endl;
    }
}