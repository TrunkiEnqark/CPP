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

int n, m;
ll k;

ll check(ll mid) {
    ll res = 0;
    int j = m;
    for (int i = 1; i <= n; ++i) {
        while (j > 0 && 1ll*i*j > mid) j--;
        res += j;
    }
    return res;
}

ll find_kth(ll k) {
    ll l = 1, r = 1ll*n*m;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid) < k) l = mid + 1;
            else r = mid - 1;
    }
    return l;
}

void solve() {
    cin >> m >> n >> k;
    cout << find_kth(k);
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