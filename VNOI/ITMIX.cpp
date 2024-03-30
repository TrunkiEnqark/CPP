#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;

const ll MOD = 1e9 + 7;
const int N = 1e5 + 5;

class SegmentTree {
private:
    ll seg[N*4], lazy1[N*4], lazy2[N*4], lazy3[N*4];

    void fix(ll &x) {
        x %= MOD;
    }
public:
    // SegmentTree() {}
    SegmentTree() {
        memset(seg, 0, sizeof seg);
        memset(lazy1, 0, sizeof lazy1);
        // memset(lazy2, 0, sizeof lazy2);
        memset(lazy3, 0, sizeof lazy3);
        fill(lazy2, lazy2 + N*4 + 1, 1);
    }

    void build(ll arr[], int id, int l, int r) {
        if (l > r) return;

        if (l == r) {
            seg[id] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        build(arr, id*2, l, mid);
        build(arr, id*2 + 1, mid + 1, r);
        seg[id] = (seg[id*2] + seg[id*2 + 1]) % MOD;
    } 

    void down1(int id, int l, int r) {
        int tmp = lazy1[id];
        if (tmp == 0) return;
        int mid = (l + r) / 2;
        // left -> [l, mid]
        seg[id*2] += 1ll * (mid - l + 1) * tmp;
        lazy1[id*2] += tmp;

        // right -> [mid + 1, r]
        seg[id*2 + 1] += 1ll * (r - mid) * tmp;
        lazy1[id*2 + 1] += tmp;

        fix(seg[id*2]);
        fix(seg[id*2 + 1]);
        // fix(lazy1[id*2]);
        // fix(lazy1[id*2 + 1]);

        lazy1[id] = 0;
    }

    void down2(int id, int l, int r) {
        int t = lazy2[id];   
        if (t == 0) return;
        // left -> [l, mid]
        lazy2[id*2] *= t;
        seg[id*2] *= t;

        // right -> [mid + 1, r]
        lazy2[id*2 + 1] *= t;
        seg[id*2 + 1] *= t;

        fix(seg[id*2]);
        fix(seg[id*2 + 1]);
        // fix(lazy2[id*2]);
        // fix(lazy2[id*2 + 1]);

        lazy2[id] = 1;
    }

    void down3(int id, int l, int r) {
        int t = lazy3[id];
        if (t == 0) return;

        int mid = (l + r) / 2;
        // left
        seg[id*2] = 1ll * (mid - l + 1) * t;
        lazy3[id*2] = t;
        // right
        seg[id*2 + 1] = 1ll * (r - mid) * t;
        lazy3[id*2 + 1] = t;

        fix(seg[id*2]);
        fix(seg[id*2 + 1]);
        // fix(lazy3[id*2]);
        // fix(lazy3[id*2 + 1]);

        lazy3[id] = 0;
    }

    void update1(int id, int l, int r, int u, int v, int val) {
        if (l > v || r < u || l > r) return;

        if (u <= l && r <= v) {
            seg[id] += 1ll * (r - l + 1) * val;
            lazy1[id] += val;
            fix(seg[id]);
            // fix(lazy1[id]);
            return;
        }

        down1(id, l, r);

        int mid = (l + r) / 2;
        update1(id*2, l, mid, u, v, val);
        update1(id*2 + 1, mid + 1, r, u, v, val);
        seg[id] = (seg[id*2] + seg[id*2 + 1]) % MOD;
    }

    void update2(int id, int l, int r, int u, int v, int val) {
        if (l > v || r < u || l > r) return;

        if (u <= l && r <= v) {
            seg[id] *= val;
            lazy2[id] *= val;
            fix(seg[id]);
            // fix(lazy2[id]);
            return;
        }

        down2(id, l, r);

        int mid = (l + r) / 2;
        update2(id*2, l, mid, u, v, val);
        update2(id*2 + 1, mid + 1, r, u, v, val);
        seg[id] = (seg[id*2] + seg[id*2 + 1]) % MOD;
    }

    void update3(int id, int l, int r, int u, int v, int val) {
        if (l > v || r < u || l > r) return;

        if (u <= l && r <= v) {
            seg[id] = 1ll * (r - l + 1) * val;
            lazy3[id] = val;
            fix(seg[id]);
            // fix(lazy3[id]);
            return;
        }

        down3(id, l, r);

        int mid = (l + r) / 2;
        update3(id*2, l, mid, u, v, val);
        update3(id*2 + 1, mid + 1, r, u, v, val);
        seg[id] = (seg[id*2] + seg[id*2 + 1]) % MOD;
    }

    int query(int id, int l, int r, int u, int v) {
        if (l > v || r < u || l > r) return 0;

        if (u <= l && r <= v) return seg[id] % MOD;
        
        down1(id, l, r);
        down2(id, l, r);
        down3(id, l, r);
    
        int mid = (l + r) / 2;
        return 1ll * (query(id*2, l, mid, u, v) + query(id*2 + 1, mid + 1, r, u, v)) % MOD;
    } 

    void print(int n) {
        for (int i = 1; i <= n; ++i) cout << query(1, 1, n, i, i) << ' ';
        cout << endl;
    }
};

int n, q;
ll a[N];
SegmentTree IT = SegmentTree();

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    IT.build(a, 1, 1, n);
    // cout << IT.query(1, 1, n, 1, n) << '\n';
    while (q--) {
        // IT.print(n);
        // cout << IT.query(1, 1, n, 1, 1) << ' ';
        // IT.query(1, 1, n, 1, 1);
        // cout << "Sum: " << IT.query(1, 1, n, 1, n) << '\n';
        int type;
        cin >> type;
        switch (type) {
            case 1: {
                int l, r, val;
                cin >> l >> r >> val;
                IT.update1(1, 1, n, l, r, val);
                break;
            }
            case 2: {
                int l, r, val;
                cin >> l >> r >> val;
                IT.update2(1, 1, n, l, r, val);
                break;
            }
            case 3: {
                int l, r, val;
                cin >> l >> r >> val;
                IT.update3(1, 1, n, l, r, val);
                break;
            }
            case 4: {
                int l, r;
                cin >> l >> r;
                cout << IT.query(1, 1, n, l, r) << '\n';
                break;
            }
        }

    }
    return 0;
}