#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, a[N];

void solve() {
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
    if (sum % n != 0) {
        cout << "NO\n";
        return;
    }
    
    sum /= n;

    ll remains = 0;
    for (int i = 1; i <= n; ++i) {
        // cout << sum << ' ' << remains << endl;
        if (remains < 0) {
            cout << "NO\n";
            return;
        }
        if (a[i] < sum) {
            remains -= (sum - a[i]);
        }
        if (a[i] > sum) remains += a[i] - sum;
    }
    if (remains > 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();
}