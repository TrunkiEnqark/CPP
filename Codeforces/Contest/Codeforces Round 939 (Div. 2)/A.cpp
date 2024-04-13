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

void solve() {
    int k, q;
    cin >> k >> q;
    int a[k + 1];
    for (int i = 1; i <= k; ++i) cin >> a[i];
    int min_arr = *min_element(a + 1, a + k + 1);
    for (int i = 1; i <= q; ++i) {
        int n;
        cin >> n;
        cout << min(n, min_arr - 1) << ' ';
    }
    cout << endl;
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}