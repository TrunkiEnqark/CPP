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
const int N = 1e6 + 5;

map<ll, int> mp;

void solve() {
    ll n, m;
    cin >> n >> m;

    for (ll i = 2; i <= m; ++i) {
        if (m%i == 0) {
            while (m%i == 0) mp[i]++, m /= i;
        }
    }

    // cout << k << ' ' << x << endl;
    ll res = 1e18;
    for (auto [k, cnt] : mp) {
        ll num = 0;
        for (ll tmp = n; tmp/k >= 1; tmp /= k) num += tmp/k;
        if (num < cnt) {
            res = -1;
            break;
        }
        res = min(res, num/cnt);
    }
    // cout << k << endl;
    cout << res;
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}