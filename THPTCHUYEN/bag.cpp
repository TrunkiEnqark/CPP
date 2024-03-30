#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n, w, a[N], b[N], dp[N][N];

int main() {
    cin >> n >> w;
    for(int i = 1; i <= n; ++i) cin >> b[i] >> a[i];
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= w; ++j) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if(j >= b[i]) 
                dp[i][j] = max(dp[i][j], dp[i][j - b[i]] + a[i]);
        }
    }
    cout << dp[n][w];
}