#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, a[N];

void solve() {
    int x, y;
    cin >> n >> x >> y;
    ll res = 0;
    map<pair<ll, ll>, int> mp;
    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        if (mp.count({(x - d%x)%x, d%y})) res += mp[{(x - d%x)%x, d%y}];
        mp[{d%x, d%y}]++;
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();
}