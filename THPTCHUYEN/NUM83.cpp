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

vector<ll> res;

void init() {
    ll n3 = 3, n8 = 8;
    while(res.size() < 5000000) {
        if (n3 == n8) n8 += 8;
        if (n3 < n8) res.push_back(n3), n3 += 3;
            else res.push_back(n8), n8 += 8;
    }
}

void solve() {
    int n;
    cin >> n;
    // int cnt = 0, i;
    // for (i = 3; i <= N; ++i) {
    //     if (cnt == n) {
    //         i--;
    //         break;
    //     }
    //     if (i%3 == 0 || i%8 == 0) cnt++;
    // }
    // cout << i << endl;
    cout << res[n-1] << '\n';
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);
    init();
    // for (int i = 0; i < 100; ++i) cout << res[i] << ' ';
    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}