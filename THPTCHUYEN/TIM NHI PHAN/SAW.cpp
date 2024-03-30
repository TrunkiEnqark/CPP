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

int n, a[N];
ll m;

bool check(int h) {
    ll total = 0;
    for (int i = 1; i <= n; ++i) 
        if (a[i] >= h) total += a[i] - h;
    return total >= m;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int res = 0, l = 0, r = *max_element(a + 1, a + n + 1);
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
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