#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 2e5 + 5;
const int BLOCK_SIZE = 2;

int n, q;
ll a[N], sum[BLOCK_SIZE];

void init() {
    for (int i = 1; i <= n / BLOCK_SIZE + 5; ++i) {
        int tmp = 0;
        int l = (i - 1) * BLOCK_SIZE + 1;
        int r = i * BLOCK_SIZE;
        if (l > N || r > N) return;
        // cout << l << ' ' << r << endl;
        for (int j = l; j <= r; ++j) tmp += a[j];
        // cout << tmp << endl;
        sum[i - 1] = tmp;
    }
}

ll get_sum(int l, int r) {
    int blockL = (l + BLOCK_SIZE - 1) / BLOCK_SIZE;
    // cout << blockL << endl;
    int blockR = r / BLOCK_SIZE;
    if (blockL >= blockR) {
        ll res = 0;
        for (int i = l; i <= r; ++i) res += a[i];
        return res;
    }

    ll res = 0;
    for (int id = blockL; id < blockR; ++id) res += sum[id]; // cout << res << ' '; 
    for (int i = l; i <= blockL * BLOCK_SIZE; ++i) res += a[i]; // cout << res << ' ';
    for (int i = blockR * BLOCK_SIZE + 1; i <= r; ++i) res += a[i]; // cout << res << endl;
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    init();

    while(q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, x;
            cin >> k >> x;
            sum[k / BLOCK_SIZE] = sum[k / BLOCK_SIZE] - a[k] + x;
            a[k] = x;
        } else {
            int l, r;
            cin >> l >> r;
            cout << get_sum(l, r) << endl;
        }
    }
}