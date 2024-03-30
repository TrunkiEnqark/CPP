#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 6;
const int MOD = 1e9 + 7;

int n, grid[N][N], dp[N][N];

void add(int &res, int val) {
    res += val;
    res %= MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) {
            char ch;
            cin >> ch;
            grid[i][j] = ch == '.';
        }

    dp[1][1] = grid[1][1];
    for(int i = 2; i <= n; ++i) {
        dp[i][1] = dp[i - 1][1] && grid[i][1];
        dp[1][i] = dp[1][i - 1] && grid[1][i];
    }
    
    for(int i = 2; i <= n; ++i)
        for(int j = 2; j <= n; ++j) 
            if(grid[i][j]) {
                add(dp[i][j], dp[i - 1][j]);
                add(dp[i][j], dp[i][j - 1]);
            }
    cout << dp[n][n];
}