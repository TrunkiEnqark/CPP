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
const int N = 2e5 + 5;

int sum[2][N][26];
string s, t;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int tests = 1;
    cin >> tests;
    while(tests--) {
        int n, q;
        cin >> n >> q;
        // memset(sum[0], 0, sizeof sum[0]);
        // memset(sum[1], 0, sizeof sum[1]);
        cin >> s >> t;
        s = "$" + s;
        t = "#" + t;
        
        for (int i = 1; i <= n; ++i) {
            for (int ch = 0; ch < 26; ++ch) {
                sum[0][i][ch] = sum[0][i - 1][ch];
                sum[1][i][ch] = sum[1][i - 1][ch];
            }

            sum[0][i][s[i] - 'a']++;
            sum[1][i][t[i] - 'a']++;
        }

        while (q--) {
            int l, r;
            cin >> l >> r;

            int res = 0;
            for (int ch = 0; ch < 26; ++ch) {
                res += abs((sum[0][r][ch] - sum[0][l - 1][ch]) - (sum[1][r][ch] - sum[1][l - 1][ch]));
            }
            cout << res / 2 << '\n';
        }
    }

    return 0;
}