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

int n, a[N], h[N];

struct SegmentTree {
    ll seg[N * 4];

    void build(int id, int l, int r) {
        if (l == r) {
            seg[id] = a[l];
            return;
        }

        int mid = (l + r) / 2;
        build(id*2, l, mid);
        build(id*2 + 1, mid + 1, r);
        seg[id] = max(seg[id*2], seg[id*2 + 1]);
    }

    void update(int id, int l, int r, int i, ll val) {
        if (l > i || r < i || l > r) return;

        if (l == r) {
            seg[id] = max(seg[id], seg[id] + val);
            return;
        }

        int mid = (l + r) / 2;
        update(id*2, l, mid, i, val);
        update(id*2 + 1, mid + 1, r, i, val);
        seg[id] = max(seg[id*2], seg[id*2 + 1]);
    }

    ll get_max(int id, int l, int r, int u, int v) {
        if (l > v || r < u || l > r) return -1e14;

        if (u <= l && r <= v) return seg[id];

        int mid = (l + r) / 2;
        return max(get_max(id*2, l, mid, u, v), get_max(id*2 + 1, mid + 1, r, u, v));
    }
} st;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    a[1] = max(0, a[1]);
    for (int i = 1; i <= k; ++i) st.update(1, 1, n, i, max(0ll, st.get_max(1, 1, n, 1, i - 1)) + a[i]);

    for (int i = k + 1; i <= n; ++i) {
        st.update(1, 1, n, i, st.get_max(1, 1, n, i - k, i - 1) + a[i]);
    }

    cout << st.get_max(1, 1, n, 1, n);

    return 0;
}