#include <bits/stdc++.h>

using namespace std;

const int lim = 92;

long long dp[lim + 1];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= lim; ++i) dp[i] = dp[i - 1] + dp[i - 2];

    // for (int i = 0; i <= lim; ++i) cout << dp[i] << ' ';
    
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        cout << upper_bound(dp, dp + lim + 1, n) - dp - 1 << endl;
    }
}