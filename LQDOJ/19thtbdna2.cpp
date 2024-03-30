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

map<ll, ll> mp;

void calc(ll x) {
    for (ll i = 2; i <= x; ++i) {
        if (x%i == 0) {
            while (x%i == 0) {
                mp[i]++;
                x /= i;
            }
        }
    }
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    calc(a);
    calc(b);
    calc(c);
    ll res = mp.begin()->second;
    for (auto [p, cnt] : mp) {
        // cout << p << ' ' << cnt << endl;
        res = gcd(res, cnt);
    }
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