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

int n, m, a[N];

bool check(int t) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += a[i]/t;
        if (a[i]%t != 0) cnt++;
    }
    return cnt <= m;
}

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    int res = -1, l = 1, r = *max_element(a + 1, a + n + 1);
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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