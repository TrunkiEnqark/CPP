#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

const int MOD = 1e9 + 7;
const int N = 3e5 + 5;

int n, bit[N];
pair<int, int> a[N];

void updatePoint(int u, int v) {
    int idx = u;
    while (idx <= n) {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}

void updateRange(int l, int r, int v) {
    updatePoint(l, v);
    updatePoint(r + 1, -v);
}

int get(int u) {
    int idx = u, ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].first, a[i].second = i;
    memset(bit, 0, sizeof bit);
    for (int i = 1; i <= n; ++i) updatePoint(i, i);
    // for (int i = 1; i <= n; ++i) cout << get(i) - get(i - 1) << ' ';
    // cout << endl;
    sort(a + 1, a + n + 1, [] (const pair<int, int> &a, const pair<int, int> &b) { return a.first + a.second > b.first + b.second; });

    // for (int i = 1; i <= n; ++i) cout << a[i].first << endl;

    vector<int> s;
    for (int i = 1; i <= n; ++i) {
        s.push_back(a[i].first + get(a[i].second) - get(a[i].second - 1));
        if (a[i].second + 1 <= n) updateRange(a[i].second + 1, n, -1);
    }

    unique(s.begin(), s.end());
    // reverse(s.begin(), s.end());
    for (auto it : s) cout << it << ' ';
    // for (set<int>::iterator it = s.end(); it != s.begin(); it--) cout << *it << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();
}