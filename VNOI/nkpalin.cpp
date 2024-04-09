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
const int N = 2e3 + 5;

int n, dp[N][N];
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> s;
    n = s.size();
    s = "#" + s;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j) dp[i][j] = 1;

    for (int i = n; i >= 0; --i) {
        for (int j = i + 1; j <= n; ++j) {
            dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            if (s[i] == s[j]) dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
        }
    }
    
    string res;
    int i = 1, j = n;
    while (i <= j) {
        if (s[i] == s[j]) {
            res += s[i];
            i++;
            j--;
        } else {
            if (dp[i + 1][j] > dp[i][j - 1]) i++;
                else j--;
        }
    }
    cout << res;
    for (int i = res.size() - dp[1][n]%2 - 1; i >= 0; --i) cout << res[i];

    return 0;
}