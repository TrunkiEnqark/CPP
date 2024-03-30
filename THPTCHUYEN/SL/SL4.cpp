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

int n, x[100], res = 0;

bool check() {
    for (int i = 1; i <= n; i += 2) {
        if ((x[i] + x[i + 1])%4 != 0) return false;
    }
    return true;
}

void attempt(int i) {
    for (int val = 0; val < 4; ++val) {
        x[i] = val;
        if (i == n) {
            res += check();
            if (check()) {for (int i = 1; i <= n; ++i) cout << x[i] << ' ';
            cout << endl;}
        } else {
            attempt(i + 1);
        }
    }
}

void solve() {
    cin >> n;
    attempt(1);
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