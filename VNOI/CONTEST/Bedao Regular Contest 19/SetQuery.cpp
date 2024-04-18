#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 2e5 + 5;
const int LG = 18;

int n, q, a[N], b[N];

class SpareTable {
private:
    set<int> st[LG + 1][N];
public:
    void build(int arr[], int n) {
        for (int i = 1; i <= n; ++i) st[0][i].insert(arr[i]);
    
        for (int j = 1; j <= LG; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
                st[j][i] = st[j - 1][i];
                st[j][i].insert(all(st[j - 1][i + (1 << (j - 1))]));
            }
        }
    }

    set<int> get(int l, int r) {
        int lg = __lg(r - l + 1);
        set<int> res = st[lg][l];
        res.insert(all(st[lg][r - (1 << lg) + 1]));
        return res;
    }
} st1, st2;  

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    st1.build(a, n);
    st2.build(b, n);

    while (q--) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        auto get1 = st1.get(l, r);
        auto get2 = st2.get(x, y);
        // cout << get1 << endl << get2 << endl;
        // for (auto it : get1) cout << it << ' '; cout << endl;
        // for (auto it : get2) cout << it << ' '; cout << endl;
        if (get1 == get2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}