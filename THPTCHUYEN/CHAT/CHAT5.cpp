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

int n, k, a[N];

bool check(ll mid) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += a[i] / mid;
    }
    return cnt >= k;
}

ll findAnswer() {
    ll l = 1, r = accumulate(a + 1, a + n + 1, r);
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) l = mid + 1;
            else r = mid - 1;
    }
    return r;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cout << findAnswer();
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