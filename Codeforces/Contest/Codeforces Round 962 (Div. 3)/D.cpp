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
const int N = 1e5 + 5;

void solve() {
    int n, x;
    cin >> n >> x;

    ll res = 0;
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; a * b <= n && x - a - b > 0; ++b) {
            int c = min(x - a - b, (n - a * b) / (a + b));
            // cout << a << ' ' << b << ' ' << c << endl;
            res += c;
        }
    }
    cout << res << '\n';
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}