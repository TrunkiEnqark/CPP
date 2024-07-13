#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e3 + 5;

int n, a[N], b[N], dp[N][N], L[N], R[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    for (int i = 1; i <= n; ++i)
        L[i] = L[i - 1] + (a[i] == b[i]);
    for (int i = n; i > 0; --i)
        R[i] = R[i + 1] + (a[i] == b[i]);

    for (int i = 1; i <= n; ++i) {
        for (int j = n; j >= 1; --j) {
            dp[i][j] = max({dp[i - 1][j], dp[i][j + 1], dp[i - 1][j + 1]});
            if (a[i] == b[j]) 
                dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + 1);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            // printf("(%d, %d): %d\n", i, j, dp[i][j]);
            res = max({res, L[i - 1] + dp[i][j] + R[j + 1], L[i] + R[j + 1]});
        }
    }
    cout << res;

    return 0;
}