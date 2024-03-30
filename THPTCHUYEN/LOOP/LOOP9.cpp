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

ll Sum_of_Divisors(ll n) {
    ll result = 0;
    for (ll i = 2; i*i <= n; ++i) {
        if (n%i == 0)
            if (n/i == i) {
                result += i;
            } else {
                result += i;
                result += n/i;
            }
    }
    return result + 1;
}

void solve() {
    ll n;
    cin >> n;
    if (Sum_of_Divisors(n) == n) cout << "YES";
        else cout << "NO";
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