#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, m;
int a[N], seg[N << 2];

void build(int id, int l, int r) {
    if (l > r) return;
    
    if (l == r) {
        seg[id] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2 + 1, mid + 1, r);
    seg[id] = (seg[id*2] * seg[id*2 + 1]) % m;
}

int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u || l > r) return 1;

    if (u <= l && r <= v) return seg[id] % m;

    int mid = (l + r) / 2;
    return (get(id * 2, l, mid, u, v) * get(id * 2 + 1, mid + 1, r, u, v)) % m;
}

void solve() {
    cin >> n >> m;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    build(1, 1, n);
    string str;
    cin >> str;
    int l = 1, r = n;
    for (char type : str) {
        cout << get(1, 1, n, l, r) << ' ';
        if (type == 'L') l++;
            else r--;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();
}