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

int n, k;
ll a[N], b[N];

ll totel_operations(ll target) {
    ll ops = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= target) {
            ops += (a[i] - target) / b[i] + 1;
        }
    }
    return ops;
}

ll calc(int x, int y) {
    ll u1 = x%y;
    ll sz = x/y + (x%y != 0);
    return sz * (2 * u1 + (sz - 1) * y) / 2 + u1;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    ll lo = 0, hi = 1e18, lim = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (totel_operations(mid) >= k) {
            lo = mid + 1;
            lim = mid;
        } else {
            hi = mid - 1;
        }
    }
    // cout << lim << endl;
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < lim) continue;
        ll ops = calc(a[i], b[i]) - calc(lim - 1, b[i]);
        res += ops;
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