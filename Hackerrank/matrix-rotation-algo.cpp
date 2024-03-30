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
const int N = 305;

int r, n, m, a[N][N];

int change(int k) {
    int cnt = 1, i = k + 1, j = k, tmp = a[k][k];
    int x = n - k + 1, y = m - k + 1;
    while (i != k || j != k) {
        // cout << i << ' ' << j << endl;
        swap(a[i][j], tmp);
        if (i < x && j == k) i++;
            else if (i == x && j < y) j++;
                else if (i > k && j == y) i--;
                    else if (i == k && j > k) j--;
        cnt++;
    }   
    swap(a[i][j], tmp);
    return cnt;
}

void solve() {
    cin >> n >> m >> r;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
    
    // change(2);
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= m; ++j) cout << a[i][j] << ' ';
    //     cout << endl;
    // }
    int tmp = min(n, m);
    for (int i = 1; i <= tmp/2 + tmp%2; ++i) {
        int cv = 2 * (n - i + 1) + 2 * (m - i + 1) - 4*i;
        // int real_cv = change(i);
        // cout << real_cv << ' ' << cv << endl;
        int R = r%cv;
        while(R--) change(i);
    }
    // cout << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cout << a[i][j] << ' ';
        cout << endl;
    }
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