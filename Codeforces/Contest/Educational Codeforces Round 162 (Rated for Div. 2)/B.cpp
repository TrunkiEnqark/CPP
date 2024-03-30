#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define int long long
#define ll long long
#define ld long double
#define ii pair<ll, ll>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 3e5 + 5;

int n, k, a[N], x[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i], x[i] = 0;
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        x[abs(p)] += a[i];
    }

    int total = 0, res = 1;
    for (int i = 1; i <= n; ++i) {
        total += x[i];
        if (total > i*k) {
            res = 0;
            break;
        }
    } 
    if (res) cout << "YES\n"; 
        else cout << "NO\n";
} 

main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen("txt.out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}