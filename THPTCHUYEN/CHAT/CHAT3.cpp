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

int n;
ll a[N];

int find_x(ll x) {
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) l = mid + 1;
            else r = mid - 1;
    }
    return r;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a  + n + 1);

    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        auto it = upper_bound(a + 1, a + n + 1, x) - a;
        cout << a[it - 1] << '\n';
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