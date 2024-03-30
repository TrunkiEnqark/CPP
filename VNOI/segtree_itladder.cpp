#include <bits/stdc++.h>

#define NAME ""

#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define all(a)		a.begin(), a.end()

#define int         long long
#define pb 			push_back
#define ld          long double
#define endl		'\n'
#define ll 			long long
#define ii 			pair<int, int>
#define fi 			first
#define se 			second

using namespace std;

ll gcd(ll a, ll b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

const string yno[] = {"NO\n", "YES\n"};
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;

int n, q;

void fix(ll &val) {
    if(val < 0) val += MOD*MOD;
    if(val >= MOD) val %= MOD;
}

struct SegmentTree1 {
    ll seg[N<<2], lazy[N<<2];

    void down(int id, int l, int r) {
        int t = lazy[id];
        if(t == 0) return;
        if(l != r) {
            int mid = (l + r) >> 1;
            seg[id*2] += (1ll * t * (mid - l + 1) * (mid + l) / 2) % MOD;
            fix(seg[id*2]);
            lazy[id*2] += t;
            fix(lazy[id*2]);

            seg[id*2 + 1] += (1ll * t * (r - (mid + 1) + 1) * (r + mid + 1) / 2) % MOD;
            fix(seg[id*2 + 1]);
            lazy[id*2 + 1] += t;   
            fix(lazy[id*2 + 1]);
        }

        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if(r < u || l > v || l > r) return;

        down(id, l, r);

        if(l >= u && r <= v) {
            seg[id] += (1ll * val * (r - l + 1) * (l + r) / 2) % MOD;
            fix(seg[id]);
            lazy[id] += val;
            fix(lazy[id]);

            down(id, l, r);

            return;
        }

        int mid = (l + r) >> 1;
        update(id*2, l, mid, u, v, val);
        update(id*2 + 1, mid + 1, r, u, v, val);
        seg[id] = (seg[id*2] + seg[id*2 + 1]) % MOD;
        fix(seg[id]);
    }

    ll get(int id, int l, int r, int u, int v) {
        if(r < u || l > v || l > r) return 0;

        down(id, l, r);

        if(l >= u && r <= v) return seg[id];

        int mid = (l + r) >> 1;
        ll ans = (get(id*2, l, mid, u, v) + get(id*2 + 1, mid + 1, r, u, v));
        fix(ans);
        return ans;
    }
} seg1;


struct SegmentTree2 {
    ll seg[N<<2], lazy[N<<2];

    void down(int id, int l, int r) {
        int t = lazy[id];
        if(t == 0) return;
        if(l != r) {
            int mid = (l + r) >> 1;
            seg[id*2] += (1ll * t * (mid - l + 1)) % MOD;
            fix(seg[id*2]);
            lazy[id*2] += t;
            fix(lazy[id*2]);

            seg[id*2 + 1] += (1ll * t * (r - (mid + 1) + 1)) % MOD;
            fix(seg[id*2 + 1]);
            lazy[id*2 + 1] += t;   
            fix(lazy[id*2 + 1]);
        }

        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if(r < u || l > v || l > r) return;

        down(id, l, r);

        if(l >= u && r <= v) {
            seg[id] += (1ll * val * (r - l + 1)) % MOD;
            fix(seg[id]);
            lazy[id] += val;
            fix(lazy[id]);

            down(id, l, r);

            return;
        }

        int mid = (l + r) >> 1;
        update(id*2, l, mid, u, v, val);
        update(id*2 + 1, mid + 1, r, u, v, val);
        seg[id] = (seg[id*2] + seg[id*2 + 1]);
        fix(seg[id]);
    }

    ll get(int id, int l, int r, int u, int v) {
        if(r < u || l > v || l > r) return 0;

        down(id, l, r);

        if(l >= u && r <= v) return seg[id];

        int mid = (l + r) >> 1;
        ll ans = (get(id*2, l, mid, u, v) + get(id*2 + 1, mid + 1, r, u, v)) % MOD;
        fix(ans);
        return ans;
    }
} seg2;

main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> q;

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int l, r, a, b;
            cin >> l >> r >> a >> b;
            seg1.update(1, 1, n, l, r, a);
            seg2.update(1, 1, n, l, r, b - l*a);
        } else {
            int l, r;
            cin >> l >> r;
            cout << (seg1.get(1, 1, n, l, r) + seg2.get(1, 1, n, l, r)) % MOD << endl;
        }
    }

    return 0;
}

//coded by eula_simp_lord (●'◡'●)
//https://oj.vnoi.info/problem/segtree_itladder
