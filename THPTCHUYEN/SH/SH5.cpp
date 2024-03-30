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

bool isPrime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i*i <= n; ++i) 
        if (n%i == 0) return false;
    return true;
}

void solve() {
    ll n;
    cin >> n;
    for (ll i = n + 1; ; i++) {
        if (isPrime(i)) {
            cout << i;
            return;
        }
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