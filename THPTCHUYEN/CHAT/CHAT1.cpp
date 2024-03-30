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

ll n, u[N];

ll find_u(ll x) {
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (u[mid] >= x) r = mid - 1;
            else l = mid + 1;
    }
    return u[l];
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) u[i] = 1ll*i*i + 1;
    int t;
    cin >> t;
    while(t--) {
        ll x;
        cin >> x;
        auto res = lower_bound(u + 1, u + n + 1, x) - u;
        cout << u[res] << endl;
    }
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