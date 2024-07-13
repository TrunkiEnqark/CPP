#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;
int64_t x, n, MOD;

int64_t POW(int64_t a, int64_t n, int64_t MOD) {
    a %= MOD;
    int64_t res = 1;
    while (n) {
        if (n&1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
} 

int64_t calculate(int64_t X, int64_t N) {
    if (N == 1) return X % MOD;

    if (N % 2 == 0) {
        int64_t halfResult = calculate(X, N / 2);
        int64_t powerTerm = powMod(X, N / 2, MOD);
        return (((powerTerm + 1) % MOD) * halfResult) % MOD;
    }

    return (X * (1 + calculate(X, N - 1))) % MOD;
}

void solve() {
    cin >> x >> n >> MOD;
    cout << (calculate(x, n) + 1) % MOD;
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