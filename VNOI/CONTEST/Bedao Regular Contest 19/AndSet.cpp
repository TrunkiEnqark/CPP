#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>
#define msk(x, k) ((x >> k) & 1)

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int n, a[N], cnt[32];

int get(int x) {
    int len = __lg(x);
    int res = 0;
    for (int i = len; i >= 0; --i) {
        if ((x >> i) & 1) 
            res = max(res, cnt[i]);
    }
    return res;
}

void update(int x) {
    int len = __lg(x);
    for (int i = len; i >= 0; --i) {
        if ((x >> i) & 1) {
            cnt[i]++;
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        // if (a[i] < 1 || a[i] > n) continue;
        res = max(res, get(a[i]) + 1);
        update(a[i]);
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