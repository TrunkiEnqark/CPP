#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>
#define int128 __int128

using namespace std;

// const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
bool cmp(__int128 x, __int128 y) { return x > y; }

int128 x, n, MOD;

int128 POW(int128 a, int128 n, int128 MOD) {
    a %= MOD;
    int128 res = 1;
    while (n) {
        if (n&1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
} 

void solve() {
    x = read();
    n = read();
    MOD = read();
    if (x == 1) {
        print((n + 1) % MOD);
        return;
    }
    MOD *= (x - 1);
    int128 A = (POW(x, n + 1, MOD) - 1 + MOD) % MOD;
    int128 B = (x - 1 + MOD) % MOD;
    // print(A); cout << endl;
    // print(B); cout << endl;
    // cout << A << ' ' << B << endl;
    int128 Q = MOD * B;
    int128 result = (A % Q) / B;
    print(result);
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