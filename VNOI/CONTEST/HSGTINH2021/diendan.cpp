#include <bits/stdc++.h>

#define NAME "diendan"
#define ii pair<int, int>
#define fi first 
#define se second

using namespace std;

const int N = 1e5 + 5;

int n, m, a[N];

bool ok(int dis) {
    int cnt = 0;
    for (int i = 1; i <= n;) {
        int j;
        for (j = i + 1; a[j] - a[i] < dis; ++j) {}
        i = j;
        cnt++;
    }
    return cnt >= m;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);

    int l = 1, r = a[n], res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ok(mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen(NAME".inp", "r", stdin);
    freopen(NAME".out", "w", stdout);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}