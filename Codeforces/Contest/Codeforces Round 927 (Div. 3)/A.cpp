#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    int a[n + 1], dp[n + 1];
    for (int i = 1; i <= n; ++i) {
        char ch;
        cin >> ch;
        if (ch == '.') a[i] = 0;
        if (ch == '@') a[i] = 1;
        if (ch == '*') a[i] = -1;
    }

    fill(dp, dp + n + 1, -1);
    int res = 0, now = 1;
    dp[1] = 0;
    for (int i = 1; i <= n; ++i) {
        bool flag = false;
        for (int k = 1; k <= 2; ++k) {
            if (i + k > n) break;
            if (a[i + k] != -1) flag = true, dp[i + k] = max(dp[i + k], dp[i] + a[i + k]); 
        }
        if (!flag) break;
    }
    cout << *max_element(dp, dp + n + 1) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();
}