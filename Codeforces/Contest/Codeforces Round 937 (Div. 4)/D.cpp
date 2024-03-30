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

vector<int> p;

int convert(int v) {
    int len = __lg(v) + 1;
    int res = 0;
    for (int i = len - 1; i >= 0; --i) {
        res = res * 10 + ((v >> i) & 1);
    }
    return res;
}

void binary_initialize() {
    for (int msk = 2; msk < (1 << 5); ++msk) {
        p.push_back(convert(msk));
    }
}

bool is_binary(int n) {
    for (; n > 0; n /= 10) {
        if (n%10 != 0 && n%10 != 1) return false;
    }
    return true;
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; ++i)
        if (n%i == 0) return false;
    return true;
}

void solve() {
    int n;
    cin >> n;
    if (isPrime(n) && !is_binary(n)) {
        cout << "NO\n";
        return;
    }
    if (is_binary(n)) {
        cout << "YES\n";
        return;
    }

    for (int i = 0; i < p.size() && p[i] <= n; ++i) {
        if (n % p[i] == 0) {
            while (n%p[i] == 0) n /= p[i];
        }
    }

    if (is_binary(n)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);
    binary_initialize();
    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}