#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
const int MOD = 1e9 + 7;

int dp[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    dp[1] = dp[2] = 1;
    for(int i = 3; i <= 1000000; ++i) dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}