#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    int a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] <= a[i - 1]) a[i] *= (a[i - 1] / a[i] + 1);
    }
    // for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
    cout << a[n] << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();
}