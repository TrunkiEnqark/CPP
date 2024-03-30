#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, dp[N];

int backtrack(int remain) {
    if(dp[remain] != 0) return dp[remain];

    for(int i = 1; i <= 6; ++i) 
        if(remain - i >= 0) {
            dp[remain] += backtrack(remain - i);
            dp[remain] %= MOD;
        }

    return dp[remain];
}

int main() {
    cin >> n;
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    cout << backtrack(n);
}