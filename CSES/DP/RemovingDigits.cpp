#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
const int MOD = 1e9 + 7;

int n, dp[N];

int FindMaxDigits(int x) {
    int result = 0;
    for(; x > 0; x /= 10) result = max(result, x%10);
    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    // for(int i = 0; i <= 9; ++i) dp[i] = 1;
    // for(int i = 10; i <= n; ++i) {
    //     int x = FindMaxDigits(i);
    //     dp[i] = dp[i - x] + 1;
    // }
    // cout << dp[n];

    int steps = 0;
    while(n != 0) {
        int x = FindMaxDigits(n);
        steps++;
        n -= x;
    }
    cout << steps;
}